#include <stdio.h>

#define SIZE 10

/*Только один раз
Дан массив из 10 элементов. В массиве найти элементы, которые в нем встречаются только один раз, и вывести их на экран. 

Данные на входе: 		10 целых чисел через пробел 
Данные на выходе: 	Элементы которые встречаются только один раз через пробел 

Пример
Данные на входе: 		5 -4 0 1 4 -3 -3 3 0 2 
Данные на выходе: 	5 -4 1 4 3 2*/

void print(int array[], int n);
void input(int array[], int n);
int amount(int array[], int n, int index);
int justOne(int array[], int n, int out[]);

int main(void) {
    int array[SIZE], out[SIZE];
    input(array, SIZE);
    print(out, justOne(array, SIZE, out));
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

int amount(int array[], int n, int index) {
    int result = 0;
    for (int i = 0; i < n; i++) {
        if (array[i] == array[index]) {
            result++;
        }
    }
    return result;
}

int justOne(int array[], int n, int out[]) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (amount(array, n, i) == 1) {
            out[count++] = array[i];
        }
    }
    return count;
}

