T = int(input())
for test_case in range(1, T + 1) :
    N=int(input())
    arr=list(map(int, input().split()))
    avg=sum(arr)/N
    cnt=0
    for _ in arr :
        if _<=avg :
            cnt+=1
    print(f"#{test_case} {cnt}")