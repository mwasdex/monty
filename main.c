#include "monty.h"

/**
 * main - Start.
 * @argc: number of arguments
 * @argv: argument vector
 *
 * Return: 0
 */

int main(int argc, char *argv[])
{
	char *file_g;

	if (argc != 2)
	{
		write(2, "USAGE: monty file\n", 18);
		exit(EXIT_FAILURE);
	}
	file_g = argv[1];
	read_file(file_g);
	return (0);
}
