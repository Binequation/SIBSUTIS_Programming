//  Внесите изменения в программу addemup. с (листинг 5.13), которая вычисляет
// сумму первых 20 целых чисел. (Если хотите, можете считать addemup. с программой,
// которая вычисляет сумму, которую вы будете иметь спустя 20 дней, если в
// первый день вы получаете $1, во второй день — $2, в третий день — $3 и т.д.)
// Модифицируйте программу так, чтобы можно было интерактивно указать, насколько
// далеко должно распространяться вычисление. Другими словами, замените число 2 
// 0 переменной, значение которой вводится пользователем.


#include <stdio.h>

int main () {
    int count = 0, sum = 0, days = 0;
    scanf("%d", &days);

    for (int i = 0; i < days; ++i) { 
        count++; sum += count;
    }
    printf("sum = %d\n", sum); 
}