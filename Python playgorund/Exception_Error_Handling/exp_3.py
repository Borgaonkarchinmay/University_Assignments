# Exception handling fine tunning

import os

try:
    inr = input("Enter your currency in INR: ", )
    print(f"{inr} INR = ${float(inr)/82.95}")

except ValueError as err:
    print(type(err).__name__)
    print(err)
    # print(os.strerror(err.errno)) Specific only to OS error

 
except Exception as err:
    # Must have to catch other than any exact exceptions catched above
    print(type(err).__name__)

else:
    print("No exception in try block")

finally:
    # Cleaning chores
    print("Executes irrespective of the occurence of exception  in try block")

print("Still in the script, now script ends")