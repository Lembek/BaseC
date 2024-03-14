#include <stdio.h>
#include <string.h>
#define SIZE 1001

/*Заканчивается на a
В файле .txt дано предложение. Необходимо определить, сколько слов заканчиваются на букву 'а'. Ответ записать в файл .txt. 

Данные на входе: 		Строка из английских букв и пробелов не более 1000 символов. 
Данные на выходе: 	Одно целое число 

Пример
Данные на входе: 		Mama mila ramu 
Данные на выходе: 	2*/

void countWords(char * input, char * output);

int main(void) {
    char input[] = "input.txt";
    char output[] = "output.txt";
    countWords(input, output);
    return 0;
}

void countWords(char * input, char * output) {
    FILE * in = fopen(input, "r");
    char str[SIZE];
    fgets(str, SIZE, in);

    int amount = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == 'a' && str[i + 1] < 33) {
            amount++;
        }
    }

    FILE * out = fopen(output, "w");
    fprintf(out, "%d", amount);

    fclose(in);
    fclose(out);
}