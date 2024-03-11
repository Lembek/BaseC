#include <stdio.h>
#define SIZE 100

/*Сумма в интервале
Написать функцию и программу, демонстрирующую работу данной функции, которая возвращает сумму элементов в заданном отрезке 
[from, to] для массива. Прототип функции
int sum_between_ab(int from, int to, int size, int a[]) 

Данные на входе: 		Функция принимает концы отрезка from и to, размер массива, массив целых чисел 
Функция возвращает сумму элементов в интервале [from, to] 

Пример №1
Данные на входе: 		4 6 1 2 3 4 5 6 7 8 9 10 
Данные на выходе: 	15 

Пример №2
Данные на входе: 		6 4 1 2 3 4 5 6 7 8 9 10 
Данные на выходе: 	15 

Примечание — Интервал 4 6 числа 4 5 6 к-во 3 сумма 15

*/

int sum_between_ab(int from, int to, int size, int a[]);
int init(int a[]);

int main(void) {
    int from, to;
    int a[SIZE];
    scanf("%d %d", &from, &to);
    printf("%d", sum_between_ab(from, to, init(a), a));
    return 0;
}

int init(int a[]) {
    int i = 0, num;
    while (scanf("%d ", &num) == 1) {
        a[i++] = num;
    }
    return i;
}

int sum_between_ab(int from, int to, int size, int a[]) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        if (a[i] >= from && a[i] <= to) {
            sum += a[i];
        }
    }
    return sum;
}