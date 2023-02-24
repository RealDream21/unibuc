import math
import socket

server = socket.socket()
PORT = 55012
HOST = socket.gethostbyname("localhost")

server.connect((HOST, PORT))

#entropia
def entropy(template_freq, word_list):
	template_ratio = template_freq / len(word_list)
	return (template_ratio * -math.log2(template_ratio))

#returneaza cuvantul cu cea mai mare entropie
def max_entropy_word(word_list):
	if len(word_list) == 1:
		return word_list[0]

	max_entropy = 0.0
	maxEtrpy_word = ""

	for word in word_list: # pt cuvantul asta eu primesc feedback
		freq_templates = [0 for i in range(243)]
		templates = []

		entropy_calc = 0.0

		for word_to_guess in word_list: #asta e guess
			word_try = word
			feedback = ["0" for i in range(5)]
			for i in range(5):
				if word_try[i] == word_to_guess[i]:
					feedback[i] = "2"

			for i in range(5):
				if feedback[i] == "0":
					if word_to_guess.find(word_try[i]) > -1:
						feedback[i] = "1"

			feedback = "".join(feedback)

			try:
				freq_templates[templates.index(feedback)] += 1
			except:
				templates.append(feedback)
				freq_templates[len(templates)-1] = 1

		for i in range(len(templates)):
			entropy_calc += entropy(freq_templates[i], word_list)

		if entropy_calc > max_entropy:
			max_entropy = entropy_calc
			maxEtrpy_word = word

	return maxEtrpy_word


#sterg cuvintele care nu imi convin din lista
def delete_from_list(word_tryout, template, word_list):
    remaining_words = []
    for word in word_list:
        to_add = True
        for index in range(5):
            if template[index] == '2' and word[index] != word_tryout[index]:
                to_add = False
            elif template[index] == '1' and word[index] == word_tryout[index]:
                to_add = False
            elif template[index] == '1' and word_tryout[index] not in word:
                to_add = False
            elif template[index] == '0' and word_tryout[index] in word:
                to_add = False
        if to_add == True:
            remaining_words.append(word)
    return remaining_words

def give_feedback(guess, input):
    feedback = ""
    for i in range (0, 5):
        if input[i] == guess[i]:
            feedback += "2"
        else:
            if input[i] in guess:
                feedback += "1"
            else:
                feedback += "0"

# MAIN Function
def main():
	pas = 0
	with open("wordlist.txt","r") as words_file:
		word_list = (words_file.read()).split("\n")
		next_guess = ""
		while True:
			user_input = server.recv(5).decode()
			if user_input == 'quit':
				break
			if user_input == '1':
				if pas == 0:
					server.send('TAREI'.encode())
					feedback = server.recv(5).decode()
					word_list = delete_from_list("TAREI", feedback, word_list)
				else:
					server.send(next_guess.encode())
					feedback = server.recv(5).decode()
					word_list = delete_from_list(next_guess, feedback, word_list)
			else:
				feedback = server.recv(5).decode()
				word_list = delete_from_list(user_input, feedback, word_list)
			next_guess = max_entropy_word(word_list)
			pas += 1

# Start Program
main()