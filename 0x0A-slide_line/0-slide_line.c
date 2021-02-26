#include "slide_line.h"


/**
 * slide_line - a function that slides and merges an array of integers
 * @line: line
 * @size: size
 * @direction: direction
 * Return: 1 upon success, or 0 upon failure
 **/
int slide_line(int *line, size_t size, int direction)
{
	if (!line || size < 1)
		return (0);
	if (direction == SLIDE_LEFT)
	{
		left_d(line, size);
		left_s(line, size);
		left_d(line, size);
	}
	else if (direction == SLIDE_RIGHT)
	{
		right_d(line, size);
		right_s(line, size);
		right_d(line, size);
	}
	return (1);
	(void)line;
	(void)size;
	(void)direction;
}

/**
 * right_s- function combines right
 * @line: pointer to array
 * @size: elements in array
 * Return: void
 */
int right_s(int *line, size_t size)
{
	ssize_t r = 0, merge = 0;

	for (r = size - 2; r >= 0; r--)
	{
		if (line[r] == line[r + 1])
		{
			merge++;
			line[r + 1] *= 2;
			line[r] = 0;
		}
	}
	return (1);
}

/**
 * left_s- function combines left
 * @line: pointer to array of
 * @size: elements contained in array
 * Return: void
 */
int left_s(int *line, size_t size)
{
	size_t left = 0, merge = 0;

	for (left = 1; left < size; left++)
	{
		if (line[left] == line[left - 1])
		{
			merge++;
			line[left - 1] *= 2;
			line[left] = 0;
		}
	}
	return (1);
}

/**
 * left_d- slides left
 * @line: pointer to array
 * @size: elements in array
 * Return: void
 */
int left_d(int *line, size_t size)
{
	size_t left = 0, zero = 0;

	for  (left = 0; left < size; left++)
	{
		if (!line[left])
			zero++;
		else if (zero)
			line[left - zero] = line[left];
	}
	for (left = size - zero; left < size; left++)
		line[left] = 0;
	return (1);
}

/**
 * right_d- slides right
 * @line: pointer to array
 * @size: elements in array
 * Return: void
 */
int right_d(int *line, size_t size)
{
	ssize_t right = 0, zero = 0;

	for  (right = size - 1; right >= 0; right--)
	{
		if (!line[right])
			zero++;
		else if (zero)
			line[right + zero] = line[right];
	}
	for (right = zero - 1; right >= 0; right--)
		line[right] = 0;
	return (1);
}
