def solution(board):
    maxVal = 0
    for x in range(len(board)):
        for y in range(len(board[0])):
            if board[x][y] == 1:
                maxVal = 1
    
    for x in range(1, len(board)):
        for y in range(1, len(board[0])):
            if board[x][y] == 0:
                continue
            board[x][y] = min(board[x-1][y], board[x][y-1], board[x-1][y-1]) + 1
            if maxVal < board[x][y]:
                maxVal = board[x][y]
    return (maxVal * maxVal)