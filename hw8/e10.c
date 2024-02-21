#include <stdio.h>

#define SIZE 12
#define SHIFT 4

/*Циклический сдвиг массива вправо на 4
Считать массив из 12 элементов и выполнить циклический сдвиг ВПРАВО на 4 элемента. 

Данные на входе: 		12 целых чисел через пробел 
Данные на выходе: 	12 целых чисел через пробел 

Пример №1
Данные на входе: 		4 -5 3 10 -4 -6 8 -10 1 0 5 7 
Данные на выходе: 	1 0 5 7 4 -5 3 10 -4 -6 8 -10 

Пример №2
Данные на входе: 		1 2 3 4 5 6 7 8 9 10 11 12 
Данные на выходе: 	9 10 11 12 1 2 3 4 5 6 7 8*/

void input(int array[], int n);
void print(int array[], int n);
void shift(int array[], int n, int shift);

int main(void) {
    int array[SIZE];
    input(array, SIZE);
    shift(array, SIZE, SHIFT);
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

void shift(int array[], int n, int shift) {
    int newArray[n];
    int index;
    for (int i = 0; i < n; i++) {
        index = i + shift;
        index = index >= n ? index - n : index;
            newArray[index] = array[i];
    }
    for (int i = 0; i < n; i++) {
        array[i] = newArray[i];
    }
}