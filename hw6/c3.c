#include <stdio.h>

/*Среднее арифметическое чисел
Написать функцию, которая возвращает среднее арифметическое двух переданных ей аргументов (параметров).
int middle(int a, int b)
Данные на входе: 		Два целых неотрицательных числа 
Данные на выходе: 	Одно целое число 

Пример №1
Данные на входе: 		5 7 
Данные на выходе: 	6 

Пример №2
Данные на входе: 		10 20 
Данные на выходе: 	15 
*/
int middle(int, int);

int main(void) {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d", middle(a, b));
    return 0;
}

int middle(int a, int b) {
    return (a + b) / 2;
}