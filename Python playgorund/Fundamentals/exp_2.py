# String operations
Str = "My name is xyz"
print(Str)
print(Str[0:6])
print(id(Str[-1:-7:-1]))
print(id(Str))

# join()
#  Any iterable object which has all items string
iterable = ["My", "name", "is", "xyz"] 
print(" ".join(iterable))


iterable2 = ("123", "241", "154")
print(",".join(iterable2))

iterable3 = {"k1" : "abc", "k2":"xyz"}
print(",".join(iterable3))

# split()

iterable4 = "My name is xyz".split()
print(iterable4)


# String Formating

Str = "George"
birth_year = 2002
weight = 71.53
print(f"Greetings to {Str} from Earth")
print(f"{Str}'s age is: {2024-birth_year}")
print(f"{Str}'s weight is: {weight:{2}.{2}}")