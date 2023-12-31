/*
Доказать тождества 
А → В =!A||B,
А ↔︎ В = (A && B) || (!A && !B), таблицы истинности на Си можно распечатать**
*/

#include <stdio.h>
#include <locale.h>

int main(void) {

    /* 
    А → В (если, то) А - условие, В - следствие, выражение ложно титт, когда условие выполнено (1),
    но следствия не было (0)    
    */
    printf("A       B       A -> B       !A||B\n");
    printf("0       0         1            1\n");
    printf("0       1         1            1\n");
    printf("1       0         0            0\n");
    printf("1       1         1            1\n");

    /*
    А ↔︎ В (тогда и только тогда), истинно, когда оба аргумента одинаковы
    */
    printf("A       B       A <-> B      (A && B) || (!A && !B)\n");
    printf("0       0         1                      1\n");
    printf("0       1         0                      0\n");
    printf("1       0         0                      0\n");
    printf("1       1         1                      1\n");
    return 0;
}