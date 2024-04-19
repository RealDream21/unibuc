def f(x, a, b, c):
    return a * (x**2) + b * x + c


a, b, c = [int(x) for x in input().strip().split()]
n = int(input().strip())
vals = [float(x) for x in input().strip().split()]

F = [f(x, a, b, c) for x in vals]
total = sum(F)
p = []
sum = 0

p.append(0)

for crom in F:
    sum += crom
    p.append(float(sum/total))

for fit in p:
    print(fit)