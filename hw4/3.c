#include <stdio.h>

/*
Дано трехзначное число, напечатать максимальную цифру

Данные на входе:        Целое положительное трехзначное число
Данные на выходе:     Одна цифра

Пример
Данные на входе:       435
Данные на выходе:    5

*/

int main() {
    int a;
    scanf("%d", &a);  //опустил проверку вводных значений
    int max = 0, divide = 100, num;
    for (int i = 0; i < 3; i++) {
        num = a / divide;
        max = max > num ? max : num;
        a %= divide;
        divide /= 10;
    }
    printf("%d", max);
}