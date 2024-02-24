# Functions

def add(a, b):
    """
    Function descriptor
    """
    return a + b

def sub(a, b):
    return  a - b

def greet(principal, *members):
    print(f"Greetings to the repsected {principal} and Hello to all " + ",".join(members))
    

#  Argument types
 
# Positional
print(add(1, 5) + 10)

# Keyword
print(sub(b = 12, a = 14))

# Variable length positional arguments
greet('George', 'abc', 'xyz')


# Pass by Value v/s Pass by reference
# Depending on the type of object you pass in the function, the function behaves differently.
# Immutable objects show “pass by value” whereas mutable objects show “pass by reference”.

x = 2 # immutable x

def modify_x(a):
    a = a*2
    print("In function " + str(a))

modify_x(x)
print("Out of function " + str(x))

fruits = ['mango', 'orange', 'watermelon', 'grapes'] # Mutable

def modify_list(x):
    x[-1] = 'tomato'
    print(f"In function: {x} ")

modify_list(fruits)
print(f"Outside funtion: {fruits}")

# Lamda funtion
#  Any number of arguments, but only single expressions

# function_name = lambda (arguments) : single line  expression

x = lambda a : a*100

print(x(12))

# No function overloading   


