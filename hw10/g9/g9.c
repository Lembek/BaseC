#include <stdio.h>
#include <string.h>
#define SIZE 1001

/*Удалить повторяющиеся символы
В файле .txt строка из меленьких и больших английских букв, знаков препинания и пробелов. 
Требуется удалить из нее повторяющиеся символы и все пробелы. Результат записать в файл .txt. 

Данные на входе: 		Строка из меленьких и больших английских букв, знаков препинания и пробелов. 
                        Размер строки не более 1000 сивмолов. 
Данные на выходе: 	Строка из меленьких и больших английских букв. 

Пример
Данные на входе: 		abc cde def 
Данные на выходе: 	abcdef 
*/

void uniqueString(char * input, char * output);

int main(void) {
    char input[] = "input.txt";
    char output[] = "output.txt";
    uniqueString(input, output);
    return 0;
}

void uniqueString(char * input, char * output) {
    FILE * in = fopen(input, "r");
    char str[SIZE];
    fgets(str, SIZE, in);

    int isWriten[127] = {0};
    FILE * out = fopen(output, "w");
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] > 32) {
            if (isWriten[str[i]] == 0) {
                isWriten[str[i]] = 1;
                fputc(str[i], out);
            }
        }
    }

    fclose(in);
    fclose(out);
}