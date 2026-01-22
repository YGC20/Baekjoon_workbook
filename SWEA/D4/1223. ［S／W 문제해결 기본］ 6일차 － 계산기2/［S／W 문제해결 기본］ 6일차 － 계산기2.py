def to_postfix(expression: str) -> str :
    op = {"+": 1,"*": 2}
    res = []
    stk = []
    for exp in expression :
        if exp.isnumeric() :
            res.append(exp)
        elif exp in op :
            while stk and (op[exp] <= op[stk[-1]]) :
                res.append(stk.pop())
            stk.append(exp)
    while stk :
        res.append(stk.pop())
    return "".join(res)

for test_case in range(1, 11):
    N = int(input())
    expression = input()
    str_postfix = to_postfix(expression)
    calc_stk = []
    for sp in str_postfix :
        if sp.isnumeric() :
            calc_stk.append(int(sp))
        elif sp=='+' :
            b = calc_stk.pop()
            a = calc_stk.pop()
            calc_stk.append(a+b)
        elif sp=='*' :
            b = calc_stk.pop()
            a = calc_stk.pop()
            calc_stk.append(a*b)
    print(f"#{test_case} {calc_stk[0]}")