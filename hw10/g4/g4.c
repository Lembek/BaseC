#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 101

/*По одному разу
В файле .txt даны два слова не более 100 символов каждое, разделенные одним пробелом. Найдите только те символы слов, 
которые встречаются в обоих словах только один раз. Напечатайте их через пробел в файл .txt в лексикографическом порядке. 

Данные на входе: 		Два слова из маленьких английских букв через пробел. Длинна каждого слова не больше 100 символов. 
Данные на выходе: 	Маленькие английские буквы через пробел. 

Пример №1
Данные на входе: 		hello world 
Данные на выходе: 	o 


Данные на входе: 		aabcd bcef 
Данные на выходе: 	b c */

void fund(char * input, char * output);
int compare(const void *a, const void *b);

int main(void) {
    char input[] = "input.txt";
    char output[] = "output.txt";
    fund(input, output);
    return 0;
}

void fund(char * input, char * output) {
    FILE * in = fopen(input, "r");
    char first[SIZE];
    char second[SIZE];
    fscanf(in, "%s", first);
    fscanf(in, "%s", second);

    int amount1 = 0, flag = 0;
    char uniq_chars[SIZE] = {0};
    for (int i = 0; i < strlen(first); i++) {
        char cur = first[i];
        flag = 0;
        for (int j = 0; j < strlen(first); j++) {
            if (cur == first[j] && i != j) {
                flag++;
                break;
            }
        }
        if (!flag) {
            uniq_chars[amount1++] = cur;
        }
    }

    int amount2 = 0, count = 0;
    char result[amount1];
    for (int i = 0; i < strlen(uniq_chars); i++) {
        char cur = uniq_chars[i];
        count = 0;
        for (int j = 0; j < strlen(second); j++) {
            if (cur == second[j]) {
                count++;
            }
            if (count > 1) {
                break;
            }
        }
        if (count == 1) {
            result[amount2++] = cur;
        }
    }

    qsort(result, sizeof(char), amount2, compare);
    FILE * out = fopen(output, "w");
    for (int i = 0; i < amount2; i++) {
        fprintf(out, "%c ", result[i]);
    }

    fclose(in);
    fclose(out);
}

int compare(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}