#in_pre.py
from pythonds.basic.stack import Stack

def in_pre(infixexpr):
    prec = {}
    prec["/"] = 3
    prec["*"] = 3
    prec["+"] = 2
    prec["-"] = 2
    prec[")"] = 1
    opstack = Stack()
    prefixList = []
    infixexpr = str(infixexpr)
    tokenList = infixexpr.split()

    tokenList.reverse()
    for token in tokenList:
        if (token.isalnum()):
            prefixList.append(token)
        elif token == ')':
            opstack.push(token)
        elif token == '(':
            operand = opstack.pop()
            while (operand != ')'):
                prefixList.append(operand)
                operand = opstack.pop()
        else:
            while (not opstack.isEmpty() and prec[opstack.peek()] >= prec[token]):
                prefixList.append(opstack.pop())
            opstack.push(token)
    
    while not opstack.isEmpty():
        prefixList.append(opstack.pop())
    
    prefixList.reverse()
    return " ".join(prefixList)
