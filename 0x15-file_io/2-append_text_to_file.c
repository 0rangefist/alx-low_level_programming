#include "main.h"

/**
 * append_text_to_file - Appends text to end of a file
 *
 * @filename: Name of the file to be appended to
 * @text_content: String to be appended to file
 *
 * Return: 1 on success or -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fildes;			 /* file descriptor of file to create */
	int oflags;			 /* open flags to use for the file*/
	int num_of_char = 0; /* num of chars to write to file */
	int bytes_written;	 /* the num of bytes successfully written */

	if (!filename) /*if filename is a NULL pointer */
		return (-1);
	if (!text_content) /*if text_content is NULL the string is empty */
		return (1);	   /* nothing added to the file */

	/* create a new file for appending if it exists */
	oflags = O_WRONLY | O_APPEND;
	fildes = open(filename, oflags);
	if (fildes == -1) /* if append fails (file doesn't exist) */
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
