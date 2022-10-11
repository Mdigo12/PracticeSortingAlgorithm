#include "sort.h"

/**
 * quick_sort - function that sorts an array of integers
 *              in ascending order using the Quick sort algorithm
 * @array: array
 * @size: array's size
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
  int lb, ub;
  lb = 0;
  ub = size - 1;
	if (array == NULL || size < 2)
		return;

	quick_s(array, lb, ub, size);
}

/**
 * partition - partition
 * @array: array
 * @lo: lower
 * @hi: higher
 * @size: array's size
 * Return: i
 */
int partition(int *array, int lb, int ub, size_t size)
{
	// int i = lo - 1, j = lo;
	// int pivot = array[hi], 
  int aux;
  int start = ub;
  int end = lb;

  int pivot = array[ub];

	while (end < start)
    {
      while(array[end] < pivot)
        end++;
      while(array[start] >= pivot)
        start--;
      if(end < start)
      {
        aux = array[end];
        array[end] = array[start];
        array[start] = aux;
        print_array(array, size);
      }
    }
  aux = array[end];
  array[end] = array[ub];
  array[ub] = aux;
  print_array(array, size);
  return end;
}

/**
 * quick_s - quick sort
 * @array: given array
 * @lo: lower
 * @hi:higher
 * @size: array's size
 * Return: void
 */
void quick_s(int *array, int lb, int ub, size_t size)
{
	int end_pos;

	if (lb < ub)
	{
		end_pos = partition(array, lb, ub, size);
		quick_s(array, lb, end_pos - 1, size);
		quick_s(array, end_pos + 1, ub, size);
	}
}