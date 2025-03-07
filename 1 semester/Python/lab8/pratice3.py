# В данном упражнении вам предстоит разработать программу, в которой у 
# пользователя будет запрошен список слов, пока он не оставит строку ввода пустой.
# После этого на экране должны быть показаны слова, введен- ные пользователем, 
# но без повторов, – каждое по одному разу. При этом слова должны быть отображены 
# в том же порядке, в каком их вводили с клавиатуры.

words = []
while True:
    word = input("Введите слово: ")
    if word == "":
        break
    words.append(word)
unique_words = " ".join(set(words))
print("Слова без повторов:")
print(*unique_words.split(" "), sep="\n")