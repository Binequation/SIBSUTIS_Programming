/*
8. В языке С одна функция может вызывать другую. Напишите программу, кото
рая вызывает функцию по имени o n e _ th re e ( ) . Эта функция должна вывести
слово “один" в одной строке, вызвать функцию two (), а затем вывести слово
“три" тоже в одной строке. Функция two () должна отобразить слово “два" в од
ной строке. Функция main () должна вывести слово “начинаем:" перед вызовом
функции o n e_ th ree () и слово “порядок!" после ее вызова. Таким образом, вы
ходные данные должны иметь следующий вид:
начинаем:
ОДИН
два
три
порядок!
*/

#include "stdio.h"

void two() { printf("два\n"); }
void one_three() { 
    printf("ОДИН\n");
    two();
    printf("три\n");
}

int main() {
    printf("начинаем:\n");
    one_three();
    printf("порядок!\n");
}