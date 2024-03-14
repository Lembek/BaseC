#include <stdio.h>
#define SIZE 10000

/*Количество букв
В файле .txt считать символьную строку, не более 10 000 символов. 
Посчитать количество строчных (маленьких) и прописных (больших) букв в введенной строке. Учитывать только английские буквы. 
Результат записать в файл .txt. 

Данные на входе: 		Строка состоящая из английских букв, цифр, пробелов и знаков препинания. 
Данные на выходе: 	Два целых числа. Количество строчных букв и количество заглавных букв. 

Пример №1
Данные на входе: 		aabbAB 
Данные на выходе: 	4 2 

Пример №2
Данные на входе: 		HELLO WORLD 
Данные на выходе: 	0 10 

*/

void countLetters(char * input, char * output);

int main(void) {
    char input[] = "input.txt";
    char output[] = "output.txt";
    countLetters(input, output);
    return 0;
}

void countLetters(char * input, char * output) {
    FILE * in = fopen(input, "r");

    int smallAmount = 0, bigAmount = 0;
    char c;
    while ((c = fgetc(in)) != EOF && (c != '\n')) {
        if (c >= 'a' && c <= 'z') {
            smallAmount++;
        }
        if (c >= 'A' && c <= 'Z') {
            bigAmount++;
        }
    }

    FILE * out = fopen(output, "w");
    fprintf(out, "%d %d", smallAmount, bigAmount);

    fclose(in);
    fclose(out);
}