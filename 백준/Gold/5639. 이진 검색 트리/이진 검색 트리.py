import sys
sys.setrecursionlimit(10**9)

pre_tree=[]
while True:
    try: pre_tree.append(int(sys.stdin.readline()))
    except: break

def post_tree(start,end):
    if start > end: return
    mid = end+1
    for i in range(start+1,end+1):
        if pre_tree[start] < pre_tree[i]:
            mid = i
            break
    post_tree(start+1,mid-1)
    post_tree(mid,end)
    print(pre_tree[start])

post_tree(0,len(pre_tree)-1)