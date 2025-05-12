#include "file_reader.h"
#include "constants.h"

#include <fstream>
#include <cstring>

dateTime convert(char* str)
{
    dateTime result;
    char* context = NULL;
    char* str_number = strtok_s(str, ".", &context);
    result.day = atoi(str_number);
    str_number = strtok_s(NULL, ".", &context);
    result.month = atoi(str_number);
    str_number = strtok_s(NULL, ".", &context);
    result.year = atoi(str_number);
    return result;
}

dateTime convertTime(char* str)
{
    dateTime result;
    char* context = NULL;
    char* str_number = strtok_s(str, ":", &context);
    result.day = atoi(str_number);
    str_number = strtok_s(NULL, ":", &context);
    result.month = atoi(str_number);
    str_number = strtok_s(NULL, ":", &context);
    result.year = atoi(str_number);
    return result;
}

void read(const char* file_name, bank_operation* array[], int& size)
{
    std::ifstream file(file_name);
    if (file.is_open())
    {
        size = 0;
        char tmp_buffer[MAX_STRING_SIZE];
        while (!file.eof())
        {
            bank_operation* item = new bank_operation;
            file >> tmp_buffer;
            item->date = convert(tmp_buffer);
            file >> tmp_buffer;
            item->time = convertTime(tmp_buffer);
            file >> item->account.form;
            file >> item->account.inv;
            file >> item->sum;
            file.read(tmp_buffer, 1); // чтения лишнего символа пробела
            file.getline(item->aim, MAX_STRING_SIZE);
            array[size++] = item;
        }
        file.close();
    }
    else
    {
        throw "Ошибка открытия файла";
    }
}
