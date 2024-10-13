def det(a, b, c, d):
    aux = a[0]**2 + a[1]**2
    return -1 * ((b[0] - a[0])*(c[1]-a[1])*(d[0]**2 + d[1]**2 - aux) + \
            (b[1] - a[1])*(c[0]**2 + c[1]**2 - aux)*(d[0] - a[0]) + \
            (c[0] - a[0])*(d[1] - a[1])*(b[0]**2 + b[1]**2 - aux) - \
            (b[0]**2 + b[1]**2 - aux)*(c[1] - a[1])*(d[0] - a[0]) - \
            (c[0]**2 + c[1]**2 - aux)*(d[1] - a[1])*(b[0] - a[0]) - \
            (b[1] - a[1])*(c[0] - a[0])*(d[0]**2 + d[1]**2 - aux))

a = tuple([int(x) for x in input().split()])
b = tuple([int(x) for x in input().split()])
c = tuple([int(x) for x in input().split()])

m = int(input())

puncte_test = []

for _ in range(m):
    puncte_test.append(tuple([int(x) for x in input().split()]))

for d in puncte_test:
    val = det(a,b,c,d)
    if val < 0:
        print("OUTSIDE")
    elif val > 0:
        print("INSIDE")
    else:
        print("BOUNDARY")