def eval(exp):
    if exp[1] == '*':
        return str(int(exp[0])*int(exp[2]))
    elif exp[1] == '/':
        return str(int(exp[0])/int(exp[2]))
    elif exp[1] == '+':
        return str(int(exp[0])+int(exp[2]))
    elif exp[1] == '-':
        return str(int(exp[0])-int(exp[2]))


def precedence(op):
    if op in '+-':
        return 1
    elif op in '*/':
        return 2
    else:
        return 0


def infix_to_postfix(infixexpr):
    st = []
    for i in infixexpr:
        if i is '(':
            st.append(i)
        elif i is ')':
            while st[-1] is not '(':
                print(st.pop()),
            st.pop()
        elif i in '+-*/':
            while st and precedence(i) <= precedence(st[-1]):
                print(st.pop()),
            st.append(i)
        else:
            print(i)
    while st:
        print(st.pop())


def postfix_to_infix(postfixexpr):
    st = []
    for i in postfixexpr:
        if i in '+-*/':
            op1 = st.pop()
            op2 = st.pop()
            st.append('('+op2+i+op1+')')
        else:
            st.append(i)
    return st.pop()


def evaluate_postfix(postfixexpr):
    st = []
    for i in postfixexpr:
        if i in '+-*/':
            op1 = st.pop()
            op2 = st.pop()
            st.append(eval(op2+i+op1))
        else:
            st.append(i)
    return st.pop()
