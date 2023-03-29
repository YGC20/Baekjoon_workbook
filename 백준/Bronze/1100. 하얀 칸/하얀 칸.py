arr = list()
Chess = 0

for i in range(8):
    arr.append(input())

for x in range(8):
    if x%2 == 0:
        for y in range(8):
            if y%2 == 0:
                if arr[x][y] == 'F': Chess += 1
    elif x%2 == 1:
        for y in range(8):
            if y%2 == 1:
                if arr[x][y] == 'F': Chess += 1

print(Chess)