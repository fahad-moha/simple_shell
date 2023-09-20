#include "shell.c"

/**
 * _realloc - Reallocates a memory block using malloc and free
 * @ptr: Pointer to the previously allocated memory block
 * @old_size: Previous size of the memory block
 * @new_size: New size of the mk
 *
 * Return: Pointer to the reallocated memory block
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *result;

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	result = malloc(new_size);
	if (result == NULL)
		return (NULL);

	if (ptr != NULL)
	{
		_memcpy(result, ptr, (old_size < new_size) ?
				old_size : new_size);
		free(ptr);
	}

	return (result);
}
