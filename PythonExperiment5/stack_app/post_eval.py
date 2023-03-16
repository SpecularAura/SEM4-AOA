#stack_app/post_eval.py
from pythonds.basic.stack import Stack
def perform_operation(operandL, operandR, operation):
    if operation == "+":
        return operandL + operandR
    elif operation == "-":
        return operandL - operandR
    elif operation == "*":
        return operandL * operandR
    elif operation == "/":
        return operandL / operandR

def post_eval(postexpr):
    postexpr = str(postexpr)
    tokenList = postexpr.split()
    operandStack = Stack()

    for token in tokenList:
        if token.isnumeric():
            operandStack.push(int(token))
        else:
            operandR = operandStack.pop()
            operandL = operandStack.pop()
            operandStack.push(perform_operation(operandL, operandR, token))

    return operandStack.pop()


    