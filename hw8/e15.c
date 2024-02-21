#include <stdio.h>

#define SIZE 10

/*Положительные и отрицательные
Считать 10 чисел в диапазоне от -500 до 500 и разложить по двум массивам: в одни помещать только положительные, во второй - только отрицательные. Числа, равные нулю, игнорировать. Вывести на экран все элементы обоих массивов. 

Данные на входе: 		10 целых чисел через пробел. 
Данные на выходе: 	Сперва положительные числа, потом отрицательыне числа, через пробел. 

Пример
Данные на входе: 		5 -4 0 1 4 -3 -3 3 0 2 
Данные на выходе: 	5 1 4 3 2 -4 -3 -3*/

void print(int array[], int n);

int main(void) {
    int a, plusSize = 0, minusSize = 0;
    int plus[SIZE], minus[SIZE];
    for (int i = 0; i < SIZE; i++) {
        scanf("%d", &a);
        if (a > 0) {
            plus[plusSize++] = a;
        } 
        if (a < 0) {
            minus[minusSize++] = a;
        }
    }
    print(plus, plusSize);
    print(minus, minusSize);
    return 0;
}

void print(int array[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
}