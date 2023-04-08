#include "main.h"

/**
 * create_file - Creates a file
 *
 * @filename: Name of the file to be created
 * @text_content: String of content to be written to file
 *
 * Return: 1 on success or -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int fildes;			 /* file descriptor of file to create */
	int oflags;			 /* open flags to use for the file*/
	int num_of_char = 0; /* num of chars to write to file */
	int bytes_written;	 /* the num of bytes successfully written */

	if (!filename) /*if filename is a NULL pointer */
		return (-1);
	if (!text_content) /*if text_content is NULL the string is empty */
		text_content = "";

	/* create a new file or truncate if it already exists */
	oflags = O_CREAT | O_WRONLY | O_TRUNC;
	fildes = open(filename, oflags, 0600); /* chmod 600 rw------- permission */
	if (fildes == -1)					   /* if open fails */
		return (-1);

	/* determine the num of chars of text_content to write */
	while (text_content[num_of_char] != '\0')
		num_of_char++;

	/* write text_content into the file */
	bytes_written = write(fildes, text_content, num_of_char);
	if (bytes_written == -1) /* write failure */
		return (-1);

	close(fildes); /* close the file */

	return (1); /* successfully created & written to file */
}
