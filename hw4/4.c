#include <stdio.h>
#include <limits.h>
# define N 5

/*
Напечатать сумму максимума и минимума.

Данные на входе:	      Пять целых чисел через пробел
Данные на выходе:    Одно целое число - сумма максимума и минимума

Пример    
Данные на входе:      	4    15    9    56    4
Данные на выходе:     60
*/

int main() {
    int min = INT_MAX;
    int max = INT_MIN;
    int a;
    for (int i = 0; i < N; i++) {
        scanf("%d", &a);
        if (a > max) {
            max = a;
        }
        if (a < min) {
            min = a;
        }
    }
    printf("%d", min + max);
    return 0;
}