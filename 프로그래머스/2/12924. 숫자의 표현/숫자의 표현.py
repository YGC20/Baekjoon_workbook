def solution(n):
    cnt = sn = 0
    s = e = 1
    while s <= n :
        if sn < n :
            sn += e
            e += 1
        else:
            if sn == n :
                cnt += 1
            sn -= s
            s += 1
    return cnt