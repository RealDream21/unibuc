l = int(input().strip())
x0 = input().strip()
x1 = input().strip()
i = int(input())

aux = x0
sir1 = x0[:i] + x1[i:]
sir2 = x1[:i] + aux[i:]

print(sir1)
print(sir2)