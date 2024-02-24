# OOP

# Special functions => def __funtion_name__()
#  Example => __init__(), __repr__()

# Access specifiers
# member function or variables => naming convention => access specification
# (var or fun)_name Public
# _(var or fun)_name Protected
# __(var or fun)_name Private

#  By default is Public

class Person:
    # Class variable
    basic_needs = ["Food", "Clothing", "Shelter"]

    def __init__(self, name, age, gender, profession):
        # Instance variables
        self.name = name
        self.age = age
        self.profession = profession
        self.gender = gender
        self.__salary = 0
        self._signature_statement = ""
        self._relatives = []
        
    def set_salary(self, sal):
        self.__salary = sal

    def get_salary(self):
        return self.__salary
    
    def introduce_yourself(self):
        print(f"My name is {self.name}. I am {self.age} years old. My profession is {self.profession}.")
    
    def populate_relatives(self, relative):
        self._relatives.append(relative)

    def tell_your_relatives(self):
        relatives = self._relatives 
        return relatives
    
    def set_signature_statement(self, statement):
        self._signature_statement = statement

    # Protected method

    def _get_signature_statement(self):
        return self._signature_statement
    
    def say_your_signature_statment(self):
        print(f"Here comes my signature statement => {self._get_signature_statement()}")

    # Destructor
    def __del__(self):
        pass

person = Person("George", 54, "Male", "Businessmen")
person.populate_relatives("John")

person.set_salary(20)


person.introduce_yourself()
print(person.basic_needs)
print(f"My relatvies are: {person.tell_your_relatives()}")

