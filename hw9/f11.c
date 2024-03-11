#include <stdio.h>
#include <limits.h>
#define SIZE 30

/*Сумма минимальна
Написать функцию и программу, демонстрирующую работу данной функции.
Дан целочисленный массив из 30 элементов. Элементы массива могут принимать произвольные целые значения помещающиеся в int. 
Необходимо создать функцию, которая находит и выводит в порядке возрастания номера двух элементов массива, сумма которых минимальна. 

Данные на входе: 		Последовательность из 30 целых чисел через пробел 
Данные на выходе: 	Два целых числа через пробел 

Пример
Данные на входе: 		1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 
Данные на выходе: 	0 1 */

void init(int a[]);
int find_min_index(int a[], int exlude);
void print_min_sum(int a[]);

int main(void) {
    int a[SIZE];
    init(a);
    print_min_sum(a);
    return 0;
}

void init(int a[]) {
    int num;
    for (int i = 0; i < SIZE; i++) {
        scanf("%d", &num);
        a[i] = num;
    }
}

int find_min_index(int a[], int exlude) {
    int min = INT_MAX, index1 = 0;
    for (int i = 0; i < SIZE; i++) {
        if (a[i] < min && i != exlude) {
            min = a[i];
            index1 = i;
        }
    }
    return index1;
}

void print_min_sum(int a[]) {
    int index1 = find_min_index(a, -1);
    int index2 = find_min_index(a, index1);
    if (index1 > index2) {
        index1 += index2;
        index2 = index1 - index2;
    }
    printf("%d %d", index1, index2);
}