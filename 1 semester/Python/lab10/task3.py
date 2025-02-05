# Истории литературы известен случай написания романа объемом около 50 тыс. слов, 
# в котором ни разу не была употреблена самая популярная в английском алфавите 
# буква E. Название его – «Gadsby».
# Напишите программу, которая будет считывать список слов из файла и собирать статистику
# о том, в каком проценте слов используется ’e’. В качестве исходного файла можете использовать
# file6.txt.
# В файле не нужно удалять знаки препинания! Просто прочитайте его и разделите на слова по
# пробелам.

file = open("src/file6.txt", "r")
lines = file.read().split()

e_count = 0

for word in lines:
    for char in word:
        if char == "e":
            e_count += 1

e_percent = (e_count / len(lines)) * 100      
e_percent = '{0:.2f}'.format(e_percent)

print("В файле используется буква e в", e_percent, "% случаев.")

file.close()