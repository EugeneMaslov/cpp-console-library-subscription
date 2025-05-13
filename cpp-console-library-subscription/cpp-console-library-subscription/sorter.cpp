#include "sorter.h"

bank_operation** sort(bank_operation* array[], int size, bank_operation** (*check)(bank_operation* operations[], int size, int criteria), int criteria)
{
    return check(array, size, criteria);
}

bank_operation** sort_bubble(bank_operation** array, int size, int criteria)
{
    if (criteria == 1)
    {
        for (int i = 0; i < size - 1; ++i) {
            for (int j = 0; j < size - i - 1; ++j) {
                if (array[j]->aim > array[j + 1]->aim) {
                    // Меняем местами
                    bank_operation* temp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = temp;
                }
            }
        }
    }
    else if (criteria == 2)
    {
        bool should_swap;
        for (int i = 0; i < size - 1; ++i) {
            for (int j = 0; j < size - i - 1; ++j) {
                bool should_swap = false;

                if (array[j]->account.form != array[j + 1]->account.form) {
                    should_swap = array[j]->account.form > array[j + 1]->account.form;
                }
                else if (array[j]->aim != array[j + 1]->aim) {
                    should_swap = array[j]->aim > array[j + 1]->aim;
                }
                else {
                    should_swap = array[j]->sum > array[j + 1]->sum;
                }

                if (should_swap) {
                    // Меняем местами
                    bank_operation* temp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = temp;
                }
            }
        }
    }
    else
    {
        for (int i = 0; i < size - 1; ++i) {
            for (int j = 0; j < size - i - 1; ++j) {
                if (array[j]->sum > array[j + 1]->sum) {
                    // Меняем местами
                    bank_operation* temp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = temp;
                }
            }
        }
    }
    return array;
}

void quick_sort_helper(bank_operation** array, int low, int high, int criteria)
{
    if (low < high) {
        // Разделяем массив
        bank_operation* pivot = array[high]; // Опорный элемент
        int i = low - 1;
        bool should_swap;

        for (int j = low; j < high; ++j) {
            switch (criteria)
            {
            case 1:
            {   
                if (array[j]->aim <= pivot->aim) {
                    i++;
                    // Меняем местами
                    bank_operation* temp = array[i];
                    array[i] = array[j];
                    array[j] = temp;
                }
                break;
            }
            case 2:
            {
                if (array[j]->account.form != pivot->account.form) {
                    should_swap = array[j]->account.form > pivot->account.form;
                }
                else if (array[j]->aim != pivot->aim) {
                    should_swap = array[j]->aim > pivot->aim;
                }
                else {
                    should_swap = array[j]->sum > pivot->sum;
                }
                if (should_swap) {
                    i++;
                    // Меняем местами
                    bank_operation* temp = array[i];
                    array[i] = array[j];
                    array[j] = temp;
                }
                break;
            }
            default:
                if (array[j]->sum <= pivot->sum) {
                    i++;
                    // Меняем местами
                    bank_operation* temp = array[i];
                    array[i] = array[j];
                    array[j] = temp;
                }
                break;
            }
        }

        // Меняем местами опорный элемент
        bank_operation* temp = array[i + 1];
        array[i + 1] = array[high];
        array[high] = temp;

        int pivotIndex = i + 1;

        // Рекурсивно сортируем элементы до и после разделения
        quick_sort_helper(array, low, pivotIndex - 1, criteria);
        quick_sort_helper(array, pivotIndex + 1, high, criteria);
    }
}

bank_operation** sort_quick(bank_operation* array[], int size, int criteria)
{
    quick_sort_helper(array, 0, size - 1, criteria);
    return array;
}
