/**
 * helpers.c
 *
 * CS50 AP
 * Problem 3-6
 *
 * Helper functions.
 */
       
#include <cs50.h>

#include "helpers.h"

void binary(int value, int values[], int min, int max);
int returned;
/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    int min = 0;
    int max = n;
    binary(value, values, min, max);
    if (returned == value)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void binary(int value, int values[], int min, int max)
{
    if (max < min)
    {
        returned = -1;
    }
    else
    {
        int middle = (max + min) / 2;
        if (values[middle] < value)
        {
            binary(value, values, middle + 1, max);
        }
        else if (values[middle] > value)
        {
            binary(value, values, min, middle - 1);
        }
        else
        {
            returned = values[middle];
        }
    }
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // selection sort algorithm from my "race.c"
    int insert;
    int checker;
    // for each element of the array, looks at the value of
    // the element, and checks where it should belong in
    // the solved portion of the array.
    for (int i = 1; i < n; i++)
    {
        insert = values[i];
        checker = i;
        /** ensures that the first element of the array is the
         * first value in the solved portion of the array. then,
         * moves each piece over one to the right in the solved
         * portion to make room for the element being sorted.
         * finally, inserts the piece into the sorted portion
         * of the array.
         */
        while (checker > 0 && values[checker - 1] > insert)
        {
            // moves a piece in the sorted portion of the
            // array to the right to make room for element
            // being sorted.
            values[checker] = values[checker - 1];
            checker--;
        }
        // inserts value into solved portion of array.
        values[checker] = insert;
    }
}