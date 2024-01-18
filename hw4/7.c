#include <stdio.h>
#include <limits.h>
#define N 5
/*
Ввести пять чисел и  вывести наибольшее из них 
Нужно напечатать наибольшее число

Данные на входе:       Пять целых чисел разделенных пробелом
Данные на выходе:    Одно целое число
   
Данные на входе:        4    15    9    56    4
Данные на выходе:     56   
*/

int main() {
    int max = INT_MIN;
    int a;
    for (int i = 0; i < N; i++) {
        scanf("%d", &a);
        if (a > max) {
            max = a;
        }
    }
    printf("%d", max);
    return 0;
}