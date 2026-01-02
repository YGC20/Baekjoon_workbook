T = int(input())
for test_case in range(1, T + 1):
    N=int(input())
    result=sum(i if i%2!=0 else -i for i in range(1,N+1))
    print(f"#{test_case} {result}")