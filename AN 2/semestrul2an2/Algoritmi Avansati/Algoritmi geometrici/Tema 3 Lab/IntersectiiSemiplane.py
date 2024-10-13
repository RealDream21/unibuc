n = int(input())
semiplane = []
for _ in range(n):
    semiplane.append([int(x) for x in input().strip().split()])

semiplan_stanga_x = None #cel mai mare x
semiplan_dreapta_x = None # cel mai mic x
semiplan_sus_y = None # cel mai mic y
semiplan_jos_y = None # cel mai mare y 

for semiplan in semiplane: 
    if semiplan[1] == 0: #nu avem y => semiplan descris de x
        val = (-1 * semiplan[2]) / semiplan[0]
        if semiplan[0] > 0: # imi descrie semiplanul din stanga
            if semiplan_stanga_x is None or val > semiplan_stanga_x:
                semiplan_stanga_x = val
        else:
            if semiplan_dreapta_x is None or val < semiplan_dreapta_x:
                semiplan_dreapta_x = val
    elif semiplan[0] == 0: #nu avem x -=> semiplan descris de y
        val = (-1 * semiplan[2]) / semiplan[1]
        if semiplan[1] > 0: #imi descrie semiplanul de jos
            if semiplan_jos_y is None or val > semiplan_jos_y:
                semiplan_jos_y = val
        else:
            if semiplan_sus_y is None or val < semiplan_sus_y:
                semiplan_sus_y = val

printed = False

print(semiplan_stanga_x, semiplan_dreapta_x, semiplan_jos_y, semiplan_sus_y)

if (semiplan_stanga_x != None and semiplan_dreapta_x != None and semiplan_sus_y != None and semiplan_jos_y != None):
    #verificam bounded
    if(semiplan_stanga_x >= semiplan_dreapta_x and semiplan_jos_y >= semiplan_sus_y):
        print("BOUNDED")
        printed = True
if not printed:
    #verificam void (sunt toate si nu sunt bine puse sau lipsesc pe ox sau pe oy)
    if (semiplan_stanga_x == None and semiplan_dreapta_x == None) or (semiplan_sus_y == None and semiplan_jos_y == None):
        if semiplan_dreapta_x != None and semiplan_stanga_x != None:
            if semiplan_dreapta_x >= semiplan_stanga_x:
                print("VOID")
                printed = True
        if semiplan_jos_y != None and semiplan_sus_y != None:
            if semiplan_sus_y >= semiplan_jos_y:
                print("VOID")
                printed = True
    elif(semiplan_stanga_x != None and semiplan_dreapta_x != None and semiplan_sus_y != None and semiplan_jos_y != None):
        if not(semiplan_stanga_x >= semiplan_dreapta_x and semiplan_jos_y >= semiplan_sus_y):
            print("VOID")
            printed = True
    else:
        if semiplan_dreapta_x != None and semiplan_stanga_x != None:
            if semiplan_dreapta_x >= semiplan_stanga_x:
                print("VOID")
                printed = True
        if semiplan_jos_y != None and semiplan_sus_y != None:
            if semiplan_sus_y >= semiplan_jos_y:
                print("VOID")
                printed = True
if not printed:
    print("UNBOUNDED")


