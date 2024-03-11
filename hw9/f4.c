#include <stdio.h>
#include <stdbool.h>

#define SIZE 100

/*Цифры в строке
Написать функцию и программу, демонстрирующую работу данной функции.
Вывести в порядке возрастания цифры, входящие в строку. Цифра - количество. Функция должно строго соответствовать прототипу:

void print_digit(char s[])

Данные на входе: 		Строка из английских букв, пробелов, знаков препинания и цифр 
Данные на выходе: 	Функция должна принимать на вход строку и выводить на печать по формату: Цифра пробел количество. 

Пример
Данные на входе: 		Hello123 world77. 
Данные на выходе: 	1 1 2 1 3 1 7 2*/

void print_digit(char s[]);
bool isDigit(char c);

int main(void) {
    char s[SIZE];
    scanf("%[^\n]", s);
    print_digit(s);
    return 0;
}

bool isDigit(char c) {
    return (c >= '0' && c <= '9');
}

void print_digit(char s[]) {
    int nums[10] = {0};
    char *pc = s;
    while (*pc) {
        if (isDigit(*pc)) {
            nums[*pc - 48]++;
        }
        pc++;
    }
    for (int i = 0; i < 10; i++) {
        if (nums[i] > 0) {
            printf("%d %d ", i, nums[i]);
        }
    }
}

