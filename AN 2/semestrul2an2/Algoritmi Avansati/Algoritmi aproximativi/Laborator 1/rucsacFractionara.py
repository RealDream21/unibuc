n, c = [int(x) for x in input().split()]

valori = [int(x) for x in input().split()]
greutati = [int(x) for x in input().split()]

profit_cantitate = [(valori[i]/greutati[i], greutati[i], valori[i]) for i in range(n)]

profit_cantitate.sort(key = lambda t: -t[0])

ghiozdan_curent = 0
best_item_index = 0
profit_total = 0

while ghiozdan_curent < c and best_item_index < n:
    currentItem = profit_cantitate[best_item_index]
    currentItemGreutate = profit_cantitate[best_item_index][1]
    if currentItemGreutate < (c - ghiozdan_curent):
        ghiozdan_curent += currentItemGreutate
        profit_total += profit_cantitate[best_item_index][2]
        best_item_index += 1
    else:
        aux = ghiozdan_curent
        ghiozdan_curent = c
        profit_total += profit_cantitate[best_item_index][0] * (c - aux)

print(profit_total)
