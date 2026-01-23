T = int(input())
for test_case in range(1, T + 1):
    num = str(input())
    last_num = int(num[-1])
    print(f"#{test_case}", end = ' ')
    if last_num%2==0 :
        print("Even")
    else :
        print("Odd")