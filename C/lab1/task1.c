/*
1. Напишите программу, которая использует первый вызов функции printf() для
вывода своего имени и фамилии в одной строке, второй вызов printf(), чтобы
вывести имя и фамилию в двух строках, и еще два вызова printf() для вывода
имени и фамилии в одной строке. Выходные данные должны иметь следующий
вид (но с указанием ваших персональных данных):
Иван Иванов ^Первый оператор вывода
Иван ^Второй оператор вывода
Иванов ^По-прежнему второй операторвывода
Иван Иванов ^Третий и четвертый операторы вывода
*/

#include "stdio.h"

int main() {
	printf("Иван Иванов\n");
	printf("Иван\nИванов\n");
	printf("Иван ");
	printf("Иванов");
}
