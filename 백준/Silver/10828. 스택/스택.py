def push(stack,x):
    stack.append(x)
    return stack

def pop(stack):
    if size(stack) == 0 : return print(-1)
    else :
        laststack = stack[size(stack)-1]
        stack.pop()
        return print(laststack)

def size(stack):
    number = len(stack)
    return number

def empty(stack):
    if size(stack) == 0 : return print("1")
    else : return print("0")

def top(stack):
    if size(stack) == 0 : return print(-1)
    else :
        laststack = stack[size(stack)-1]
        return print(laststack)


stack = list()
command = list()

N = int(input())
for i in range(N):
    command.append(input())

for i in range(N):
    if command[i] == "pop" : pop(stack)
    elif command[i] == "size" : print(size(stack))
    elif command[i] == "empty" : empty(stack)
    elif command[i] == "top" : top(stack)
    else :
        pushcut = command[i].split()
        push(stack,pushcut[1])


    
