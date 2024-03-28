l, k = [int(x) for x in input().strip().split()]
c = input().strip()
poz = [int(x) for x in input().strip().split()]

string = [ch for ch in c]

for i in poz:
    if string[i] == '1':
        string[i] = '0'
    else:
        string[i] = '1'

print("".join(string))