#include <stdio.h>

#define SIZE 5

/*Среднее арифметическое чисел
Ввести c клавиатуры массив из 5 элементов, найти среднее арифметическое всех элементов массива. 

Данные на входе: 		5 целых ненулевых чисел через пробел 
Данные на выходе: 	Одно число в формате "%.3f" 

Пример №1
Данные на входе: 		4 15 3 10 14 
Данные на выходе: 	9.200 

Пример №2
Данные на входе: 		1 2 3 4 5 
Данные на выходе: 	3.000*/

void input(int array[], int n);
float middle(int array[], int n);

int main(void) {
    int array[SIZE];
    input(array, SIZE);
    printf("%.3f", middle(array, SIZE));
    return 0;
}

void input(int array[], int n) {
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }
}

float middle(int array[], int n) {
    float result = 0;
    for (int i = 0; i < n; i++) {
        result += array[i];
    }
    return result / n;
}