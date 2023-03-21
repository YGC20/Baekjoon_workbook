N = int(input())
Ncard = list(map(int,input().split()))
M = int(input())
Mcard = list(map(int,input().split()))
Ncard.sort()

for i in Mcard:
    sN , eN = 0, N - 1
    exist = False
    while sN <= eN:
        midN = (sN + eN)//2
        if i == Ncard[midN] :
            exist = True
            print(1,end=" ")
            break
        elif i < Ncard[midN] :
            eN = midN - 1
        else :
            sN = midN + 1
    if not exist : print(0,end=" ")