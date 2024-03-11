#include <stdio.h>
#define SIZE 100

/*В заданном интервале
Написать функцию и программу, демонстрирующую работу данной функции, которая возвращает количество элементов 
на заданном отрезке [from, to] для массива. Прототип функции
int count_between(int from, int to, int size, int a[])

Данные на входе: 		Функция принимает значения концов отрезка from и to, размер массива, массив целых чисел. 
Данные на выходе: 	Функция возвращает целое число - количество чисел в интервале [from, to] 

Пример
Данные на входе: 		4 6 1 2 3 4 5 6 7 8 9 10 
Данные на выходе: 	3 

Примечание — Интервал 4 6 числа 4 5 6 к-во 3
*/

int count_between(int from, int to, int size, int a[]);
int init(int a[]);

int main(void) {
    int from, to;
    int a[SIZE];
    scanf("%d %d", &from, &to);
    printf("%d", count_between(from, to, init(a), a));
    return 0;
}

int init(int a[]) {
    int i = 0, num;
    while (scanf("%d ", &num) == 1) {
        a[i++] = num;
    }
    return i;
}

int count_between(int from, int to, int size, int a[]) {
    int amount = 0;
    for (int i = 0; i < size; i++) {
        if (a[i] >= from && a[i] <= to) {
            amount++;
        }
    }
    return amount;
}