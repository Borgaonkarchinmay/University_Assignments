# List comprehesion

numbers  = [12, 1, 15, 16]
numbers = [number*3 for number in numbers] # [expression iterable]
print(numbers)

numbers = [number for number in numbers if number%2 == 0] # [expression iterable if condition]
print(numbers)

# Expression => Any python expression that returns a value = item of new list