#include <stdio.h>

#define SIZE 40

/*Цифры по порядку
Вывести в порядке следования цифры, входящие в десятичную запись натурального числа N. 

Данные на входе: 		Одно натуральное число N 
Данные на выходе: 	Цифры через пробел 

Пример
Данные на входе: 		54412 
Данные на выходе: 	5 4 4 1 2*/

void print(int array[], int n);
int getNums(int a, int nums[]);

int main(void) {
    int a;
    scanf("%d", &a);
    int nums[SIZE] = {0};
    print(nums, getNums(a, nums));
    return 0;
}

void print(int array[], int n) {
    for (int i = n - 1; i >= 0; i--) {
        printf("%d ", array[i]);
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