# Дан текстовый файл (можно самим создать). Пользователь вводит новую строку текста. Напишите
# программу для добавления в середину файла введенной пользователем строки, сохраняя при этом
# старое содержимое файла.

usr_file = open("src/usr_text.txt", "r+")

def write_to_file(file):
    usr_line = input("Введите строку, которую хотите добавить в файл: ")
    file.write(usr_line)
    file.seek(0)

write_to_file(usr_file)

print("Файл записан. Добавленная строка в файле: \n", usr_file.read())