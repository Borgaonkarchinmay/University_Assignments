class Matrix:
    def __init__(self):
        self.mat = []
        self.rows = 0
        self.cols = 0

    def getMatrix(self):
        mat = []
        self.rows = int(input("Enter number of rows: ", ))
        self.cols = int(input("Enter number of columns: ", ))
        for i in range(self.rows):
            row = []
            for j in range(self.cols):
                ele = int(input("Enter item: ", ))
                row.append(ele)
            mat.append(row)
        self.mat = mat

    def display(self):
        for i in range(self.rows):
            for j in range(self.cols):
                print(self.mat[i][j], end="  ")
            print()

    def addition(self, mat1, mat2):
        result = []
        if mat1.rows == mat2.rows and mat1.cols == mat2.cols:
            for i in range(mat1.rows):
                row = []
                for j in range(mat1.cols):
                    ele = mat1.mat[i][j] + mat2.mat[i][j]
                    row.append(ele)
                result.append(row)
            self.mat = result
            self.rows = mat1.rows
            self.cols = mat1.cols
        else:
            print("Matrix addition not possible!!")

    def subtraction(self, mat1, mat2):
        result = []
        if mat1.rows == mat2.rows and mat1.cols == mat2.cols:
            for i in range(mat1.rows):
                row = []
                for j in range(mat1.cols):
                    ele = mat1.mat[i][j] - mat2.mat[i][j]
                    row.append(ele)
                result.append(row)
            self.mat = result
            self.rows = mat1.rows
            self.cols = mat1.cols
        else:
            print("Matrix subtraction not possible!!")

    def multiply(self, mat1, mat2):
        result = []
        if mat1.cols == mat2.rows:
            for i in range(mat1.rows):
                row = []
                for j in range(mat2.cols):
                    ele = 0
                    for k in range(mat1.cols):
                        ele = ele + mat1.mat[i][k] * mat2.mat[k][j]
                    row.append(ele)
                result.append(row)
            self.mat = result
            self.rows = mat1.rows
            self.cols = mat2.cols
        else:
            print("Matrix multiplication not possible!!")

    def transpose(self):
        result = []
        for j in range(self.cols):
            row = []
            for i in range(self.rows):
                row.append(self.mat[i][j])
            result.append(row)
        self.mat = result
        temp = self.rows
        self.rows = self.cols
        self.cols = temp


print("Matrix A")
matA = Matrix()
matA.getMatrix()
matA.display()
print()
print("Matrix B")
matB = Matrix()
matB.getMatrix()
matB.display()
print()
matC = Matrix()
matC.addition(matA, matB)
print("Matrix addition is-")
matC.display()
print()
matC.subtraction(matA, matB)
print("Matrix subtraction is-")
matC.display()
print()
matC.multiply(matA, matB)
print("Matrix multiplication is-")
matC.display()
print()
matA.transpose()
print("Matrix A transpose is-")
matA.display()
print()
matB.transpose()
print("Matrix B transpose is-")
matB.display()