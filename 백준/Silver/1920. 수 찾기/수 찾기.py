N = int(input()) # 자연수 N을 받고 정수로 변환
A = list(map(int,input().split())) # 문자열을 받고 공백을 기준으로 나눠서(split) A 리스트에 정수로 하나씩 넣음(map)
M = int(input()) # 자연수 M을 받고 정수로 변환
arr = list(map(int,input().split())) # 문자열을 받고 공백을 기준으로 나눠서(split) arr 리스트에 정수로 하나씩 넣음(map)
A.sort() # 리스트 A의 내용을 순서대로 정리

for num in arr:
    lN , hN = 0 , N - 1 # 이분탐색을 위해 arr의 시작값(lN)과 최후값(hN) 설정
    exist = False 
    
    while lN <= hN : # lN이 hN보다 커지면 while반복문 탈출
        midN = (lN + hN) // 2 # 중간값 설정
        if num == A[midN] : # arr값과 A의 중간값을 비교 후 같은 경우
            exist = True
            print(1)
            break
        elif num > A[midN] : # arr값과 A의 중간값을 비교 후 arr값이 큰 경우 시작값(lN)에 중간값보다 한칸더 간값을 넣음
            lN = midN + 1
        else : 
            hN = midN - 1
    
    if not exist : print(0)

'''
이분 탐색
결정문제의 답이 이분적일 때 사용할수 있는 탐색 기법
'''
