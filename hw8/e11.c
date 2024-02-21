#include <stdio.h>

#define SIZE 10

/*Отсортировать по последней цифре
Считать массив из 10 элементов и отсортировать его по последней цифре. 

Данные на входе: 		10 целых чисел через пробел 
Этот же массив отсортированный по последней цифре 

Пример №1
Данные на входе: 		14 25 13 30 76 58 32 11 41 97 
Данные на выходе: 	30 11 41 32 13 14 25 76 97 58 

Пример №2
Данные на входе: 		109 118 100 51 62 73 1007 16 4 555 
Данные на выходе: 	100 51 62 73 4 555 16 1007 118 109*/

void input(int array[], int n);
void print(int array[], int n);
void swap(int array[], int i, int j);
void sort(int array[], int n);

int main(void) {
    int array[SIZE];
    input(array, SIZE);
    sort(array, SIZE);
    print(array, SIZE);
    return 0;
}

void input(int array[], int n) {
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }
}

void print(int array[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
}

void swap(int array[], int i, int j) {
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

void sort(int array[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (array[i] % 10 > array[j] % 10) {
                swap(array, i, j);
            }
        }
    }
}