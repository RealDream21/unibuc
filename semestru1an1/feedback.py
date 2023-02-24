import random
import socket

server = socket.socket()
PORT = 55012
maxConn = 1
IP = socket.gethostbyname("localhost")

server.bind((IP, PORT))
server.listen(maxConn)

client, address = server.accept()

file = open("wordlist.txt","r")
file_content = file.read()
content_list = file_content.split('\n')
to_guess = random.choice(content_list)

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
    return feedback

user_input = None
print("Apasati 1 pentru a primi urmatorul cuvant de la calculator\n"
      "Apasati 2 pentru a lasa calculatorul sa joace pana la final\n"
      "Altfel, dati un cuvant din lista de cuvinte pentru a fi ghicit\n"
      "\n"
      "Instructiuni pentru feedback:\n"
      "valoarea 1 inseamna litera buna, dar pozitia gresita\n"
      "valoarea 2 inseamna litera buna pe pozitia buna\n"
      "valoarea 0 inseamna ca litera nu a fost gasita in cuvant\n")
while user_input != to_guess and user_input != "quit\n":
    user_input = input("Give Input: ")
    user_input = user_input.strip()
    user_input = user_input.upper()
    while user_input not in content_list and user_input != '1' and user_input != '2':
        user_input = input("Input gresit, da alt input: ")
        user_input = user_input.upper()
        user_input = user_input.strip()

    if user_input == '1':
        client.send('1'.encode())
        next_guess = client.recv(5).decode()
        feedback = give_feedback(to_guess, next_guess)
        client.send(feedback.encode())
        user_input = next_guess
        print(next_guess)
        print(feedback)
    elif user_input == '2':
        while user_input != to_guess:
            client.send('1'.encode())
            next_guess = client.recv(5).decode()
            feedback = give_feedback(to_guess, next_guess)
            client.send(feedback.encode())
            user_input = next_guess
            print(next_guess)
            print(feedback)
    else:
        feedback = give_feedback(to_guess, user_input)
        client.send(user_input.encode())
        client.send(feedback.encode())
        print(feedback)
client.send('quit'.encode())
input('Apasa ENTER pentru a iesi')