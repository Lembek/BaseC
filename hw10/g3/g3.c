#include <stdio.h>

/*Последний номер символа
В файле .txt дана строка из 1000 символов. Показать номера символов, совпадающих с последним символом строки. 
Результат записать в файл .txt 

Данные на входе: 		Строка не более 1000 символов 
Данные на выходе: 	Целые числа через пробел - номера символа, который совпадает с последним символом строки. 

Пример
Данные на входе: 		aabbcdb 
Данные на выходе: 	2 3 */

void getIndexes(char * input, char * output);

int main(void) {
    char input[] = "input.txt";
    char output[] = "output.txt";
    getIndexes(input, output);
    return 0;
}

void getIndexes(char * input, char * output) {
    FILE *in = fopen(input, "r");
    if (in == NULL) {
        perror("Can't open file");
    }

    fseek(in, -1, SEEK_END);
    int last = ftell(in);  //запоминаем позицию последнего элемента чтобы не записывать его в файл
    char c = fgetc(in);
    fseek(in, 0, SEEK_SET);

    int index = 0;
    char cur;
    FILE *out = fopen(output, "w");
    while (((cur = fgetc(in)) != EOF) && (cur != '\n')) {
        if (cur == c && index != last) {
            fprintf(out, "%d ", index);
        }
        index++;
    }

    fclose(in);
    fclose(out);
}