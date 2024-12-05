# Дана квадратная матрица n x n. Поменяйте местами элементы, стоящие на главной 
# и побочной диагонали, при этом каждый элемент должен остаться в том же столбце 
# (то есть в каждом столбце нужно поменять местами элемент на главной диагонали и 
# на побочной диагонали).

# Входные данные:
# n - количество строк и столбцов
# и сама матрица вводится с клавиатуры.

def swap(matrix, i, j):
    temp = matrix[i][j]
    matrix[i][j] = matrix[i][n - j - 1]
    matrix[i][n - j - 1] = temp
    return matrix

n = int(input("Введите размер матрицы (n): "))
matrix = []
for i in range(n):
    matrix.append(list(map(int, input("Введите элементы строки: ").split())))


for i in range(n):
    swap(matrix, i, i)


print("Матрица после перестановки элементов:")
for i in range(n):
    print(*matrix[i])