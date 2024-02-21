#include <stdio.h>

#define SIZE 10

/*Чаще других
Дан массив из 10 элементов. Определить, какое число в массиве встречается чаще всего. Гарантируется, что такое число ровно 1. 

Данные на входе: 		10 целых числе через пробел 
Данные на выходе: 	Одно число, которое встречается чаще других. 

Пример
Данные на входе: 		4 1 2 1 11 2 34 11 0 11 
Данные на выходе: 	11*/

void input(int array[], int n);
int frequent(int array[], int n);

int main(void) {
    int array[SIZE];
    input(array, SIZE);
    printf("%d", frequent(array, SIZE));
    return 0;
}

void input(int array[], int n) {
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }
}

int frequent(int array[], int n) {
    int result;
    int count = 0, currentCount;
    for (int i = 0; i < n - 1; i++) {
        currentCount = 0;
        for (int j = i + 1; j < n; j++) {
            if (array[i] == array[j]) {
                currentCount++;
            }
        }
        if (currentCount > count) {
            count = currentCount;
            result = array[i];
        }
    }
    return result;
}