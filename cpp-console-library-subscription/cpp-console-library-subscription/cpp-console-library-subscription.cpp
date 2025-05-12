// ВАРИАНТ 7 - Банковские операции
// Маслов Евгений Александрович

#include <iostream>

using namespace std;

#include "bank_operations.h"
#include "file_reader.h"
#include "constants.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Лабораторная работа №1. GIT\n";
    cout << "Вариант №7. Банковские операции\n";
    cout << "Автор: Маслов Евгений\n\n";
    bank_operation* operations[MAX_FILE_ROWS_COUNT];
    int size;
    try
    {
        read("data.txt", operations, size);
        for (int i = 0; i < size; i++)
        {
            cout << operations[i]->date.day << '.';
            cout << operations[i]->date.month << '.';
            cout << operations[i]->date.year << '\n';
            cout << operations[i]->time.day << ':';
            cout << operations[i]->time.month << ':';
            cout << operations[i]->time.year << '\n';
            cout << operations[i]->account.form << '\n';
            cout << operations[i]->account.inv << '\n';
            cout << operations[i]->sum << '\n';
            cout << operations[i]->aim << '\n';
            cout << '\n';
        }
        for (int i = 0; i < size; i++)
        {
            delete operations[i];
        }
    }
    catch (const char* error)
    {
        cout << error << '\n';
    }
    return 0;
}
