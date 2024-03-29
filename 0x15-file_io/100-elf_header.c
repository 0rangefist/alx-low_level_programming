#include "main.h"
#include <stdio.h>


/**
 * get_system_endianness - Function that returns the endianness
 * of a system
 *
 * Return: 1 if little endian, 2 if big endian.
 * This matches the values of EI_DATA of an elf header
 * for little and big endianness.
 */
int get_system_endianness(void)
{
	/* we create a short int which is 2 bytes long */
	short int num = 1;

	/* on a big endian system,    num is stored as 00000000 00000001 */
	/* on a little endian system, num is stored as 00000001 00000000 */

	/* we cast it into a 1 byte char*/
	char *num_ptr = (char *) &num;

	/* on a big endian system, the casted value takes */
	/* the MSB which will be 0 (00000000)*/
	/* on a little endian system, the casted value takes */
	/* the  LSB which will be (00000001)*/

	if (*num_ptr == 1) /*little endian*/
		return (1);
	else /* big endian */
		return (2);
}

/**
 * swap_byte_order_16 - Swaps the byte order of a 16-bit number
 *
 * @value: The 16-bit number to swap the byte order of
 *
 * Return: The 16-bit number with the byte order swapped
 */
uint16_t swap_byte_order_16(uint16_t value)
{
	return ((value >> 8) | (value << 8));
}

/**
 * swap_byte_order_32 - Swaps the byte order of a 32-bit number
 *
 * @value: The 32-bit number to swap the byte order of
 *
 * Return: The 32-bit number with the byte order swapped
 */
uint32_t swap_byte_order_32(uint32_t value)
{
	value = ((value & 0x000000ff) << 24) | ((value & 0x0000ff00) << 8)
			| ((value & 0x00ff0000) >> 8) | ((value & 0xff000000) >> 24);

	return (value);
}

/**
 * swap_byte_order_64 - Swaps the byte order of a 64-bit number
 *
 * @value: The 64-bit number to swap the byte order of
 *
 * Return: The 64-bit number with the byte order swapped
 */
uint64_t swap_byte_order_64(uint64_t value)
{
	value = ((value & 0x00000000000000ff) << 56)
			| ((value & 0x000000000000ff00) << 40)
			| ((value & 0x0000000000ff0000) << 24)
			| ((value & 0x00000000ff000000) << 8)
			| ((value & 0x000000ff00000000) >> 8)
			| ((value & 0x0000ff0000000000) >> 24)
			| ((value & 0x00ff000000000000) >> 40)
			| ((value & 0xff00000000000000) >> 56);

	return (value);
}

/**
 * print_error - prints error messages to stderr and exits
 * with status 98
 *
 * @elf_fd: the file descriptor for the ELF file
 * @error_type: the type of error that occurred (READ_ERROR,
 *              NOT_ELF_ERROR or BAD_ELF_ERROR)
 * @bytes_read: the number of bytes read from the ELF file
 *
 * This function takes in a file descriptor for an ELF file,
 * an error type, and the number of bytes read from the file
 * (if applicable) and prints an error message to stderr based
 * on the error type, closes the file descriptor and exits with
 * status 98. If there is no match, the function does nothing.
 */
void print_error(int elf_fd, int error_type, int bytes_read)
{
	if (error_type == READ_ERROR && bytes_read == -1)
	{
		dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
		close(elf_fd);
		exit(98);
	}

	if (error_type == NOT_ELF_ERROR)
	{
		dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
		close(elf_fd);
		exit(98);
	}

	if (error_type == BAD_ELF_ERROR)
	{
		dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
		close(elf_fd);
		exit(98);
	}
}

/**
 * read_elf32_header - Reads the ELF header for a 32-bit ELF file.
 *
 * @elf_fd: The file descriptor of the ELF file.
 *
 * Return: The ELF header for the 32-bit ELF file.
 */
elf32_t read_elf32_header(int elf_fd)
{
	int		bytes_read; /* num of bytes read from elf file */
	elf32_t header32;	/* elf header for 32 bit elf */

	/*reset file offset to beginning of the file*/
	lseek(elf_fd, 0, SEEK_SET);

	/* read 32 bit elf file header */
	bytes_read = read(elf_fd, &header32, sizeof(header32));
	print_error(elf_fd, READ_ERROR, bytes_read);
	return (header32);
}

/**
 * read_elf64_header - Reads the ELF header for a 64-bit ELF file.
 *
 * @elf_fd: The file descriptor of the ELF file.
 *
 * Return: The ELF header for the 64-bit ELF file.
 */
elf64_t read_elf64_header(int elf_fd)
{
	int		bytes_read; /* num of bytes read from elf file */
	elf64_t header64;	/* elf header for 64 bit elf */

	/*reset file offset to beginning of the file*/
	lseek(elf_fd, 0, SEEK_SET);

	/* read 64 bit elf file header */
	bytes_read = read(elf_fd, &header64, sizeof(header64));
	print_error(elf_fd, READ_ERROR, bytes_read);

	return (header64);
}

/**
 * print_magic - prints the Magic number of an ELF
 *
 * @elf_ident: the e_ident field of the ELF
 *
 */
void print_magic(uint8_t *elf_ident)
{
	int i;

	printf("  Magic:   ");
	for (i = 0; i < 16; i++) /*loop over Magic number*/
	{
		printf("%02x", elf_ident[i]);
		if (i < 15) /*all indices*/
			printf(" ");
		else /*last index*/
			printf("\n");
	}
}

/**
 * print_class - prints the Magic number of an ELF
 *
 * @elf_class: the e_ident field of the ELF
 *
 */
void print_class(uint8_t elf_class)
{
	printf("  Class:                             ");
	if (elf_class == EI_CLASS_32)
	{
		printf("ELF32\n");
	}
	else if (elf_class == EI_CLASS_64)
	{
		printf("ELF64\n");
	}
	else if (elf_class == EI_CLASS_NONE)
	{
		printf("none\n");
	}
	else
	{
		printf("Unknown\n");
	}
}

/**
 * print_data - prints the EI_DATA field of an ELF
 *
 * @elf_data: theEI_DATA field of the ELF
 *
 */
void print_data(uint8_t elf_data)
{
	printf("  Data:                              ");
	if (elf_data == ELFDATA2LSB)
		printf("2's complement, little endian\n");
	else if (elf_data == ELFDATA2MSB)
		printf("2's complement, big endian\n");
}

/**
 * print_version - prints the EI_VERSION field of an ELF
 *
 * @elf_version: the EI_VERSION field of the ELF
 *
 */
void print_version(uint32_t elf_version)
{
	printf("  Version:                           %d", elf_version);
	if (elf_version == EV_CURRENT)
	{
		printf(" (current)\n");
	}
	else
	{
		printf("\n");
	}
}

/**
 * print_osabi - prints the EI_OSABI field of an ELF
 *
 * @elf_osabi: the EI_OSABI field of an ELF
 *
 */
void print_osabi(uint8_t elf_osabi)
{
	printf("  OS/ABI:                            ");
	if (elf_osabi == ELFOSABI_SYSV)
		printf("UNIX - System V\n");
	else if (elf_osabi == ELFOSABI_HPUX)
		printf("HP-UX\n");
	else if (elf_osabi == ELFOSABI_NETBSD)
		printf("UNIX - NetBSD\n");
	else if (elf_osabi == ELFOSABI_LINUX)
		printf("Linux\n");
	else if (elf_osabi == ELFOSABI_SOLARIS)
		printf("UNIX - Solaris\n");
	else if (elf_osabi == ELFOSABI_AIX)
		printf("AIX\n");
	else if (elf_osabi == ELFOSABI_IRIX)
		printf("IRIX\n");
	else if (elf_osabi == ELFOSABI_FREEBSD)
		printf("FreeBSD\n");
	else if (elf_osabi == ELFOSABI_ARM)
		printf("Compaq TRU64 UNIX\n");
	else if (elf_osabi == ELFOSABI_ARM)
		printf("ARM\n");
	else if (elf_osabi == ELFOSABI_STANDALONE)
		printf("UNIX - Standalone\n");
	else
		printf("<unknown: %x>\n", elf_osabi);
}

/**
 * print_abi_version - prints the EI_ABIVERSION field of an ELF
 *
 * @elf_abi_ver: the EI_ABIVERSION field of an ELF
 *
 */
void print_abi_version(uint8_t elf_abi_ver)
{
	printf("  ABI Version:                       %d\n", elf_abi_ver);
}

/**
 * print_type - prints the e_type field of an ELF
 *
 * @elf_type: tthe e_type field of an ELF
 *
 */
void print_type(uint16_t elf_type)
{
	printf("  Type:                              ");
	if (elf_type == ET_NONE)
		printf("NONE (No file type)\n");
	else if (elf_type == ET_REL)
		printf("REL (Relocatable file)\n");
	else if (elf_type == ET_EXEC)
		printf("EXEC (Executable file)\n");
	else if (elf_type == ET_DYN)
		printf("DYN (Shared object file)\n");
	else if (elf_type == ET_CORE)
		printf("CORE (Core file)\n");
	else
		printf("%x (Unknown type)\n", elf_type);
}

/**
 * print_elf32_header - prints a 32 bit ELF file header
 *
 * @header32: 32-bit ELF file header
 *
 */
void print_elf32_header(elf32_t header32)
{
	/* compare endianness of system to elf file. */
	/* if different, peform byte swaps on muti-byte fields */
	if (get_system_endianness() != header32.ident[EI_DATA])
	{
		header32.version = swap_byte_order_32(header32.version);
		header32.type	 = swap_byte_order_16(header32.type);
		header32.entry	 = swap_byte_order_32(header32.entry);
	}
	printf("ELF Header:\n");
	print_magic(header32.ident);
	print_class(header32.ident[EI_CLASS]);
	print_data(header32.ident[EI_DATA]);
	print_version(header32.version);
	print_osabi(header32.ident[EI_OSABI]);
	print_abi_version(header32.ident[EI_ABIVERSION]);
	print_type(header32.type);
	printf("  Entry point address:               %#x\n", header32.entry);
}

/**
 * print_elf64_header - prints a 64 bit ELF file header
 *
 * @header64: 64-bit ELF file header
 *
 */
void print_elf64_header(elf64_t header64)
{
	/* compare endianness of system to elf file. */
	/* if different, peform byte swaps on muti-byte fields */
	if (get_system_endianness() != header64.ident[EI_DATA])
	{
		header64.version = swap_byte_order_32(header64.version);
		header64.type	 = swap_byte_order_16(header64.type);
		header64.entry	 = swap_byte_order_64(header64.entry);
	}
	printf("ELF Header:\n");
	print_magic(header64.ident);
	print_class(header64.ident[EI_CLASS]);
	print_data(header64.ident[EI_DATA]);
	print_version(header64.version);
	print_osabi(header64.ident[EI_OSABI]);
	print_abi_version(header64.ident[EI_ABIVERSION]);
	print_type(header64.type);
	printf("  Entry point address:               %#lx\n", header64.entry);
}

/**
 * main - A program that displays some info in the header
 * of an ELF file
 *
 * @argc: The number of command-line arguments.
 * @argv: Array of command-line arguments. Arg 1 is the ELF filename.
 *
 * Return: 0 on success. -1, otherwise
 */
int main(int argc, char *argv[])
{
	int		elf_fd;		 /* the elf file descriptor */
	int		bytes_read;	 /* num of bytes read from elf file */
	uint8_t e_ident[16]; /* elf ident to determine 32 or 64 bit elf*/
	elf32_t header32;	 /* elf header for 32 bit elf */
	elf64_t header64;	 /* elf header for 64 bit elf */

	/* Check for correct number of arguments */
	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: elf_header elf_filename\n");
		exit(98);
	}
	/* open the elf file */
	elf_fd = open(argv[1], O_RDONLY);
	/* read the first 16bytes of elf file header into e_ident */
	bytes_read = read(elf_fd, e_ident, sizeof(e_ident));
	print_error(elf_fd, READ_ERROR, bytes_read);

	/* Use e_ident to check if the file is truely an ELF file */
	/* read the first 4 bytes of e_ident to determine if ELF file */
	if (e_ident[EI_MAG0] != 0x7f || e_ident[EI_MAG1] != 'E'
		|| e_ident[EI_MAG2] != 'L' || e_ident[EI_MAG3] != 'F')
		print_error(elf_fd, NOT_ELF_ERROR, 0); /* not an ELF file */
	/*check if elf is 32/64 bit then read & print into correct file type*/
	if (e_ident[EI_CLASS] == EI_CLASS_32)
	{
		header32 = read_elf32_header(elf_fd); /*read 32bit elf header*/
		print_elf32_header(header32);		  /*print 32bit elf header*/
	}
	else if (e_ident[EI_CLASS] == EI_CLASS_64)
	{
		header64 = read_elf64_header(elf_fd); /*read 64bit elf header*/
		print_elf64_header(header64);		  /*print 64bit elf file*/
	}
	else
		print_error(elf_fd, BAD_ELF_ERROR, 0); /*uknown elf class*/
	/* close the elf file descriptor */
	close(elf_fd);
	return (0);
}
