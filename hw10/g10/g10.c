#include <stdio.h>
#include <string.h>
#define SIZE 1001

/*Самое длинное слово
В файле .txt дана строка слов, разделенных пробелами. Найти самое длинное слово и вывести его в файл .txt. 
Случай, когда самых длинных слов может быть несколько, не обрабатывать. 

Данные на входе: 		Строка из английских букв и пробелов. Не более 1000 символов. 
Данные на выходе: 	Одно слово из английских букв. 

Пример
Данные на входе: 		Hello beautiful world 
Данные на выходе: 	beautiful */

void writeBigestString(char * input, char * output);

int main(void) {
    char input[] = "input.txt";
    char output[] = "output.txt";
    writeBigestString(input, output);
    return 0;
}

void writeBigestString(char * input, char * output) {
    FILE * in = fopen(input, "r");
    char str[SIZE];
    fgets(str, SIZE, in);

    int maxLength = 0, len = 0, start, pointMax;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] != 32) {
            start = i;
            while (i < strlen(str) && str[i] != 32) {
                len++;
                i++;
            }
            if (maxLength < len) {
                maxLength = len;
                pointMax = start;
                len = 0;
            }
        }
    }
    fseek(in, pointMax, SEEK_SET);
    char word[SIZE];
    fscanf(in, "%s", word);

    FILE * out = fopen(output, "w");
    fprintf(out, "%s", word);

    fclose(in);
    fclose(out);
}