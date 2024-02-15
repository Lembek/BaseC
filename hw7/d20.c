#include <stdio.h>

/*Возвести в степень
Написать рекурсивную функцию возведения целого числа n в степень p.
int recurs_power(int n, int p)
Используя данную функцию, решить задачу.

Данные на входе: 		Два целых положительных числа
Данные на выходе: 	Одно целое число n в степени p

Пример №1
Данные на входе: 		2 3
Данные на выходе: 	8

Пример №2
Данные на входе: 		3 4
Данные на выходе: 	81*/

int recurs_power(int n, int p);

int main(void) {
    int n, p;
    scanf("%d %d", &n, &p);
    printf("%d", recurs_power(n, p));
    return 0;
}

int recurs_power(int n, int p) {
    if (p > 1) {
        return n * recurs_power(n, p - 1);
    } else {
        return n;
    }
}