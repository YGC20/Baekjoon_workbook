def checkVPS(VPS) :
    VPSstack = []
    for char in VPS :
        if (char == '(') : VPSstack.append(char)
        elif (char == ')') :
            if VPSstack : VPSstack.pop()
            else : return print("NO")
    else : 
        if not VPSstack : return print("YES")
        else : print("NO")

VPS = list()
T = int(input())

for i in range(T) :
    N = input()
    if 2 >= len(N) >= 50 : break
    else : VPS.append(N)

for i in range(T) :
    checkVPS(VPS[i])
