// Чаки Лаки выиграл миллион долларов (после уплаты всех налогов), который он
// поместил на счет со ставкой 8% годовых. В последний день каждого года Чаки
// снимает со счета по $100 ООО. Напишите программу, которая вычисляет, сколько
// лет пройдет до того, как на счету Чаки не останется денег.

#include "stdio.h"

int main() {
    float money = 1000000;
    int years = 0;

    while (money > 0) {
        money -= 100000;
        money += money * 0.08;
        years++;
    }

    printf("%d лет пройдет.\n", years);
}