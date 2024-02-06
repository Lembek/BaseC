#include <stdio.h>

/*Факториал
Составить функцию вычисления N!. Использовать ее при вычислении факториала
int factorial(int n)

Данные на входе: 		Целое положительное число не больше 20 
Данные на выходе: 	Целое положительное число 

Пример №1
Данные на входе: 		5 
Данные на выходе: 	120 */

unsigned int factorial(int n); // при n = 20 результат не помещается в int, поэтому использовал unsigned

int main(void) {
    int n;
    scanf("%d", &n);
    printf("%u", factorial(n));
    return 0;
}

unsigned int factorial(int n) {
    unsigned int result = 1;
    while (n > 1) {
        result *= n--;
    }
    return result;
}