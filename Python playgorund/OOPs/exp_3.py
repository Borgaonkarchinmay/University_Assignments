
class ComplexNumber:
    def __init__(self, real, imag):
        self.real = real
        self.imag = imag

    # DUNDER method, modifies the object behaviour
    def __add__(self, other):
        # Check if the other operand is a ComplexNumber object
        if not isinstance(other, ComplexNumber):
            raise TypeError("Addition is only defined for ComplexNumber objects")

        # Add real and imaginary components separately
        return ComplexNumber(self.real + other.real, self.imag + other.imag)

    def __str__(self):
        # Return a string representation of the complex number
        return f"{self.real} + {self.imag}j"

# Create two complex numbers
num1 = ComplexNumber(2, 3)
num2 = ComplexNumber(4, -1)

# Add the complex numbers using the __add__ method
result = num1 + num2

# Print the result
print(result)  # Output: (6 + 2j)
