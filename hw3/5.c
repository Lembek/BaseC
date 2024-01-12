#include <stdio.h>

/*
На вход подается произвольное трехзначное число. 
Нужно напечатать произведение цифр.
Данные на входе:       Трехзначное целое положительное число
Данные на выходе:    Одно целое число   
Пример №1: 
Данные на входе:        435
Данные на выходе:     60   
Пример №2:     
Данные на входе:        102
Данные на выходе:    0
*/

int main() {
    int a;
    scanf("%d", &a);
    if (a < 100 || a > 999) {
        printf("%s", "Number must be more than 100 and less than 1000");
    } else {
        int multy = 1, divider = 100;
        for (int i = 0; i < 3; i++) {
            multy *= a / divider;
            a %= divider;
            divider /= 10;
        }
        printf("%d", multy);
    }
    return 0;
}