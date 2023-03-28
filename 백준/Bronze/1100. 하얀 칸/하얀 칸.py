def Chess(i,j,arr,count):
    if (0 <= i < 8):
        if i%2 == 0:
            if(0 <= j < 8):
                if(j == 0 or j == 2 or j == 4 or j == 6):
                    if (arr[i][j] == 'F'): count += 1
                    Chess(i,j+1,arr,count)
                else: Chess(i,j+1,arr,count)
            else:
                j = 0
                Chess(i+1,j,arr,count)
        elif i%2 == 1:
            if(0 <= j < 8):
                if(j == 1 or j == 3 or j == 5 or j == 7):
                    if (arr[i][j] == 'F'): count += 1
                    Chess(i,j+1,arr,count)
                else: Chess(i,j+1,arr,count)
            else:
                j = 0
                Chess(i+1,j,arr,count)             
    else :
        print(count)

arr = list()

for i in range(8) :
    arr.append(input())

i = 0
j = 0
count = 0
Chess(i,j,arr,count)