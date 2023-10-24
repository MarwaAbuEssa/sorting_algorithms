#include "sort.h"

void swap(int *a, int *b);
void heap_tree(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);

/**
 * swap - Swap two integers.
 * @a: first.
 * @b: second.
 */
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * heap_tree - a binary tree into a complete binary heap.
 * @array: array of a binary tree.
 * @size: size of the tree.
 * @base: index of the base row of tree.
 * @root: root node of the binary tree.
 */
void heap_tree(int *array, size_t size, size_t base, size_t root)
{
	size_t left, right, large;

	left = 2 * root + 1;
	right = 2 * root + 2;
	large = root;

	if (left < base && array[left] > array[large])
		large = left;
	if (right < base && array[right] > array[large])
		large = right;

	if (large != root)
	{
		swap(array + root, array + large);
		print_array(array, size);
		heap_tree(array, size, base, large);
	}
}

/**
 * heap_sort - heap sort algorithm for int array in asc
 * @array: integers array.
 * @size: array size
 * Description: sift-down heap sort algorithm.
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = (size / 2) - 1; i >= 0; i--)
		heap_tree(array, size, size, i);

	for (i = size - 1; i > 0; i--)
	{
		swap(array, array + i);
		print_array(array, size);
		heap_tree(array, size, i, 0);
	}
}
