# Primitive data types introduction

entity = "Earth"
greet = "Hello from " + entity

print(greet)

rollno = 21
married = False
weight = 72.3
name = """John"""

print(type(entity))
print(type(name))
print(type(rollno))
print(type(married))
print(type(weight))
print(isinstance(married, float))

# Mutable Objects	Immutable Objects
# Lists	            Numbers
# Dictionaries	    Strings
# Sets              Tuples

# Type conversion/casting

print(int("104") + 26)
print(float("104.25") + 26)
# print(int("104.25") + 26) => error, beacause of invalid literal for int with base 10
print(str(124) + "6")
print(str(124.64) + "6")
print(bool(124.64))
print(bool(0))
print(bool(-25))
print(float(True))

# implicit type conversion
#  No type coercion in python
a = 10
b = 12.4
s = "10"

c = s + str(a)
print(c)

c = a + b
print(c)
print(type(c))

c = a + int(b)
print(c)
print(type(c))

c = a/int(b)
print(c)
print(type(c))

# Assignment type

x, y, z, s = 10, 12.5, 13, "abc"
print(x)
print(y)
print(z)
print(s)

x, y = y, x

print(x)
print(y)
