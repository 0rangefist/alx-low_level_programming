#ifndef MAIN_H
#define MAIN_H

#include <fcntl.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * struct elf32_s - matches the data bytes of the first five fields
 * of a 32-bit ELF file header
 *
 * @ident: identification bytes
 * @type: object file type
 * @machine: machine architecture
 * @version: object file version
 * @entry: virtual address of the entry point
 *
 * This struct matches the byte layout of the ELF file header for a
 * 32-bit ELF file. It is used to store the header information read
 * from the ELF file.
 */
struct elf32_s
{
	uint8_t	 ident[16];
	uint16_t type;
	uint16_t machine;
	uint32_t version;
	uint32_t entry;
};

/**
 * struct elf64_s - matches the data bytes of the first five fields
 * of a 64-bit ELF file header
 *
 * @ident: identification bytes
 * @type: object file type
 * @machine: machine architecture
 * @version: object file version
 * @entry: virtual address of the entry point
 *
 * This struct matches the byte layout of the ELF file header for a
 * 64-bit ELF file. It is used to store the header information read
 * from the ELF file.
 */
struct elf64_s
{
	uint8_t	 ident[16];
	uint16_t type;
	uint16_t machine;
	uint32_t version;
	uint64_t entry;
};

/**
 * elf32_t - typedef for struct elf32_s
 */
typedef struct elf32_s elf32_t;

/**
 * elf64_t - typedef for struct elf64_s
 */
typedef struct elf64_s elf64_t;

/* index constants representing sub-fields of the e_ident field */
#define EI_MAG0 0		/* ELF identification byte 0 */
#define EI_MAG1 1		/* ELF identification byte 1 */
#define EI_MAG2 2		/* ELF identification byte 2 */
#define EI_MAG3 3		/* ELF identification byte 3 */
#define EI_CLASS 4		/* ELF class (32-bit or 64-bit) */
#define EI_DATA 5		/* ELF encoding (little-endian or big-endian) */
#define EI_VERSION 6	/* ELF version */
#define EI_OSABI 7		/* ELF Operating System ABI */
#define EI_ABIVERSION 8 /* ELF OSABI version */
#define EI_PAD 9		/* ELF Reserved padding bytes (to be ignored) */

/* values for EI_CLASS */
#define EI_CLASS_NONE 0
#define EI_CLASS_32 1
#define EI_CLASS_64 2

/* values for EI_DATA*/
#define ENDIAN_L 1 /* Little endianness */
#define ENDIAN_B 2 /* Big endianness */

/* values for EI_OSABI */
#define ELFOSABI_SYSV 0			/* UNIX System V ABI */
#define ELFOSABI_HPUX 1			/* HP-UX ABI */
#define ELFOSABI_NETBSD 2		/* NetBSD ABI */
#define ELFOSABI_LINUX 3		/* Linux ABI */
#define ELFOSABI_SOLARIS 6		/* Solaris ABI */
#define ELFOSABI_AIX 7			/* AIX ABI */
#define ELFOSABI_IRIX 8			/* IRIX ABI */
#define ELFOSABI_FREEBSD 9		/* FreeBSD ABI */
#define ELFOSABI_TRU64 10		/* Compaq TRU64 UNIX ABI */
#define ELFOSABI_ARM 97			/* ARM ABI */
#define ELFOSABI_STANDALONE 255 /* Standalone (embedded) application */

/* constants for e_type*/
#define ET_NONE 0 /* Unknown */
#define ET_REL 1  /* Relocatable file */
#define ET_EXEC 2 /* Executable file */
#define ET_DYN 3  /* Shared object */
#define ET_CORE 4 /* Core file */

/* constants representing various errors */
#define READ_ERROR 1
#define NOT_ELF_ERROR 2
#define BAD_ELF_ERROR 3

int		_putchar(char c);
ssize_t read_textfile(const char *filename, size_t letters);
int		create_file(const char *filename, char *text_content);
int		append_text_to_file(const char *filename, char *text_content);

#endif /*MAIN_H*/
