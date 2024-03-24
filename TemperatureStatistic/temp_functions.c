#include "temp_functions.h"

// Пробовал объявлять и инициализировать массив в temp_functions.h,
// но тогда при сборке выдает ошибку "multiple definition of `months'"
char months[MONTHS_RECORDS][10] = {"All year", "January", "February", "March", "April", "May", "Juny", "July",
                                   "August", "September", "October", "November", "December"};

// Конструктор для month_records, валидацию не провожу, т к сюда будут поступать данные с уже провалидированных data
void fill_m_record(unsigned year, unsigned month, data *start, int size, month_records *m_record)
{
    m_record->year = year;
    m_record->month = month;
    m_record->start = start;
    m_record->size = size;
}

// Заполняем массив month_records * за один проход по records, таким образом мы в будущем
// можем быстро находить статистику по каждому месяцу
int group_records_by_months(data *records, int size, month_records *m_records)
{
    int amount = 0, start = 0;
    unsigned y = records->year;
    for (int i = 0; i < size; i++)
    {
        unsigned m = records[i].month;
        start = i;
        while (i < size && records[i].month == m)
        {
            i++;
        }
        fill_m_record(y, m, &records[start], i - start, &m_records[amount++]);
        i--;
    }
    fill_m_record(y, 0, records, size, &m_records[amount++]); // добавляем элемент, по которому в дальнейшем будем выводить
    return amount;                                            // информацию за весь год
}

// Конструктор для data
void fill_data(unsigned year, unsigned month, unsigned day, unsigned hour, unsigned minute, int temperature, data *record)
{
    record->year = year;
    record->month = month;
    record->day = day;
    record->hour = hour;
    record->temperature = temperature;
}

// Проводим валидацию для данных для data
int validate_data(unsigned year, unsigned month, unsigned day, unsigned hour, unsigned minute, int temperature, int string_number)
{
    char error[60];
    if (month == 0 || month > 12 || day == 0 || day > 31 || hour > 23 || minute > 59 || temperature > 99 || temperature < -99)
    {
        sprintf(error, "Invalid data in string %d", string_number);
        print(error);
        return 0;
    }
    else
    {
        return 1;
    }
}

// Заполняем массив data
int input(char *fileName, data *records)
{
    FILE *in = fopen(fileName, "r");
    if (in == NULL)
    {
        printf("Can't open file");
        return -1;
    }
    unsigned year, month, day, hour, minute;
    int temperature, string_amount = 0, record_amount = 0;
    char c;
    char str[100];
    while (!feof(in))
    {
        int correct = fscanf(in, "%u;%u;%u;%u;%u;%d", &year, &month, &day, &hour, &minute, &temperature);
        if (correct < 6 || validate_data(year, month, day, hour, minute, temperature, string_amount) == 0)
        {
            fgets(str, 100, in);
        }
        else
        {
            fill_data(year, month, day, hour, minute, temperature, &records[record_amount++]);
        }
        string_amount++;
    }
    fclose(in);
    return record_amount;
}

// По структуре month_record формируем в виде строки статистику и возвращаем её
char *get_info_by_month(month_records *m_records, char *info)
{
    data *pdata = m_records->start;
    int temp = pdata->temperature;
    int min, max, sum;
    min = max = sum = temp;
    for (int i = 1; i < m_records->size; i++) // начинаем с единицы, потому что первое значение мы учли при инициализации переменных min, max, average
    {
        temp = (++pdata)->temperature;
        max = max > temp ? max : temp;
        min = min < temp ? min : temp;
        sum += temp;
    }
    int average = sum / m_records->size;
    sprintf(info, "%d %10s  min %3d   max %3d   average: %3d", m_records->year, months[m_records->month], min, max, average);
    return info;
}

// Все функции возвращают строку, которую мы печатаем отдельной функцией print
// Таким образом мы можем легко изменить вывод в консоль на запись в файл и т.д.
void print(char *string)
{
    printf("%s\n", string);
}

// Выводид информацию по месяцам или за конкретный месяц
void get_statistic(unsigned month, month_records *m_records, int m_records_size)
{
    char info[100] = {0};
    if (month != 0)
    {
        for (int i = 0; i < m_records_size; i++)
        {
            if (m_records[i].month == month)
            {
                print(get_info_by_month(&m_records[i], info));
                return;
            }
        }
        sprintf(info, "There is no information about %s", months[month]); // Обрабатываем случай, когда нет записей за нужный месяц
        print(info);
    }
    else
    {
        for (int i = 0; i < m_records_size; i++)
        {
            print(get_info_by_month(&m_records[i], info));
        }
    }
}

void print_help()
{
    char help[150];
    print("-h List of keys, which you can use in this app");
    print("-f <filename.csv> input file name for getting date");
    print("-m <number of month> if this key is present, app will show information about only whis month");
}