#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>
#include <stdlib.h>

/**
 * display_elf_header - Displays the ELF header information
 * @elf_header: Pointer to the ELF header structure
 */
void display_elf_header(Elf64_Ehdr *elf_header)
{
	int i;

	printf("Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
		printf("%02x ", elf_header->e_ident[i]);
	printf("\n");

	printf("Class:                             %s\n",
		elf_header->e_ident[EI_CLASS] == ELFCLASS64 ? "ELF64" : "ELF32");
	printf("Data:                              %s\n",
	elf_header->e_ident[EI_DATA] == ELFDATA2LSB ?
	"2's complement, little endian" : "2's complement, big endian");
	printf("Version:                           %d %s\n",
		elf_header->e_ident[EI_VERSION], "(current)");
	printf("OS/ABI:                            %s\n",
		elf_header->e_ident[EI_OSABI] == ELFOSABI_NONE ?
		"UNIX - System V" : "Unknown");
	printf("ABI Version:                       %d\n",
		elf_header->e_ident[EI_ABIVERSION]);
	printf("Type:                              %s\n",
		elf_header->e_type == ET_EXEC ? "EXEC (Executable file)" : "Unknown");
	printf("Entry point address:               %p\n",
		(void *)elf_header->e_entry);
}

/**
 * main - Entry point
 * @argc: Number of command line arguments
 * @argv: Array of command line arguments
 * Return: 0 on success, 98 on failure
 */
int main(int argc, char **argv)
{
	int fd;
	Elf64_Ehdr elf_header;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
		exit(98);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		perror("open");
		exit(98);
	}

	if (read(fd, &elf_header, sizeof(elf_header)) != sizeof(elf_header))
	{
		perror("read");
		close(fd);
		exit(98);
	}

	if (elf_header.e_ident[EI_MAG0] != ELFMAG0 ||
		elf_header.e_ident[EI_MAG1] != ELFMAG1 ||
		elf_header.e_ident[EI_MAG2] != ELFMAG2 ||
		elf_header.e_ident[EI_MAG3] != ELFMAG3)
	{
		fprintf(stderr, "%s: Error: Not an ELF file\n", argv[0]);
		close(fd);
		exit(98);
	}

	display_elf_header(&elf_header);

	close(fd);
	return (0);
}
