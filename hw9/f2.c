#include <stdio.h>
#define SIZE 100

/*Четные в начало
Написать функцию и программу, демонстрирующую работу данной функции, которая ставит в начало массива все четные элементы, 
а в конец – все нечетные. Не нарушайте порядок следования чисел между собой. Строго согласно прототипу:
void sort_even_odd(int n, int a[])

Данные на входе: 		Функция принимает на вход целые числа 
Данные на выходе: 	Отсортированный исходный массив 

Пример №1
Данные на входе: 		20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 
Данные на выходе: 	    20 18 16 14 12 10 8 6 4 2 19 17 15 13 11 9 7 5 3 1 

Пример №2
Данные на входе: 		1 0 1 0 1 
Данные на выходе: 	    0 0 1 1 1*/

void sort_even_odd(int n, int a[]);
int input(int nums[], int n);
void print(int nums[], int n);

int main(void) {
    int nums[SIZE] = {0};
    int len = input(nums, SIZE);
    sort_even_odd(len, nums);
    print(nums, len);
    return 0;
}

int input(int nums[], int n) {
    int num, i = 0;
    while (scanf("%d", &num) == 1) {
        nums[i++] = num;
    }
    return i;
}

void print(int nums[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", nums[i]);
    }
}

void sort_even_odd(int n, int a[]) {
    int array[SIZE] = {0};
    int last_odd = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            array[last_odd++] = a[i];
        }
    }
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 != 0) {
            array[last_odd++] = a[i];
        }
    }
    for (int i = 0; i < n; i++) {
        a[i] = array[i];
    }
}