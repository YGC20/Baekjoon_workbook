def solution(clothes):
    dic = {}
    for gear in clothes :
        dic[gear[1]] = dic.get(gear[1], 0) + 1
    answer = 1
    for cnt in dic.values() :
        answer *= (cnt + 1)
    return answer-1