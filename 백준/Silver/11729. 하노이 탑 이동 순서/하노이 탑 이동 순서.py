import sys
sys.setrecursionlimit(10**6)

def Hanoi_count(n,a,b,c,count):
    if n==1: 
        count+=1
        return count
    count = Hanoi_count(n-1,a,b,c,count)
    count = Hanoi_count(n-1,b,a,c,count)
    count+=1
    return count

def Hanoi(n,a,b,c):
    if n==1:
        print(a,c)
        return
    Hanoi(n-1,a,c,b)
    print(a,c)
    Hanoi(n-1,b,a,c)
    return

count = 0
N = int(sys.stdin.readline().strip())
print(Hanoi_count(N,1,2,3,count))
Hanoi(N,1,2,3)
