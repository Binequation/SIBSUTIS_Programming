// Напишите программу, которая запрашивает ввод нижнего и верхнего пределов
// последовательности целых чисел, вычисляет сумму всех квадратов целых чисел,
// начиная с квадрата нижнего целочисленного предела и заканчивая квадратом
// верхнего целочисленного предела, после чего отобр^ажает результат на экране.
// Затем программа дложна запрашивать ввод следующих предельных значений и
// отображать ответ, пока пользователь не введет значение верхнего предела, ко­
// торый меньше или равен нижнему пределу. Результаты выполнения программы
// дложны выглядеть следующим образом:
// Введите нижний и верхний целочисленные пределы: 5 9
// Сумма квадратов целых чисел от 25 до 81 равна 255
// Введите следующую комбинацию пределов: З 25
// Сумма квадратов целых чисел от 9 до 625 равна 95
// Введите следующую комбинацию пределов: 5 5
// Работа завершена

#include "stdio.h"

int main() 
{
    int lower_bound = 0, upper_bound = 0, pow_sum = 0;
    
    while (1) 
    {
        printf("Введите нижний и верхний целочисленные пределы: ");
        scanf("%d %d", &lower_bound, &upper_bound);

        if (lower_bound >= upper_bound) 
        {
            printf("Работа завершена\n");
            break;
        }

        for (int i = lower_bound; i <= upper_bound; i++) 
            pow_sum += i * i;

        printf("Сумма квадратов целых чисел от %d до %d равна %d\n", lower_bound * lower_bound, upper_bound * upper_bound, pow_sum);
        pow_sum = 0;
    }
}