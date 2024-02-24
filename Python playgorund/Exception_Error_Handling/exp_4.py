# Custom exception

class InvalidInput(Exception):
    """Unexpected literal got as an input"""

age = input("Enter age: ")
if (age.isalnum()):
    raise InvalidInput("Age must be numeric")