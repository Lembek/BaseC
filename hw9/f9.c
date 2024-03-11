#include <stdio.h>
#include <limits.h>
#define SIZE 100

/*Поменять местами
Написать функцию и программу, демонстрирующую работу данной функции, которая в массиве находит максимальный из отрицательных элементов 
и меняет его местами с последним элементом массива. Гарантируется, что в массиве только один такой элемент или же
такой элемент отсутствует. Если отрицательных элементов нет - массив не менять.

Прототип функции:
void swap_negmax_last(int size, int a[])

Данные на входе: 		Функция принимает на вход размер массива и указатель на начало массива. Массив состоит из целых чисел. 

Пример
Данные на входе: 		1 -2 -3 -4 5 6 7 8 9 10 
Данные на выходе: 	1 10 -3 -4 5 6 7 8 9 -2 
*/

void swap_negmax_last(int size, int a[]);
int init(int a[]);
void swap(int array[], int i, int j);
int negative_max(int size, int a[]);
void print(int size, int a[]);

int main(void) {
    int array[SIZE];
    int size = init(array);
    swap_negmax_last(size, array);
    print(size, array);
    return 0;
}

int init(int a[]) {
    int i = 0, num;
    while (scanf("%d ", &num) == 1) {
        a[i++] = num;
    }
    return i;
}

int negative_max(int size, int a[]) {
    int min = INT_MIN;
    for (int i = 1; i < size; i++) {
        if (a[i] < 0 && a[i] > min) {
            min = a[i];
        }
    }
    return min == INT_MIN ? 0 : min;
}

void swap_negmax_last(int size, int a[]) {
    int negative = negative_max(size, a);
    if (negative < 0) {
        for (int i = 0; i < size; i++) {
            if (a[i] == negative) {
                swap(a, i, size - 1);
                return;
            }
        }
    }
}

void swap(int array[], int i, int j) {
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

void print(int size, int a[]) {
    for (int i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
}