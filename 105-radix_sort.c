
#include "sort.h"

int get_max(int *array, int size);
void radix(int *array, size_t size, int identifier, int *buff);
void radix_sort(int *array, size_t size);

/**
 * get_max - Max value of int array.
 * @array: int array.
 * @size: array size.
 * Return: The maximum integer in the array.
 */
int get_max(int *array, int size)
{
	int max, i;

	for (max = array[0], i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	return (max);
}

/**
 * radix - counting sort algorithm for identifiernificant digits
 * @array: array of integers.
 * @size: size of the array.
 * @identifier: identifier.
 * @buff:  buffer.
 */
void radix(int *array, size_t size, int identifier, int *buff)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t i;

	for (i = 0; i < size; i++)
		count[(array[i] / identifier) % 10] += 1;

	for (i = 0; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; (int)i >= 0; i--)
	{
		buff[count[(array[i] / identifier) % 10] - 1] = array[i];
		count[(array[i] / identifier) % 10] -= 1;
	}

	for (i = 0; i < size; i++)
		array[i] = buff[i];
}

/**
 * radix_sort -  radix sort algorithm for an array of integers in asc
 * @array: An array of integers.
 * @size: The size of the array.
 * Description:  LSD radix sort algorithm.
 */
void radix_sort(int *array, size_t size)
{
	int max, identifier, *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	max = get_max(array, size);
	for (identifier = 1; max / identifier > 0; identifier *= 10)
	{
		radix(array, size, identifier, buff);
		print_array(array, size);
	}

	free(buff);
}
