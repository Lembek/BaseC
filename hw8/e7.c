#include <stdio.h>

#define SIZE 10

/*Инверсия половинок
Считать массив из 10 элементов и выполнить инверсию отдельно для 1-ой и 2-ой половин массива. 
Необходимо изменить считанный массив и напечатать его одним циклом. 

Данные на входе: 		10 целых элементов массива через пробел. 
Данные на выходе: 	10 целых элементов массива через пробел. 

Пример №1
Данные на входе: 		4 -5 3 10 -4 -6 8 -10 1 0 
Данные на выходе: 	-4 10 3 -5 4 0 1 -10 8 -6 

Пример №2
Данные на входе: 		1 2 3 4 5 6 7 8 9 10 
Данные на выходе: 	5 4 3 2 1 10 9 8 7 6*/

void input(int array[], int n);
void print(int array[], int n);
void reverse(int array[], int n);
void swap(int array[], int i, int j);

int main(void) {
    int array[SIZE];
    input(array, SIZE);
    reverse(array, SIZE);
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

void reverse(int array[], int n) {
    for (int i = 0; i < n / 4; i++) {
        swap(array, i, n / 2 - 1 - i);
        swap(array, n / 2 + i, n - 1 - i);
    }
}

void swap(int array[], int i, int j) {
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

