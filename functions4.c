#include "monty.h"

char *number;

/**
 * read_file - This function reads the file
 * @file_g: file.
 *
 * Return: void.
 */

void read_file(char *file_g)
{
	FILE *montyf;
	char *buffr = NULL, **cmd;
	size_t size = 0;
	ssize_t rt;
	int ptr, line = 0, i = 0;
	stack_t *lst = NULL;

	montyf = fopen(file_g, "r");
	if (montyf == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_g);
		exit(EXIT_FAILURE);
	}
	while ((rt = getline(&buffr, &size, montyf)) != EOF)
	{
		if (!buffr)
		{
			write(2, "Error: malloc failed\n", 21);
			fclose(montyf);
			exit(EXIT_FAILURE);
		} line += 1;
		if (rt == 1)
			continue;
		else
		{
			i = 0;
			while (buffr[i] == ' ' && buffr[i + 1] == ' ')
				i++;
			if (buffr[i + 1] == '\n')
				continue;
		}
		ptr = _mem(buffr);
		cmd = valid_buffr(buffr, ptr, montyf);
		_val(cmd, buffr, &lst, line, montyf);
		free(cmd);
	}
	free_stack(&lst);
	free(buffr);
	fclose(montyf);
}

/**
 * valid_buffr - Function tokenized the variable buffr in cmd
 * @buffr: is the variable storage in getline
 * @ptr: is the amount of words in the buffr
¨* @montyf: File
 *
 * Return: cmd is the tokenized of buffr
 */

char **valid_buffr(char *buffr, int ptr, FILE *montyf)
{
	char *delimit = " \n\t";
	char *tok;
	size_t i;
	char **cmd;

	cmd = malloc(sizeof(char *) * ptr);
	if (cmd == NULL)
	{
		write(2, "Error: malloc failed\n", 21);
		free(buffr);
		fclose(montyf);
		exit(EXIT_FAILURE);
	}
	tok = strtok(buffr, delimit);
	i = 0;
	while (tok)
	{
		cmd[i] = tok;
		tok = strtok(NULL, delimit);
		i++;
	}
	cmd[i] = NULL;
	return (cmd);
}

/**
 * _val - opcode validate the number of arguments in cmd
 * @cmd: is the tokenized of the string in getline
 * @buffr: is the string storared in getline
 * @lst: is the struct of the doubly linked list
 * @line: is the currently number line in the file
 * @a: File
 *
 * Return: void
 */

void _val(char **cmd, char *buffr, stack_t **lst, int line, FILE *a)
{
	int i = 0;

	while (cmd[i] != NULL)
		i++;
	if (!(i == 2 || i == 1))
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line, cmd[0]);
		free(cmd);
		free(buffr);
		free_stack(lst);
		fclose(a);
		exit(EXIT_FAILURE);
	}
	if (i == 2)
		number = cmd[1];
	_opcode(cmd, buffr, line, lst, a);
}

/**
 * _opcode - is the function that compare the word read in the file for
 * @cmd: is the tokenized of the string in getline
 * @buffr: is the string storared in getline
 * @lst: is the struct of the doubly linked list
 * @line: is the currently number line in the file
 * @m: File.
 *
 * Return: void
 */

void _opcode(char **cmd, char *buffr, int line, stack_t **lst, FILE *m)
{
	int j = 0;
	instruction_t opcodeFunc[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _mop},
		{"sub", _sub},
		{NULL, NULL},
	};
	while (opcodeFunc[j].opcode != NULL)
	{
		if (strcmp(opcodeFunc[j].opcode, cmd[0]) == 0)
		{
			opcodeFunc[j].f(lst, line);
			return;
		}
		j++;
	}
	if (opcodeFunc[j].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line, cmd[0]);
		free(cmd);
		free(buffr);
		free_stack(lst);
		fclose(m);
		exit(EXIT_FAILURE);
	}
}
