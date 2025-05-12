#ifndef FILTER_H
#define FILTER_H

#include "bank_operations.h"

bank_operation** filter(bank_operation* array[], int size, bool (*check)(bank_operation* element), int& result_size);

bool check_bank_operations_coming(bank_operation* element);

bool check_bank_operation_november_2021(bank_operation* element);

#endif
