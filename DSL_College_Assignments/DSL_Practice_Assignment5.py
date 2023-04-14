class Percentage:
    def __init__(self):
        self.MarkList = []
        self.size = 0

    def StoreMarks(self):
        self.size = int(input("Enter number of students: ",))
        for i in range(self.size):
            marks = float(input("Enter percentage of student " + str(i+1) + ": ",))
            self.MarkList.append(marks)
        if i + 1 == self.size:
            print("Marks are stored successfully!!")

    def InsertionSort(self):
        for i in range(1, self.size):
            temp = self.MarkList[i]
            j = i - 1
            while j >= 0 and temp < self.MarkList[j]:
                self.MarkList[j + 1] = self.MarkList[j]
                j = j - 1
            self.MarkList[j + 1] = temp
        print("Marklist sorted successfully!!")

    def ShellSort(self):
        gap = self.size//2
        while gap >= 1:
            for i in range(gap, self.size):
                temp = self.MarkList[i]
                j = i - gap
                while j >= 0 and temp < self.MarkList[j]:
                    self.MarkList[j + gap] = self.MarkList[j]
                    j = j - gap
                self.MarkList[j + gap] = temp
            gap = gap//2
        print("Marklist sorted successfully!!")


    def DisplayMarks(self):
        print()
        print("Marks of students are-")
        for i in range(self.size):
            print(self.MarkList[i], end="%, ")

    def DisplayTopScores(self):
        print()
        print("Top five scores are-")

        if self.size >= 5:
            for i in range(self.size-1, self.size-6, -1):
                print(self.MarkList[i], "%")
        else:
            for i in range(self.size-1, -1, -1):
                print(self.MarkList[i], "%")

SE1 = Percentage()
choice = 'y'
while choice == 'y' and choice != 'n':
    print("MENU")
    print("1. Store Marks\n2. Shell sort\n3. Insertion sort\n4. Display marks\n5. Display Top five scores")
    menu = int(input("Enter menu: "))

    if menu == 1:
        SE1.StoreMarks()
    elif menu == 2:
        SE1.ShellSort()
    elif menu == 3:
        SE1.InsertionSort()
    elif menu == 4:
        SE1.DisplayMarks()
    elif menu == 5:
        SE1.DisplayTopScores()
    else:
        print("OOPs!!, Invalid Menu, try again.")

    print()
    choice = input("Enter choice(y/n)?: ")
    print("--------------------")
    print()




