#  Memory Management

num = 12
names = ["afwa", "abc"]
print(id(num)) # Unique id of the object tha means => memory address
print(id(names))

abc = num
dnames = names

print(id(abc))
print(id(dnames))

# del decreases the no of references to a object in the memory by 1
# It releases the reference name from the namespace => check with dir() method

del abc
del num
del names
del dnames

def fun(num):
    num = num + 1
    print(id(num))

a = 12
print(id(a))
fun(a)
print(a)

