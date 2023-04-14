class Set:
    def length(self, List):
        index = 0
        while True:
            try:
                ele = List[index]
                index = index + 1
            except:
                break
        return index

    def isPresent(self, List, tarEle):
        for i in range(self.length(List)):
            if List[i] == tarEle:
                return True
        return False

    def genSet(self):
        result = []
        no = int(input("Enter number of students: ", ))
        for i in range(no):
            rollNo = int(input("Enter roll no of student: ", ))
            if self.isPresent(result, rollNo):
                print("Roll no already stored!!")
                rollNo = int(input("Re-enter roll no of student: ", ))
                result.append(rollNo)
            else:
                result.append(rollNo)
        return result

    def Union(self, List1, List2):
        len1 = self.length(List1)
        len2 = self.length(List2)
        result = []
        if len1 != 0 and len2 != 0:
            for i in range(len1):
                ele = List1[i]
                result.append(ele)

            for i in range(len2):
                if self.isPresent(result, List2[i]):
                    continue
                else:
                    result.append(List2[i])
            return result
        elif len1 == 0 and len2 == 0:
            return result
        else:
            if len1 == 0:
                return List2
            else:
                return List1

    def intersection(self, List1, List2):
        len1 = self.length(List1)
        len2 = self.length(List2)
        result = []
        if len1 != 0 and len2 != 0:
            for i in range(len1):
                ele = List1[i]
                if self.isPresent(List2, ele):
                    result.append(ele)
            return result
        else:
            return result

    def difference(self, List1,List2):
        len1 = self.length(List1)
        len2 = self.length(List2)
        result = []
        if len1 == 0 and len2 == 0:
            return result
        elif len1 == 0:
            return result
        else:
            for i in range(len1):
                ele = List1[i]
                if self.isPresent(List2, ele):
                    continue
                else:
                    result.append(ele)
            return result

SE1 = Set()
print("Enter details of students in class")
sample = SE1.genSet()
print("Enter cricket students")
cricket = SE1.genSet()
print("Enter badminton students")
badminton = SE1.genSet()
print("Enter football students")
football = SE1.genSet()

print()
print("Cricket: ", cricket)
print("Badminton: ", badminton)
print("Football: ", football)

print()
print("Students playing both cricket and badminton-")
inter = SE1.intersection(cricket, badminton)
print(inter)

print()
print("Students playing either cricket or badminton but not both-")
inter = SE1.intersection(cricket, badminton)
union = SE1.Union(cricket, badminton)
diff = SE1.difference(union, inter)
print(diff)

print()
print("Students playing neither cricket nor badminton-")
diff = SE1.difference(sample, union)
print(diff)

print()
print("Number of students playing cricket and football but not badminton-")
inter = SE1.intersection(cricket, football)
diff = SE1.difference(inter, badminton)
print(SE1.length(diff))
