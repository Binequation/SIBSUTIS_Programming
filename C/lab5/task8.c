// Напишите программу, которая запрашивает два числа с плавающей запятой и
// выводит значение их разности, деленной на их произведение. Программа должна
// обрабатывать пары вводимых чисел до тех пор, пока пользователь не введет
// нечисловое значение.

#include <stdio.h>

int main() {
    float num1, num2;
    int status1, status2;

    while (1) {
        printf("Введите первое число: ");
        status1 = scanf("%f", &num1);
        
        if (status1 != 1) {
            printf("Вы ввели не число. Программа завершена.\n");
            break;
        }

        printf("Введите второе число: ");
        status2 = scanf("%f", &num2);
        
        if (status2 != 1) {
            printf("Вы ввели не число. Программа завершена.\n");
            break;
        }

        if (num2 == 0 || (num1 * num2) == 0) {
            printf("Ошибка: деление на ноль невозможно.\n");
        } else {
            printf("Результат: %f\n", (num1 - num2) / (num1 * num2));
        }

        while (getchar() != '\n');
    }
}