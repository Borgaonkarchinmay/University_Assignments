# Exception handling

import os

try:
    num1 = 12
    num2 = 6

    if(num2 == 0):
        raise ZeroDivisionError("Divide by zero is not allowed.")
    else:
        print(num1/num2)

    with open('file.cpp') as file:
        data = file.read()

except ZeroDivisionError as err:
    print(type(err).__name__)
    # print(os.strerror(err.errno)) Specific only to OS error

except FileNotFoundError as err:
    print(type(err).__name__)
    print(os.strerror(err.errno))
 
except Exception as err:
    # Must have to catch other than any exact exceptions catched above
    print(type(err).__name__)
