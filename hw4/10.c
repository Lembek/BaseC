#include <stdio.h>

/*
Ввести номер месяца и вывести название времени года.
Данные на входе:    	Целое число от 1 до 12 - номер месяца.
Данные на выходе:     Время года на английском: winter, spring, summer, autumn (используйте switch)
Пример №1
Данные на входе:      	4
Данные на выходе:     spring
Пример №2   
Данные на входе:      1
Данные на выходе:    winter
*/

int main() {
    int a;
    scanf("%d", &a);
    switch (a)
    {
    case 12:
    case 1:
    case 2:
        printf("%s", "winter");
        break;
    case 3:
    case 4:
    case 5:
        printf("%s", "spring");
        break;
    case 6:
    case 7:
    case 8:
        printf("%s", "summer");
        break;
    case 9:
    case 10:
    case 11:
        printf("%s", "autumn");
        break;
    default:
        printf("%s", "Wrong month's number");
    }
    return 0;
}