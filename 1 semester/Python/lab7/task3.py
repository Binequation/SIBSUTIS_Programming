# Вы – разработчик программы для обработки текстовых сообщений в мессенджере. 
# Ваша задача – написать программу, которая форматирует сообщения, вставляя 
# символ точки между каждыми двумя соседними символами. В этой задаче можно 
# использовать цикл, но можно обойтись и без него (нужно догадаться самому).
# Программа должна корректно работать с различными типами входных строк, 
# включая пустые и строки из одного символа.

s = input("Введите строку: ")
print("Исправленная строка: ", *list(s), sep=".") if len(s) > 2 else print(s)