#include <stdio.h>
#include <string.h>
#define SIZE 1001

/*Изменить расширение
В файле .txt записан полный адрес файла (возможно, без расширения). Необходимо изменить его расширение на ".html" 
и записать результат в файл .txt. 

Данные на входе: 		Строка состоящая из символов: a-z, A-Z, 0-9, / 
Данные на выходе: 	Исходная строка с измененным расширением. 

Пример №1
Данные на входе: 		/DOC.TXT/qqq 
Данные на выходе: 	/DOC.TXT/qqq.html 

Пример №2
Данные на входе: 		/DOC.TXT/qqq.com 
Данные на выходе: 	/DOC.TXT/qqq.html 
*/

void changeName(char * input, char * output);

int main(void) {
    char input[] = "input.txt";
    char output[] = "output.txt";
    changeName(input, output);
    return 0;
}

void changeName(char * input, char * output) {
    FILE * in = fopen(input, "r");
    char str[SIZE];
    fgets(str, SIZE, in);

    int border = strlen(str);
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == '.') {
            border = i;
        } else if (str[i] == '/') {
            border = strlen(str);
        }
    }

    FILE * out = fopen(output, "w");
    for (int i = 0; i < border; i++) {
        fputc(str[i], out);
    }
    fprintf(out, "%s", ".html");

    fclose(in);
    fclose(out);
}