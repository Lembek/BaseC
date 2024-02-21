#include <stdio.h>

#define SIZE 40

/*Переставить цифры
Переставить цифры в числе так, чтобы получилось максимальное число. 
Данные на входе: 		Одно целое не отрицательное число 
Данные на выходе: 	Целое неотрицательное число 

Пример №1
Данные на входе: 		1229 
Данные на выходе: 	9221 

Пример №2
Данные на входе: 		19 
Данные на выходе: 	91*/

void print(int array[], int n);
int getNums(int a, int nums[]);
void swap(int array[], int i, int j);
void sort(int array[], int n);

int main(void) {
    int a;
    scanf("%d", &a);
    int nums[SIZE] = {0};
    int len = getNums(a, nums);
    sort(nums, len);
    print(nums, len);
    return 0;
}

void print(int array[], int n) {
    for (int i = 0; i <n; i++) {
        printf("%d", array[i]);
    }
}

int getNums(int a, int nums[]) {
    int count = 0;
    while (a > 0) {
        nums[count++] = a % 10;
        a /= 10;
    }
    return count;
}

void sort(int array[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (array[i] < array[j]) {
                swap(array, i, j);
            }
        }
    }
}

void swap(int array[], int i, int j) {
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}