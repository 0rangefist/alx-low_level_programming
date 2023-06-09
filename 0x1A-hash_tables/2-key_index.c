#include "hash_tables.h"

/**
 * key_index - Calculates the index of a key in a hash table
 * @key: The key to calculate the index for
 * @size: The size of the hash table
 *
 * Return: The index of the key in the hash table
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int index;

	index = hash_djb2(key) % size;
	return (index);
}
