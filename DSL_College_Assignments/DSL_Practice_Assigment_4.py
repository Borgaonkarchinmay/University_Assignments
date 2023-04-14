class Searching:
    def __init__(self):
        self.arr = []
        self.size = 0

    def getAttendance(self):
        self.size = int(input("Enter number of students who attended the training: ",))
        i = 0
        for i in range(self.size):
            ele = int(input("Enter Roll No: ",))
            self.arr.append(ele)
        if i + 1 == self.size:
            print("Attendance stored successfully")

    def LinearSearch(self, tarEle):
        for i in range(self.size):
            if self.arr[i] == tarEle:
                return i
        return -1

    def SentinelSearch(self, tarEle):
        i = 0
        self.arr.append(tarEle)
        while self.arr[i] != tarEle:
            i = i + 1

        if i == self.size:
            self.arr.pop()
            return -1
        else:
            self.arr.pop()
            return i

    def ShellSort(self):
        gap = self.size // 2
        while gap >= 1:
            for i in range(gap, self.size):
                temp = self.arr[i]
                j = i - gap
                while j >= 0 and temp < self.arr[j]:
                    self.arr[j + gap] = self.arr[j]
                    j = j - gap
                self.arr[j + gap] = temp
            gap = gap // 2


    def BinarySearch(self, tarEle):
        self.ShellSort()
        LB = 0
        UB = self.size - 1
        mid = (LB + UB) // 2
        while LB <= UB:
            if self.arr[mid] == tarEle:
                return mid
            elif tarEle > self.arr[mid]:
                LB = mid + 1
                mid = (LB + UB) // 2
            else:
                UB = mid - 1
                mid = (LB + UB) // 2

        return -1

    def FibonacciSearch(self, tarEle):
        self.ShellSort()

        fibo2 = 0
        fibo1 = 1
        fiboM = 1

        while fiboM < self.size:
            fibo2 = fibo1
            fibo1 = fiboM
            fiboM = fibo1 + fibo2

        offset = -1

        while fiboM > 1:
            index = min(offset + fibo2, self.size - 1)

            if tarEle < self.arr[index]:
                fiboM = fibo2
                fibo1 = fibo1 - fibo2
                fibo2 = fiboM - fibo1

            elif tarEle > self.arr[index]:
                fiboM = fibo1
                fibo1 = fibo2
                fibo2 = fiboM - fibo1
                offset = index

            else:
                return index

        if fibo1 == 1 and self.arr[self.size - 1] == tarEle:
            return offset +1

        return -1


    def Display(self):
        print("Below is the attendance list-")
        for i in range(self.size):
            print(self.arr[i], end=" ")
        print()


IOT = Searching()
IOT.getAttendance()
choice = 'y'
while choice == 'y' and choice != 'n':
    print()
    print("MENU")
    print("1-> Store Attendence\n2-> Display Attendence List\n3-> Linear Search\n4-> Sentinel Search\n5-> Binary Search\n6-> Fibonacci Search\n7-> Exit")
    print()
    menu = int(input("Enter Menu: ",))
    if menu == 1:
        IOT.getAttendance()

    elif menu == 2:
        IOT.Display()

    elif menu == 3:
        rollNo = int(input("Enter Roll no to be searched: ",))
        index = IOT.LinearSearch(rollNo)
        if index == -1:
            print("Student not present")
        else:
            print("Student present")

    elif menu == 4:
        rollNo = int(input("Enter Roll no to be searched: ", ))
        index = IOT.SentinelSearch(rollNo)
        if index == -1:
            print("Student not present")
        else:
            print("Student present")

    elif menu == 5:
        rollNo = int(input("Enter Roll no to be searched: ", ))
        index = IOT.BinarySearch(rollNo)
        if index == -1:
            print("Student not present")
        else:
            print("Student present")

    elif menu == 6:
        rollNo = int(input("Enter Roll no to be searched: ", ))
        index = IOT.FibonacciSearch(rollNo)
        if index == -1:
            print("Student not present")
        else:
            print("Student present")

    elif menu == 7:
        break

    else:
        print("Invalid menu, Try again!!")

    print()
    choice = input("Enter choice:(y/n)? ",)
    print("------------------------")