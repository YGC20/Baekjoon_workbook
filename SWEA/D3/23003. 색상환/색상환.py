T = int(input())
for test_case in range(1, T + 1):
    a,b = input().split()
    colors = ["red","orange","yellow","green","blue","purple"]
    a_idx = colors.index(a)
    b_idx = colors.index(b)
    c_size = len(colors)
    if a_idx==b_idx :
        print('E')
    elif (a_idx+1)%c_size == b_idx or (a_idx-1)%c_size == b_idx :
        print('A')
    elif (a_idx+(c_size//2))%c_size == b_idx :
        print('C')
    else :
        print('X')