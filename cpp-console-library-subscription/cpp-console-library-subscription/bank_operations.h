#ifndef BANK_OPERATIONS_H
#define BANK_OPERATIONS_H

#include "constants.h"

struct dateTime
{
    int day;
    int month;
    int year;
};

struct dataBank
{
    char form[MAX_STRING_SIZE];
    char inv[MAX_STRING_SIZE];
};

struct bank_operation
{
    dateTime date;
    dateTime time;
    dataBank account;
    double sum;
    char aim[MAX_STRING_SIZE];
};

#endif