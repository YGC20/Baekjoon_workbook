T = int(input())
for test_case in range(1, T + 1):
    result = 0
    score = list(map(int, input().split()))
    for s in score :
        if s < 40 :
            result += 40
        else :
            result += s
    print(f"#{test_case} {result//5}")