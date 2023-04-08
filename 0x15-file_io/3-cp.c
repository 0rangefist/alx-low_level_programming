#include "main.h"
#include <stdio.h>

/**
 * open_files - Opens the source and destination files for copying
 *
 * @argv: Array of arguments containing source and destination file names
 * @source_fd: Pointer to an integer to store the source file descriptor
 * @dest_fd: Pointer to an integer to store the destination file descriptor
 *
 * This function opens the source and destination files for copying.
 * If the source file cannot be opened, the function prints an error message &
 * exits with code 98. If the destination file cannot be opened, the function
 * prints an error message, closes the source file, and exits with code 99.
 */
void open_files(char *argv[], int *source_fd, int *dest_fd)
{
	/* Open the source file */
	*source_fd = open(argv[1], O_RDONLY);
	if (*source_fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	/*Open the dest file, create or truncate if it already exists (rw-rw-r--)*/
	*dest_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (*dest_fd == -1) /* dest file open failure */
	{
		close(*source_fd);
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}
}

/**
 * copy_from_source_to_dest - Copies the contents of the source file to the
 * destination file
 *
 * @source_fd: The source file descriptor
 * @dest_fd: The destination file descriptor
 * @argv: Array of arguments containing source and destination file names
 *
 * This function reads from the source file and writes to the destination file.
 * If there is a read error, the function prints an error message, closes both
 * files, and exits with code 98. If there is a write error, the function
 * prints an error message, closes both files, and exits with code 99.
 */
void copy_from_source_to_dest(int source_fd, int dest_fd, char *argv[])
{
	char buffer[1024];	/* buffer to read source to dest in 1024 byte chunks */
	int	 bytes_read;	/* num of bytes read from source file */
	int	 bytes_written; /* num of bytes written to dest file */

	/* Read from the source file and write to the destination file */
	/* This is done in chunks of 1024 bytes till bytes_read is <= 0 */
	do {
		/* read() continues from where it left off on subsequent calls */
		bytes_read = read(source_fd, buffer, 1024);
		if (bytes_read == -1) /* there was a read error */
		{
			close(source_fd);
			close(dest_fd);
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
			exit(98);
		}

		/* write() also continues from where it left off on subsequent call*/
		bytes_written = write(dest_fd, buffer, bytes_read);
		if (bytes_written != bytes_read) /*there was a write error */
		{
			close(source_fd);
			close(dest_fd);
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			exit(99);
		}
	} while (bytes_read > 0);
}

/**
 * close_files - Closes the source and destination files
 *
 * @source_fd: The source file descriptor
 * @dest_fd: The destination file descriptor
 *
 * This function closes the source and destination files.
 * If either file descriptor cannot be closed, the function prints an error
 * message and exits with code 100.
 */
void close_files(int source_fd, int dest_fd)
{
	/* Close the file descriptors */
	if (close(source_fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", source_fd);
		exit(100);
	}

	if (close(dest_fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", dest_fd);
		exit(100);
	}
}

/**
 * main - A program that copies the content of a file to another file.
 *
 * @argc: The number of command-line arguments.
 * @argv: Array of command-line arguments. Arg 1 is the source file name
 * & Arg 2 is the destination file name.
 *
 * Return: 0 on success. Otherwise, the appropriate error code
 * 97, 98, 99, or 100
 */
int main(int argc, char *argv[])
{
	int source_fd; /* the source file descriptor */
	int dest_fd;   /* the destination file descriptor */

	/* Check for correct number of arguments */
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	/* open the source & dest files & return their descriptors */
	open_files(argv, &source_fd, &dest_fd);

	/* read bytes from source & write to dest */
	copy_from_source_to_dest(source_fd, dest_fd, argv);

	/* close file descriptors */
	close_files(source_fd, dest_fd);

	return (0);
}
