﻿// ВАРИАНТ 7 - Банковские операции
// Маслов Евгений Александрович

#include <iostream>
#include <iomanip>

using namespace std;

#include "bank_operations.h"
#include "file_reader.h"
#include "constants.h"
#include "filter.h"


void output(bank_operation* operation)
{
    /********** вывод даты **********/
    cout << "**************************** \n* Дата: ";
    cout << operation->date.day << '.';
    cout << operation->date.month << '.';
    cout << operation->date.year << '\n';
    /********** вывод времени **********/
    cout << "* " << "Время: ";
    cout << operation->time.day << ':';
    cout << operation->time.month << ':';
    cout << operation->time.year << '\n';
    /********** вывод вида операции **********/
    cout << "* Операция: ";
    cout << operation->account.form << '\n';
    /********** вывод счёта **********/
    cout << "* Номер счёта: ";
    cout << operation->account.inv << '\n';
    /********** вывод суммы операции **********/
    cout << "* Сумма операции: ";
    cout << operation->sum << '\n';
    /********** вывод назначения **********/
    cout << "* Назначение: ";
    cout << operation->aim << '\n';
    cout << "\n";
}

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Laboratory work #1. GIT\n";
    cout << "Variant #7. Bank Operations\n";
    cout << "Author: Maslov Eugene\n";
    cout << "Group: 24PInzh1z\n";
    bank_operation* operations[MAX_FILE_ROWS_COUNT];
    int size;
    try
    {
        read("data.txt", operations, size);
        cout << "*****   *****\n\n";
        for (int i = 0; i < size; i++)
        {
            //output(operations[i]);
        }
        bool (*check_function)(bank_operation*) = NULL; // check_function -    ,    bool,
                                                           //        book_subscription*
        cout << "\nВыберите действия :\n";
        cout << "1) Все операции \"Приход\"\n";
        cout << "2) Все операции за ноябрь 2021 \n";
        cout << "3) Comming soon... \n";
        cout << "\nВаше действие: ";
        int item;
        cin >> item;
        cout << '\n';
        switch (item)
        {
        case 1:
            check_function = check_bank_operations_coming; //       
            cout << "***** Все операции \"Приход\" *****\n\n";
            break;
        case 2:
            check_function = check_bank_operation_november_2021; //       
            cout << "***** Все операции за ноябрь 2021 *****\n\n";
            break;
        case 3:
        {
            //COMMING SOON
            break;
        }
        default:
            throw "  ";
        }
        if (check_function)
        {
            int new_size;
            bank_operation** filtered = filter(operations, size, check_function, new_size);
            for (int i = 0; i < new_size; i++)
            {
                output(filtered[i]);
            }
            delete[] filtered;
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
