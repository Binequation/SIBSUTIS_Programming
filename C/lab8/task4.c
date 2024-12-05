// Напишите функцию которая возвращает индекс наибольшего значения в мас
// сиве значений типа double. Протестируйте эту функцию с помощью простой
// программы.

// Подключение библиотеки
#include "stdio.h"

// Объявление функции
int find_max(double arr[]);

// Главная функция 
int main()
{
    // Запрашиваем размерность массива 
    printf("Введите длину массива: ");

    // Считываем размерность массива
    int arr_size;
    scanf("%d", &arr_size);

    // Задаем массиву размер константным значением
    double arr[arr_size];

    // Заполняем каждый элемент массива числом,
    // введным пользователем
    for (int i = 0; i < arr_size; i++) 
        arr[i] = scanf("%lf", &arr[i]);

    // Выводим индекс, под которым находится самое большое значение в массиве
    printf("Индекс наибольшего значения в массиве: %d\n", find_max(arr));
}

// Находит индекс под которым находится 
// максимальное значение в созданном 
// пользователем массиве
int find_max(double arr[]) 
{
    // Хранит индекс, где находится
    // самое большое число
    int max_index = 0;

    // Проходимся по каждому элементу и сравниваем числа под индексами:
    // i-ый - отвечает за индекс
    // max_index - отвечает за индекс, который хранит самое большое число
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) 
    {
        // Если текущее больше того, что храним,
        // меняем индекс большого числа
        if (arr[i] > arr[max_index])
            max_index = i;
    }

    // Возращаем самое большое число в массиве
    return max_index;
}