// Напишите программу, которая запрашивает у пользователя ввод значения температуры по Фаренгейту. Программа должна считывать значение температуры
// как число типа double и передавать его в виде аргумента пользовательской функции по имени T e m p e r a t u r e s (). Эта функция должна вычислять эквивалентные значения температуры 110 Цельсию и по Кельвину и отображать на экране
// все три значения температуры с точностью до двух позиций справа от десятичной точки. Функция должна идентифицировать каждое значение символом соответствующей температурной шкалы. Вот формула перевода температуры по
// Фаренгейту в температуру по Цельсию:
// Т ем перат ура по Ц ельсию = 5.0 / 9.0 х ( т ем п ерат ура п о Ф арен гей т у - 32.0)
// В шкале Кельвина, которая обычно применяется в науке, О представляет абсолютный нуль, т.е. минимальный предел возможных температур. Формула перевода температуры по Цельсию в температуру по Фаренгейту имеет вид:
// Темпер<та:тура п о К ельви н у = т ем п ерат ура п о Ц т ь с и ю + 273. 16
// Функция Tempera tures () должна использовать const для создания символических представлений трех констант, которые участвуют в преобразованиях. Чтобы
// предоставить пользователю возможность многократного ввода значений температуры, в функции main () должен быть организован цикл который завершается
// при вводе символа q или другого нечислового значения. Воспользуйтесь тем фактом, что функция scanf () возвращает количество прочитанных ею элементов,
// поэтому она возвратит 1, если прочитает число, но не будет возвращать 1, когда
// пользователь введет q. Операция == выполняет проверку на равенство, так что
// ее можно применять для сравнения возвращаемого значения scanf () с 1.

#include <stdio.h>

void Temperatures(double fahrenheit);

int main() {
    double fahrenheit;
    char input[10];

    while (1) {
        printf("Введите температуру в Фаренгейтах (или 'q' для выхода): ");
        if (scanf("%s", input) != 1 || input[0] == 'q') { break; }

        if (sscanf(input, "%lf", &fahrenheit) == 1) {
            Temperatures(fahrenheit);
        } else {
            printf("Некорректный ввод. Пожалуйста, введите число или 'q' для выхода.\n");
        }
    }
}

void Temperatures(double fahrenheit) {
    const double FAHRENHEIT_TO_CELSIUS = 5.0 / 9.0;
    const double CELSIUS_TO_KELVIN = 273.16;
    const double OFFSET = 32.0;

    double celsius = FAHRENHEIT_TO_CELSIUS * (fahrenheit - OFFSET);
    double kelvin = celsius + CELSIUS_TO_KELVIN;

    printf("Температура: %.2f °F, %.2f °C, %.2f K\n", fahrenheit, celsius, kelvin);
}