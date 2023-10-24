
#include "sort.h"

void swap(int *a, int *b);
void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
		char dir);
void bitonic(int *array, size_t size, size_t start, size_t seq, char dir);
void bitonic_sort(int *array, size_t size);

/**
 * swap - Swap two integers.
 * @a:  first .
 * @b:  second.
 */
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * bitonic_merge - bitonic sequence inside an array of integers.
 * @array: array of integers.
 * @size:  size array.
 * @start: starting index.
 * @seq: size of the sequence to sort.
 * @dir: direction to sort.
 */
void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
		char dir)
{
	size_t i, jump = seq / 2;

	if (seq > 1)
	{
		for (i = start; i < start + jump; i++)
		{
			if ((dir == UP && array[i] > array[i + jump]) ||
			    (dir == DOWN && array[i] < array[i + jump]))
				swap(array + i, array + i + jump);
		}
		bitonic_merge(array, size, start, jump, dir);
		bitonic_merge(array, size, start + jump, jump, dir);
	}
}

/**
 * bitonic - an array to a bitonic sequence.
 * @array: array of integers.
 * @size: size of the array.
 * @start: starting index
 * @seq: size of bitonic sequence.
 * @dir: direction to sort.
 */
void bitonic(int *array, size_t size, size_t start, size_t seq, char dir)
{
	size_t cut = seq / 2;
	char *str = (dir == UP) ? "UP" : "DOWN";

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);

		bitonic(array, size, start, cut, UP);
		bitonic(array, size, start + cut, cut, DOWN);
		bitonic_merge(array, size, start, seq, dir);

		printf("Result [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);
	}
}

/**
 * bitonic_sort - bitonic sort algorithm for array in asc
 * @array: int array.
 * @size: array size.
 * Description: bitonic sort algorithm 
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic(array, size, 0, size, UP);
}
