#include "main.h"

/**
 * read_textfile - Reads a text file and prints it to the POSIX standard output
 *
 * @filename: Name of the file to be read
 * @letters: Number of letter bytes to read from file
 *
 * Return: number of chars printed to POSIX standard out on success
 * or 0 on failure
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char   *buffer;		   /* create a buffer to hold read values */
	ssize_t bytes_read;	   /*num of bytes read from file into buffer */
	ssize_t bytes_written; /* num of bytes written to stdout from buffer */
	int		fildes;		   /* file descriptor */

	if (!filename) /* filename is NULL ptr */
		return (0);

	fildes = open(filename, O_RDONLY); /* open file & save file descriptor*/

	buffer = malloc(letters); /* allocate memory for the buffer */
	if (!buffer)			  /* alloc failure */
	{
		close(fildes);
		return (0);
	}

	/* read 'letters' num of bytes from file into buffer */
	bytes_read = read(fildes, buffer, letters);
	if (bytes_read == -1) /* read failure */
	{
		free(buffer);
		close(fildes);
		return (0);
	}
	/* write the buffer to stdout */
	bytes_written = write(STDOUT_FILENO, buffer, bytes_read);
	if (bytes_written == -1) /* write failure */
	{
		free(buffer);
		close(fildes);
		return (0);
	}
	if (close(fildes) == -1) /*close file & check for failure*/
	{
		free(buffer);
		return (0);
	}
	free(buffer);
	return (bytes_written); /* succeeded printing from file to stdout */
}
