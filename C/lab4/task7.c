// Напишите программу, которая запрашивает ввод числа типа d o u b l e и выводит
//  значение куба этого числа. Для этого используйте собственную функцию,
// которая возводит значение в куб и выводит полученный результат. Программа
// main () должна передавать этой функции вводимое значение.

#include "stdio.h"
#include "math.h"

double Cube_power(double num) { return pow(num, 3); }

int main() {
    double num;
    scanf("%lf", &num);
    printf("%lf\n", Cube_power(num));
}