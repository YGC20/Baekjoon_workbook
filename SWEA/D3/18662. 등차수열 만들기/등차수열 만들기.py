T = int(input())
for test_case in range(1, T + 1):
    a,b,c=map(float,input().split())
    x=abs((a+c)/2-b)
    print(f"#{test_case} {x:.1f}")