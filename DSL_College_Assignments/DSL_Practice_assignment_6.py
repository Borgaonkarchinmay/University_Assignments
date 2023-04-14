class Marks:
    def __init__(self):
        self.arr = []
        self.size = 0

    def getMarkList(self):
        self.size = int(input("Enter number of students in class: ",))
        for i in range(self.size):
            marks = float(input("Enter marks of student " + str(i + 1) + ": ",))
            self.arr.append(marks)
        if i + 1 == self.size:
            print("Marks stored successfully.")

    def swap(self, ind1, ind2):
        temp = self.arr[ind1]
        self.arr[ind1] = self.arr[ind2]
        self.arr[ind2] = temp

    def partition(self, lb, ub):
        start = lb
        end = ub
        pivot = self.arr[lb]
        while start < end:
            while self.arr[start] <= pivot and start != ub:
                start = start + 1
            while self.arr[end] > pivot and end != lb:
                end = end - 1
            if start < end:
                self.swap(start, end)
        self.swap(lb, end)
        return end

    def quicksort(self, lb, ub):
        if lb < ub:
            pivotIndex = self.partition(lb, ub)
            self.quicksort(lb, pivotIndex - 1)
            self.quicksort(pivotIndex + 1, ub)
        return

    def displayMarks(self):
        print(self.arr)
        self.quicksort(0, self.size - 1)
        print(self.arr)

    def topscore(self):
        for i in range(self.size - 1, self.size - 6, -1):
            print(self.arr[i], "%")

SE1 = Marks()
SE1.getMarkList()
SE1.displayMarks()
print("Top five scores are-")
SE1.topscore()
