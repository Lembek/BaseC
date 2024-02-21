#include <stdio.h>

#define SIZE 10

/*По убыванию и по возрастанию
Считать массив из 10 элементов и отсортировать первую половину по возрастанию, а вторую – по убыванию. 

Данные на входе: 		10 целых чисел через пробел 
Данные на выходе: 	Исходный массив. Первая часть отсортирована по возрастанию, вторая половина по убыванию. 

Пример №1
Данные на входе: 		14 25 13 30 76 58 32 11 41 97 
Данные на выходе: 	13 14 25 30 76 97 58 41 32 11 

Пример №2
Данные на входе: 		5 4 3 2 1 6 7 8 9 10 
Данные на выходе: 	1 2 3 4 5 10 9 8 7 6 
*/

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
    for (int i = 0; i < n / 2 - 1; i++) {
        for (int j = i + 1; j < n / 2; j++) {
            if (array[i] > array[j]) {
                swap(array, i, j);
            }
        }
    }
    for (int i = n / 2; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (array[i] < array[j]) {
                swap(array, i, j);
            }
        }
    }
}