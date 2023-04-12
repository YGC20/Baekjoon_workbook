import sys
sys.setrecursionlimit(10**6)

def Star(index):
    if index == 1: return ['*']
    Starlen = Star(index//3)
    SL = list()
    for _ in Starlen: SL.append(_*3)
    for _ in Starlen: SL.append(_+' '*(index//3)+_)
    for _ in Starlen: SL.append(_*3)
    return SL

n = int(sys.stdin.readline().strip())
print('\n'.join(Star(n)))