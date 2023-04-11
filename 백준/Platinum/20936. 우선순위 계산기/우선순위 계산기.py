import sys
import re
import heapq

def checkValue(index):
    if oper_info[index][2] == '+': return oper_info[index][0] + oper_info[index][1]
    elif oper_info[index][2] == '-': return oper_info[index][0] - oper_info[index][1]
    elif oper_info[index][2] == '*': return oper_info[index][0] * oper_info[index][1]
    else: return oper_info[index][0] // oper_info[index][1]

tex = sys.stdin.readline().rstrip()
num = list(map(int,re.split(r'\*|/|\+|-',tex)))
oper = list(re.sub(r'[0-9]','',tex))

answer = num[0]
PostQue = []
oper_info = dict()

for i in range(1,len(num)):
    oper_info[i-1] = ([num[i-1], num[i], oper[i-1], i-2, i])
    oper_prior = -1 if oper[i-1] == '*' or oper[i-1] == '/' else 0
    if oper[i-1] == '*':
        value = num[i-1] * num[i]
    elif oper[i-1] == '/':
        value = num[i-1] // num[i]
    elif oper[i-1] == '+':
        value = num[i-1] + num[i]
    elif oper[i-1] == '-':
        value = num[i-1] - num[i]
    heapq.heappush(PostQue,(-value, oper_prior, i-1))

while PostQue:
    get_value, prior, index = heapq.heappop(PostQue)
    check_value = checkValue(index)
    if -get_value == check_value:
        answer = check_value
        left_oper = oper_info[index][3]
        right_oper = oper_info[index][4]
        
        if left_oper > -1:
            oper_info[left_oper][1] = check_value
            oper_info[left_oper][4] = right_oper
            left_change_value = checkValue(left_oper)
            if oper_info[left_oper][2] == '*' or oper_info[left_oper][2] == '/': left_operator = -1
            else: left_operator = 0
            heapq.heappush(PostQue,(-left_change_value,left_operator,left_oper))
        
        if right_oper < len(oper_info):
            oper_info[right_oper][0] = check_value
            oper_info[right_oper][3] = left_oper
            right_change_value = checkValue(right_oper)
            if oper_info[right_oper][2] == '*' or oper_info[right_oper][2] == '/': right_operator = -1
            else: right_operator = 0
            heapq.heappush(PostQue,(-right_change_value,right_operator,right_oper))

print(answer)