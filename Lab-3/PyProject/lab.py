import random


class SqrMatrix:

    def __init__(self, size):
        self.size = size
        self.matrix = []
        for i in range(size):
            row = []
            for j in range(size):
                row.append(random.randint(1, 99))
            self.matrix.append(row)


def list_objects():
    num = int(input("Number of objects to create: "))
    lst = []
    size = int(input("Enter the size of matrix: "))
    for i in range(num):
        sqr_matrix = SqrMatrix(size)
        lst.append(sqr_matrix)
    return lst


def show_objects(lst):
    n = 1
    print("\n===============================")
    for matrix in lst:
        print("Matrix", n)
        for i in range(matrix.size):
            for j in range(matrix.size):
                print("%3d" % (matrix.matrix[i][j]), end=' ')
            print()
        print("===============================")
        n += 1


def calc_sum(lst):
    max_s = 0
    max_m = []
    max_n = 1
    size = 0
    n = 1
    for matrix in lst:
        print("\nMatrix", n)
        size = matrix.size
        cur_s = 0
        for i in range(size):
            for j in range(size):
                if i == j or i + j == size - 1:
                    cur_s += matrix.matrix[i][j]
        print("Sum of diagonal elements:", cur_s)
        if cur_s > max_s:
            max_s = cur_s
            max_m = matrix.matrix
            max_n = n
        n += 1
    print("\nMatrix", max_n, "has the largest sum of diagonal elements:", max_s)
    for i in range(size):
        for j in range(size):
            print("%3d" % (max_m[i][j]), end=' ')
        print()
