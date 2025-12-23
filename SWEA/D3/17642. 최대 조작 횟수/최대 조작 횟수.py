T = int(input())
for test_case in range(1, T + 1):
    A,B=map(int,input().split())
    diff=B-A
    if diff<0 or diff==1 :
        print(f"#{test_case} -1")
        continue
    cnt=diff//2
    print(f"#{test_case} {cnt}")