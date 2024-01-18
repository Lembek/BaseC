#include <stdio.h>
#include <string.h>


/*
Ввести два числа. Если первое число больше второго, то программа печатает слово Above. Если первое число меньше второго, то программа печатает слово Less. А если числа равны, программа напечатает сообщение Equal.
Данные на входе:		Два целых числа
Данные на выходе:	Одно единственное слово: Above, Less, Equal
Пример №1    
Данные на входе:		24 24
Данные на выходе:	Equal
Пример №2    
Данные на входе:      100 0
Данные на выходе:    Above
*/

int main() {
    const char above[] = "Above";
    const char less[] = "Less";
    const char equal[] = "Equal";
    int a, b;
    scanf("%d %d", &a, &b);
    const char* answer = (a > b) ? above : a < b ? less : equal;
    printf("%s", answer);
    return 0; 
    /* Подскажите, пожалуйста, как будет правильнее с точки зрения использования памяти
       записывать варианты ответа (создавать константы или записывать в тернарном операторе, есть ли разница),
       и стоит ли создавать ещё одну строку под ответ, чтобы не писать три раза оператор printf?
       Заранее спасибо за ответ!
    */
}