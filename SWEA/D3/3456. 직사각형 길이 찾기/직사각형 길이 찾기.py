T = int(input())
for test_case in range(1, T + 1):
    a,b,c=map(int, input().split())
    print(f"#{test_case}",end=' ')
    if a==b :
        print(f"{c}")
    elif a==c :
        print(f"{b}")
    elif b==c :
        print(f"{a}")
    else :
        print(f"{a}")