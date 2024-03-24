#include "temp_functions.h"
#define ARRAY_SIZE 527050 //   Предполагаем, что у нас данные строго за один год


int main(int argc, char *argv[])
{
    int res = 0;
    unsigned month = 0;
    opterr = 0;
    char * file_name;
    while ((res = getopt(argc, argv, "hf:m:")) != -1) {
        switch (res) {
            case 'h':
            print_help();
            return 0;
            case 'f':
            file_name = optarg;
            break;
            case 'm':
            month = atoi(optarg);
            break;
        }
    }

    data *records = (data *)malloc(ARRAY_SIZE * sizeof(data));
    int size = input(file_name, records);
    if (size == -1) {
        return 1;
    }

    month_records *m_records = (month_records *)malloc(MONTHS_RECORDS * sizeof(month_records));
    int m_records_size = group_records_by_months(records, size, m_records);
    get_statistic(month, m_records, m_records_size);
    return 0;
}