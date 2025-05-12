// ВАРИАНТ 7 - Банковские операции
// Маслов Евгений Александрович

#include <iostream>

using namespace std;

#include "bank_operations.h"
#include "file_reader.h"
#include "constants.h"

int main()
{
    cout << "Laboratory work #1. GIT\n";
    cout << "Variant #7. Bank Operations\n";
    cout << "Author: Maslov Eugene\n";
    cout << "Group: 24PInzh1z\n";
    bank_operation* operations[MAX_FILE_ROWS_COUNT];
    int size;
    try
    {
        read("data.txt", operations, size);
        cout << "***** Банковские операции *****\n\n";
        for (int i = 0; i < size; i++)
        {
            /********** вывод даты **********/
            cout << "**************************** \n* Дата: ";
            cout << operations[i]->date.day << '.';
            cout << operations[i]->date.month << '.';
            cout << operations[i]->date.year << '\n';
            /********** вывод времени **********/
            cout << "* " << "Время: ";
            cout << operations[i]->time.day << ':';
            cout << operations[i]->time.month << ':';
            cout << operations[i]->time.year << '\n';
            /********** вывод вида операции **********/
            cout << "* Операция: ";
            cout << operations[i]->account.form << '\n';
            /********** вывод счёта **********/
            cout << "* Номер счёта: ";
            cout << operations[i]->account.inv << '\n';
            /********** вывод суммы операции **********/
            cout << "* Сумма операции: ";
            cout << operations[i]->sum << '\n';
            /********** вывод назначения **********/
            cout << "* Назначение: ";
            cout << operations[i]->aim << '\n';
            cout << "\n";
        }
        cout << "**************************** \n";
        for (int i = 0; i < size; i++)
        {
            delete operations[i];
        }
    }
    catch (const char* error)
    {
        cout << error << '\n';
    }
}
