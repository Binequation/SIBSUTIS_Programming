/*
2. Нанишите программу, которая приглашает ввести некоторое значение в коде
ДОСИ, например, 66, а затем выводит символ, которому соответствует введен
ный код.
*/

#include "stdio.h"

int main() {
    printf("Введите любое значение: ");
    
    int usr_choice;
    scanf("%d", &usr_choice);
    printf("%c\n", usr_choice);
}