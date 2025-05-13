#ifndef SORTER_H
#define SORTER_H

#include "bank_operations.h"

bank_operation** sort(bank_operation* array[], int size, bank_operation** (*check)(bank_operation* operations[], int size, int criteria), int criteria);

bank_operation** sort_bubble(bank_operation** array, int size, int criteria);

void quick_sort_helper(bank_operation** array, int low, int high, int criteria);

bank_operation** sort_quick(bank_operation* array[], int size, int criteria);

#endif