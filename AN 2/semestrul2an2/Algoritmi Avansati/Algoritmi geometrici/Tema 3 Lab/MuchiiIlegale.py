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
d = tuple([int(x) for x in input().split()])


print(f'AC: {"ILLEGAL"if det(a,b,c,d) > 0 else "LEGAL"}')
print(f'BD: {"ILLEGAL"if det(b,c,d,a) > 0 else "LEGAL"}')