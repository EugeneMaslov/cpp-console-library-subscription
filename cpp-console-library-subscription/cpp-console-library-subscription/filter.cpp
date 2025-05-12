#include "filter.h"
#include <cstring>
#include <iostream>
#include <string>

bank_operation** filter(bank_operation* array[], int size, bool(*check)(bank_operation* element), int& result_size)
{
	bank_operation** result = new bank_operation * [size];
	result_size = 0;
	for (int i = 0; i < size; i++)
	{
		if (check(array[i]))
		{
			result[result_size++] = array[i];
		}
	}
	return result;
}

bool check_bank_operations_coming(bank_operation* element)
{
	return std::string(element->account.form) == "приход";
}

bool check_bank_operation_november_2021(bank_operation* element)
{
	return element->date.month == 11 && element->date.year == 21;
}
