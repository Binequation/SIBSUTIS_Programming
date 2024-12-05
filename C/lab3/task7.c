/*
7. Н а п и ш и т е программу, которая присваивает п е р е м е н н о й типа d o u b l e значение
1.0/3.0 и п е р е м е н н о й тина float значение 1.0/3.0. Отобразите к а ж д ы й резуль
тат три раза: в первом случае с ч е т ы р ь м я ц и ф р а м и справа от десятичной точки,
во вто р о м случае с двенадцатью ц и ф р а м и и в третьем случае с шестнадцатью
цифрами. В к л ю ч и т е также в программу заголовочный ф а й л f loa t.h и выведите
значения FLT_DIG и DBL_DIG. Согласуются ли в ы в е д е н н ы е значения со значени
ем 1.0/0.3?
*/

#include "stdio.h"
#include "float.h"

#define FMAX FLT_MAX
#define DMAX DBL_MAX

int main() 
{
    float eq = 1.0 / 3.0;

    printf("#1\n%.4f\n%.4f\n%.4f\n\n", eq, FMAX, DMAX);
    printf("#2\n%.12f\n%.12f\n%.12f\n\n", eq, FMAX, DMAX);
    printf("#3\n%.16f\n%.16f\n%.16f\n", eq, FMAX, DMAX);
}