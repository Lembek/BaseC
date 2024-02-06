#include <stdio.h>

/*C17 ДЗ
Сумма цифр равна произведению

Составить логическую функцию, которая определяет, верно ли, что в данном числе сумма цифр равна произведению.

int is_happy_number(int n)

Данные на входе: 		Целое не отрицательное число 
Данные на выходе: 	YES или NO 

Пример №1
Данные на входе: 		123 
Данные на выходе: 	YES 

Пример №2
Данные на входе: 		528 
Данные на выходе: 	NO
*/

int is_happy_number(int n);

int main(void) {
    int n;
    scanf("%d", &n);
    printf("%s", is_happy_number(n) == 0 ? "YES" : "NO");
    return 0;
}

int is_happy_number(int n) {
    int num;
    int sum = 0;
    int multy = 1;
    while (n > 0) {
        num = n % 10;
        n /= 10;
        sum += num;
        multy *= num;
    }
    return multy == sum ? 0 : 1;
}