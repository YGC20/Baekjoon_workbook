import sys

Stack_1 = list(sys.stdin.readline().rstrip())
Stack_2 = list()

for num in range(int(sys.stdin.readline())):
    commend = list(sys.stdin.readline().split())
    if commend[0] == "L":
        if Stack_1: Stack_2.append(Stack_1.pop())     
    elif commend[0] == "D":
        if Stack_2: Stack_1.append(Stack_2.pop())
    elif commend[0] == "B":
        if Stack_1: Stack_1.pop()
    elif commend[0] == "P": 
        Stack_1.append(commend[1])

Stack_1.extend(reversed(Stack_2))
print(''.join(Stack_1))