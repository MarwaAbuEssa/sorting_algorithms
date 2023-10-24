
#include "sort.h"

void conquer(int *subArray, int *buff, size_t right, size_t mid,
		size_t left);
void divide(int *subArray, int *buff, size_t right, size_t left);
void merge_sort(int *array, size_t size);

/**
 * conquer - subarray of integers.
 * @subArray: subArray.
 * @buff: buffer.
 * @right: right index.
 * @mid: middle index .
 * @left: left index.
 */
void conquer(int *subArray, int *buff, size_t right, size_t mid,
		size_t left)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(subArray + right, mid - right);

	printf("[right]: ");
	print_array(subArray + mid, left - mid);

	for (i = right, j = mid; i < mid && j < left; k++)
		buff[k] = (subArray[i] < subArray[j]) ? subArray[i++] : subArray[j++];
	for (; i < mid; i++)
		buff[k++] = subArray[i];
	for (; j < left; j++)
		buff[k++] = subArray[j];
	for (i = right, k = 0; i < left; i++)
		subArray[i] = buff[k++];

	printf("[Done]: ");
	print_array(subArray + right, left - right);
}

/**
 * divide - merge sort algorithm through recursion.
 * @subArray: subArray.
 * @buff:  buffer.
 * @right:  right index .
 * @left:  left index.
 */
void divide(int *subArray, int *buff, size_t right, size_t left)
{
	size_t mid;

	if (left - right > 1)
	{
		mid = right + (left - right) / 2;
		divide(subArray, buff, right, mid);
		divide(subArray, buff, mid, left);
		conquer(subArray, buff, right, mid, left);
	}
}

/**
 * merge_sort - merge sort algorithm for array of integers in asc
 * @array: int  array.
 * @size: array size.
 *
 * Description:  merge sort algorithm.
 */
void merge_sort(int *array, size_t size)
{
	int *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	divide(array, buff, 0, size);

	free(buff);
}
