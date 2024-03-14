#include <stdio.h>
#include <stdlib.h>
#define SIZE 1001

/*Числа в массив
В файле .txt дана строка, не более 1000 символов, содержащая буквы, целые числа и иные символы. 
Требуется все числа, которые встречаются в строке, поместить в отдельный целочисленный массив.
Например, если дана строка "data 48 call 9 read13 blank0a", то в массиве числа 48, 9, 13 и 0. 
Вывести массив по возрастанию в файл .txt. 

Данные на входе: 		Строка из английских букв, цифр и знаков препинания 
Данные на выходе: 	Последовательность целых чисел отсортированная по возрастанию 

Пример
Данные на входе: 		data 48 call 9 read13 blank0a 
Данные на выходе: 	0 9 13 48 */

int compare(const void *a, const void *b);
void getNums(char * input, char * output);

int main(void) {
    char input[] = "input.txt";
    char output[] = "output.txt";
    getNums(input, output);
    return 0;
}

void getNums(char * input, char * output) {
    FILE * in = fopen(input, "r");

    char str[SIZE] = {0};
    int chars_amount = 0;
    char c;
    while ((c = fgetc(in)) != EOF && (c != '\n')) {
        str[chars_amount++] = c;
    }

    int value = 0, nums_amount = 0;
    int nums[SIZE];
    for (int i = 0; i < chars_amount; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            value = value * 10 + str[i] - '0';
            if (str[i + 1] < '0' || str[i + 1] > '9') {
                nums[nums_amount++] = value;
                value = 0;
            }
        }
    }

    qsort(nums, nums_amount, sizeof(int), compare);

    FILE * out = fopen(output, "w");
    for (int i = 0; i < nums_amount; i++) {
        fprintf(out, "%d ", nums[i]);
    }

    fclose(in);
    fclose(out);
}

int compare(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}