#include <stdio.h>
#define SIZE 100

/*Заменить a на b
В файле .txt дана символьная строка не более 1000 символов. Необходимо заменить все буквы "а" на буквы "b" и наоборот, 
как заглавные, так и строчные. Результат записать в .txt. 

Данные на входе: 		Строка из маленьких и больших английских букв, знаков препинания и пробелов. 
Данные на выходе: 	Строка из маленьких и больших английских букв, знаков препинания и пробелов. 

Пример
Данные на входе: 		aabbccddABCD 
Данные на выходе: 	bbaaccddBACD 
*/

void changeString(char * input, char * output);
char upgrade(char c);

int main(void) {
    char input[] = "input.txt";
    char output[] = "output.txt";
    changeString(input, output);
    return 0;
}

void changeString(char * input, char * output) {
    FILE * in = fopen(input, "r");
    FILE * out = fopen(output, "w");

    char cur;
    while ((cur = fgetc(in)) != EOF && cur != '\n') {
        fputc(upgrade(cur), out);
    }

    fclose(in);
    fclose(out);
}

char upgrade(char c) {
    if (c == 'a' || c == 'A') {
        return c + 1;
    }
    if (c == 'b' || c == 'B') {
        return c - 1;
    }
    return c;
}