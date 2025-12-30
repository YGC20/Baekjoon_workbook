T = int(input())
for test_case in range(1, T + 1):
    L,U,X=map(int,input().split())
    if X>U :
        print(f"#{test_case} -1")
    elif X>=L and X<=U :
        print(f"#{test_case} 0")
    elif X<L :
        print(f"#{test_case} {L-X}")