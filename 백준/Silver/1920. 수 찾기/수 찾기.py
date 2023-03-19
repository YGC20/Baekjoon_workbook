N = int(input())
A = list(map(int,input().split()))
M = int(input())
arr = list(map(int,input().split()))
A.sort()

for num in arr:
    lN , hN = 0 , N - 1
    exist = False
    
    while lN <= hN :
        midN = (lN + hN) // 2
        if num == A[midN] :
            exist = True
            print(1)
            break
        elif num > A[midN] :
            lN = midN + 1
        else : 
            hN = midN - 1
    
    if not exist : print(0)