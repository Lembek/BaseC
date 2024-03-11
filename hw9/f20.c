#include <stdio.h>
#define SIZE 10

/*Четные и нечетные
Написать функцию и программу, демонстрирующую работу данной функции.
Дан целочисленный массив из 10 элементов. Необходимо определить количество четных и нечетных чисел. 
Если количество чётных чисел больше, чем количество нечётных, заменить каждое нечетное число на произведение нечетных цифр
в его десятичной записи. Если количество нечётных чисел больше или равно количеству чётных, заменить каждое чётное число 
на произведение чётных цифр в его десятичной записи. 

Данные на входе: 		10 целых чисел через пробел 
Данные на выходе: 	10 целых чисел через пробел 

Пример №1
Данные на входе: 		48 31 20 61 97 12 18 100 200 123 
Данные на выходе: 	48 3 20 1 63 12 18 100 200 3 

Пример №2
Данные на входе: 		48 25 57 34 23 91 90 85 30 79 
Данные на выходе: 	32 25 57 4 23 91 0 85 0 79 

*/

void init(int n, int a[]);
void print(int n, int a[]);
void even_odd(int n, int a[]);
int change_num(int n);

int main(void) {
    int a[SIZE];
    init(SIZE, a);
    even_odd(SIZE, a);
    print(SIZE, a);
    return 0;
}

void init(int n, int a[]) {
    int num;
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        a[i] = num;
    }
}

void print(int n, int a[]) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
}

void even_odd(int n, int a[]) {
    int odd_amount = 0, even_amount = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            even_amount++;
        } else {
            odd_amount++;
        }
    }
    for (int i = 0; i < n; i++) {
        if (!(even_amount > odd_amount ^ a[i] % 2 != 0)) {
            a[i] = change_num(a[i]);
        }
    }
}

int change_num(int n) {
    int answer = 1;
    int num;
    int flag = n % 2 == 0 ? 1 : 0;
    while (n > 0) {
        num = n % 10;
        n /= 10;
        if ((flag == 1 && num % 2 == 0) || (flag == 0 && num % 2 != 0)) {
            answer *= num;
        }
    }
    return answer;
}