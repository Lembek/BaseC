#include <stdio.h>
#define SIZE 5

/*След матрицы 
Написать функцию и программу, демонстрирующую работу данной функции, которая находит след матрицы в двумерном массиве. 
Показать пример ее работы на матрице из 5 на 5 элементов. След матрицы - это сумма элементов на главной диагонали. 

Данные на входе: 		25 целых чисел через пробел. 
Данные на выходе: 	Одно целое число. 

Пример
Данные на входе: 		                           1 1 1 1 1 
                                                   2 2 2 2 2
                                                   3 3 3 3 3 
                                                   4 4 4 4 4 
                                                   5 5 5 5 5 
Данные на выходе: 	15 */

void init(int n, int a[n][n]);
int sum_diagonal(int n, int a[n][n]);

int main(void) {
    int a[SIZE][SIZE];
    init(SIZE, a);
    printf("%d\n", sum_diagonal(SIZE, a));
    return 0;
}

int sum_diagonal(int n, int a[n][n]) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i][i];
    }
    return sum;
}

void init(int n, int a[n][n]) {
    int num;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &num);
            a[i][j] = num;
        }
    }
}