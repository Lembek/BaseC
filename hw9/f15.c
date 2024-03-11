#include <stdio.h>
#define SIZE 100

/*Больше по модулю
Написать функцию и программу, демонстрирующую работу данной функции, которая определяет в массиве, состоящем из положительных и отрицательных чисел, сколько элементов превосходят по модулю максимальный элемент. Прототип функции
int count_bigger_abs(int n, int a[]);

Данные на входе: 		Функция получает размер массива и массив целых чисел 
Данные на выходе: 	Функция возвращает целое число раное количеству элементов превосходящих по модулю максимальный элемент. 

Пример
Данные на входе: 		1 -20 3 4 -50 6 7 8 9 10 
Данные на выходе: 	2
*/

int count_bigger_abs(int n, int a[]);
int init(int a[]);
int max(int size, int a[]);

int main(void) {
    int a[SIZE];
    printf("%d", count_bigger_abs(init(a), a));
    return 0;
}

int init(int a[]) {
    int i = 0, num;
    while (scanf("%d ", &num) == 1) {
        a[i++] = num;
    }
    return i;
}

int count_bigger_abs(int n, int a[]) {
    int amount = 0;
    int max_num = max(n, a);
    for (int i = 0; i < n; i++) {
        if (a[i] < 0 && - a[i] > max_num) {
            amount++;
        }
    }
    return amount;
}

int max(int size, int a[]) {
    int max = a[0];
    for (int i = 1; i < size; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    return max;
}