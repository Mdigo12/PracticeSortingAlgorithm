#include <stdlib.h>
#include "sort.h"

/**
bubble_sort -  sorts an array of integers in ascending order using the Bubble sort algorithm

@array: An array to be sorted 
@size: No of elements in an array

Return - Void
*/

void bubble_sort(int *array, size_t size)
{
  int swap = 1;
  int n = size;
  int i, j;

  for(i = 0; i < n; i++)
    {
      for(j = 0; j < n - 1; j++)
        {
          if (array[j] > array[j + 1])
          {
            int temp = array[j];
            array[j] = array[j + 1];
            array[j + 1] = temp;
            print_array(array, size);
          }
        }
      
    }  
}