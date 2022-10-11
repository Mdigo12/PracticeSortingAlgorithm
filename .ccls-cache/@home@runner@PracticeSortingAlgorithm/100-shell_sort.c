#include "sort.h"

/**
shell_sort - sorts an array of integers in ascending order using the Shell sort algorithm, using the Knuth sequence

Desc: a.k.a the Knuth sequence
n+1 = n * 3 + 1
1, 4, 13, 40, 121, ...

@array: An array to be sorted 
@size: No of elements in an array

Return - Void
*/

void shell_sort(int *array, size_t size)
{
  int gap, n, i, j;

  n = n * 3 + 1;
  for (gap = (n * 3 + 1); gap >= 1; gap = gap / 2)
    {
      for (j = gap; j < size; j++)
        {
          for (i = j - gap; i >= 0; i = i - gap)
            {
              if (array[i + gap] > array[i])
                break;
              else
              {
                int temp = array[i + gap];
                array[i + gap] = array[i];
                array[i] = temp;
                print_array(array, size);
              }
            }
        }
    }
}