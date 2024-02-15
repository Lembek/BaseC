#include <stdio.h>

/*Количество 1
Дано натуральное число N. Посчитать количество «1» в двоичной записи числа. 
Данные на входе: 		Натуральное число 
Данные на выходе: 	Целое число - количество единиц в двоичной записи числа. 

Пример №1
Данные на входе: 		5 
Данные на выходе: 	2 

Пример №2
Данные на входе: 		255 
Данные на выходе: 	8*/

int rec(int n);
int recurs(int n, int answer);

int main(void) {
    int n;
    scanf("%d", &n);
    printf("%d", rec(n));
    return 0;
}

int rec(int n) {
    return recurs(n, 0);
}

int recurs(int n, int answer) {
    if (n > 0) {
        return recurs(n / 2, answer + n % 2);
    } else {
        return answer;
    }
}

