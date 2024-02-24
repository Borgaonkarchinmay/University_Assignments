"""
This is example module. To help understand the working of the python modules
"""

def add(num1, num2):
    return num1 + num2

def sub(num1, num2):
    return num1 - num2

def mul(num1, num2):
    return num1 * num2

def div(num1, num2):
    res = 0
    try:
        res = num1 / num2
    except (ZeroDivisionError, Exception) as err:
        print(type(err).__name__)
    else:
        return res
    
def modulo(num1, num2):
    res = 0
    try:
        res = num1 % num2
    except (ZeroDivisionError, Exception) as err:
        print(type(err).__name__)
    else:
        return res
    