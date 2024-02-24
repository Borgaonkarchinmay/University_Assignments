# Functional programming
# using Map function

rate_of_interests = [19.6, 7.8, 3.4, 17.45, 13.3]
investment_amount = 1500

def calculate_roi(rate_of_interest):
    return (rate_of_interest*0.01 + 1)*investment_amount

compare_list = map(calculate_roi, rate_of_interests)

for roi in compare_list:
    print(roi)


letters = ["a", "b", "c"]
ascii_map = map(ord, letters)
for ascii_code in ascii_map:
    print(ascii_code)

sqr_numbers = map(lambda i : i*i, [1, 2, 3, 4])
for num in sqr_numbers:
    print(num)


# Using Filter function
even_numbers = filter(lambda x : x%2 == 0, [1, 12, 16, 15])
for num in even_numbers:
    print(num)

from functools import reduce

# Using Reduce function
result = reduce(lambda x, y: x + y, [1, 1, 1])
print(result)