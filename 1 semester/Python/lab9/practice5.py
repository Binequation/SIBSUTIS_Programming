# Получены значения температуры воздуха за 4 дня с трех метеостанций, расположенных в разных
# регионах страны:
# Т.е. запись показаний в двумерном массиве выглядела бы так:
# t[0][0]=-8 t[0][1]=-14 t[0][2]=-19 t[0][3]=-18
# t[1][0]=25 t[1][1]=28 t[1][2]=26 t[1][3]=20
# t[2][0]=11 t[2][1]=18 t[2][2]=20 t[2][3]=25
# 2. Распечатать показания термометров всех метеостанций за 2-й день.
# 3. Определить среднюю температуру на 3-й метеостанции.


temperatures = [
    [-8, -14, -19, -18],
    [25, 28, 26, 20],
    [11, 18, 20, 25]
]

print("Температура за 4-й день:", temperatures[2][3])
print("Показания термометров всех метеостанций за 2-й день:")
for i in range(len(temperatures)):
    for j in range(len(temperatures[i])):
        if j == 2:
            print(f"№{i + 1}: {temperatures[i][j]}")
print("Средняя температура на 3-й метеостанции:", sum(temperatures[1]) / len(temperatures[1]))