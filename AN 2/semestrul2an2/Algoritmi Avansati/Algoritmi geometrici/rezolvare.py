n = int(input())
semiplane = []
for _ in range(n):
    semiplane.append(tuple([float(x) for x in input().split()]))

raspunsuri = []
m = int(input().strip())
for _ in range(m):
    x, y = [float(x) for x in input().split()]
    semiplan_dreapta_x = -9999999  # x_min
    semiplan_stanga_x = 9999999    # x_max
    semiplan_jos_y = -9999999      # y_min
    semiplan_sus_y = 9999999       # y_max

    for semiplan in semiplane:
        val_st = -9999999
        val_dr = 9999999
        if semiplan[0] * x + semiplan[1] * y + semiplan[2] >= 0:
            continue
        if semiplan[0] == 0: # imi descrie un semiplan paralel cu oy
            val = -semiplan[2]/semiplan[1]
            if semiplan[1] < 0: # spre stanga
                val_st = val
            else: # spre dreapta
                val_dr = val
        else:
            val = -semiplan[2]/semiplan[0]
            if semiplan[0] < 0:
                val_st = val
            else:
                val_dr = val
        
        if semiplan[0] == 0:
            semiplan_jos_y = max(semiplan_jos_y, val_st)
            semiplan_sus_y = min(semiplan_sus_y, val_dr)
        else:
            semiplan_dreapta_x = max(semiplan_dreapta_x, val_st)
            semiplan_stanga_x = min(semiplan_stanga_x, val_dr)
        
    if(semiplan_dreapta_x > semiplan_stanga_x or semiplan_jos_y > semiplan_sus_y or semiplan_dreapta_x == -9999999 or semiplan_stanga_x == 9999999 or
            semiplan_jos_y == -9999999 or semiplan_sus_y == 9999999 or semiplan_dreapta_x == semiplan_stanga_x or semiplan_sus_y == semiplan_jos_y):
        raspunsuri.append("NO")
    else:
        raspunsuri.append("YES")
        arie = (semiplan_stanga_x - semiplan_dreapta_x) * (semiplan_jos_y - semiplan_sus_y)
        raspunsuri.append(f"{abs(arie):.6f}")

for raspuns in raspunsuri:
    print(raspuns)

