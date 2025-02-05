# Считается, что один год, прожитый собакой, эквивалентен семи человеческим годам. 
# При этом зачастую не учитывается, что собаки становятся абсолютно взрослыми уже
# к двум годам. Таким образом, многие предпочитают каждый из первых двух лет жизни
# собаки приравнивать к 10,5 года человеческой жизни, а все последующие – к четырем.
# Напишите программу, которая  будет переводить возраст собаки в человеческий с
# учетом указанной выше логики. Убедитесь, что программа корректно работает при
# пересчете возраста собаки  меньше и больше двух лет. Также программа должна 
# выводить сообщение об ошибке если пользователь ввел отрицательное число.

dog_age, human_age = int(input("Введите собачьи года: ")), 0
if dog_age == 1 or dog_age == 2:
    print("Введенный вами год эквивалентен 10.5 человеческим")
elif dog_age > 2:
    for i in range(dog_age - 2):
        human_age += 4
    print(f"Введенный вами год эквивалентен {int((10.5 * 2) + human_age)} человеческим")
else: 
    print("Ошибка!")