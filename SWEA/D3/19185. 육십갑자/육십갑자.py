T = int(input())
for test_case in range(1, T + 1):
    n,m=map(int, input().split())
    s_list=input().split()
    t_list=input().split()
    q=int(input())
    ans = []
    for _ in range(q):
        y=int(input())
        s_idx=(y-1)%n
        t_idx=(y-1)%m
        result=s_list[s_idx]+t_list[t_idx]
        ans.append(result)
    print(f"#{test_case}", *ans)