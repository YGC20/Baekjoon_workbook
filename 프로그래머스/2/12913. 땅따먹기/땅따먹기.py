def solution(land):
    for k in range(1,len(land)):
        for i in range(0,4):
            maxVal = 0
            for j in range(0,4):
                if i == j :
                    continue
                maxVal = max(maxVal, land[k-1][j])
            land[k][i] += maxVal
    result = 0
    for _ in land[len(land)-1]:
        if(result<_):
            result = _
    return result