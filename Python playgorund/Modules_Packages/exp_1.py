import sys
import calculator as calc

# Paths where python will search for imported module
print(sys.path)

print(calc.add(6, 3))


# The built-in function dir() returns a list of defined names/references in the namespace.
print(dir())