#include <stdio.h>

/*Точная степень двойки
Написать логическую рекурсивную функцию и используя ее определить является ли введенное натуральное число точной степенью двойки.
int is2pow(int n)
Данные на входе: 		Одно натуральное число. 
Данные на выходе: 	YES или NO 

Пример №1
Данные на входе: 		8 
Данные на выходе: 	YES 

Пример №2
Данные на входе: 		7 
Данные на выходе: 	NO*/

void is2pow(int n);
int recurs(int n, int answer);

int main(void) {
    int n;
    scanf("%d", &n);
    is2pow(n);
    return 0;
}

void is2pow(int n) {
    printf("%s", recurs(n , 0) == 1 ? "YES" : "NO");
}

int recurs(int n, int answer) {
    if (n > 0) {
        return recurs(n / 2, answer + n % 2);
    } else {
        return answer;
    }
}