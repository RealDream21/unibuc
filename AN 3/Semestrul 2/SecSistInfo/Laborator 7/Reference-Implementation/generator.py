message = 'salut'
with open("input.txt", mode="w+") as f:
    f.writelines([f'{message}{x}\n' for x in range(10000)])
