#include <stdio.h>

#define SIZE 10

/*Сумма положительных элементов
Считать массив из 10 элементов и подсчитать сумму положительных элементов массива. 

Данные на входе: 		10 целых чисел через пробел 
Данные на выходе: 	Одно целое число - сумма положительных элементов массива 

Пример №1
Данные на входе: 		4 -5 3 10 -4 -6 8 -10 1 0 
Данные на выходе: 	26 

Пример №2
Данные на входе: 		1 -2 3 -4 5 -6 7 -8 9 0 
Данные на выходе: 	25 */

void input(int array[], int n);
int sum(int array[], int n);

int main(void) {
    int array[SIZE];
    input(array, SIZE);
    printf("%d", sum(array, SIZE));
    return 0;
}

void input(int array[], int n) {
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }
}

int sum(int array[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (array[i] > 0) {
            sum += array[i];
        }
    }
    return sum;
}