# Developer environment => Debugging

num = 12  

assert num > 0, "0 and non-negative are not allowed"
print(num)

#  Raising exception

num1 = 12
num2 = 0

if(num2 == 0):
    raise ZeroDivisionError("Divide by zero is not allowed.")
else:
    print(num1/num2)

# Assert or rasie ensures that script terminates gracefully.