# Basics of list

# Mutable
B1 = [12, 13, 14, 15]
K1 = [1, 2, 3, 4, 5]

for student in B1:
    print(student)

print(B1)
print(B1 + K1)
print(B1*2)

B1.sort()

print(B1[1:4:2])

B1.append(16)
print(B1.index(14))
B1.insert(2, 18)
B1.remove(4)