# Для выигрыша главного приза необходимо, чтобы шесть номеров
# на лотерейном билете совпали с шестью числами, выпавшими 
# случайным образом в диапазоне от 1 до 49 во время очередного
# тиража. Напишите программу, которая будет случайным образом 
# генерировать билет.

import random

print("Ваш билет: ", end="")
for i in range(6):
    print(random.randint(1, 50), end=" ")
print('\n')