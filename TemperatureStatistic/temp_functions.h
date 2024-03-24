#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#define MONTHS_RECORDS 13

// Структура, описывающая одну запись
typedef struct
{
    unsigned year : 12;
    unsigned month : 4;
    unsigned day : 5;
    unsigned hour : 5;
    unsigned minute : 6;
    int temperature : 8;
} data;

// Структура, в которой сгрупированы записи по одному месяцу. Предполагаем, что записи в файле идут в хронологическом порядке.
typedef struct
{
    unsigned year;
    unsigned month;
    data *start;
    int size;
} month_records;

void fill_m_record(unsigned year, unsigned month, data *start, int size, month_records *m_record);
int group_records_by_months(data *records, int size, month_records *records_by_m);
void fill_data(unsigned year, unsigned month, unsigned day, unsigned hour, unsigned minute, int temperature, data *record);
int input(char *fileName, data *records);
char *get_info_by_month(month_records *m_records, char *info);
void print(char *string);
void get_statistic(unsigned month, month_records *m_records, int m_records_size);
void print_help();