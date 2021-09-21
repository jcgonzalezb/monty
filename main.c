#include "monty.h"
#define TOK_DELIM " \t\r\n\a\\$"

char **tokenization(char *line)
{
	char *token;
	int p = 0;
	char **tokens = malloc(sizeof(char *) * 1024);

	if (!tokens)
		exit(EXIT_SUCCESS);

	token = strtok(line, TOK_DELIM);

	while (token != NULL)
	{
		tokens[p] = token;
		p++;

		token = strtok(NULL, TOK_DELIM);
	}
	tokens[p] = NULL;
	return (tokens);
}

int (*selectf(char s))(va_list)
{
	int i = 0;

	order options[] = {
		{"Push", push},
		{"pall", pall},
		{NULL, NULL}
	};

	while (options[i].program != NULL)
	{
		if (strcmp(args[0], options[i].program) == 0)
		{
			return (options[i].f);
		}
		i++;
	}
	return (NULL);
}











int main(int argc, char **argv)
{
	char **args = NULL;
	char *line_buf = NULL;
	size_t line_buf_size = 0;
	int line_count = 0;
	ssize_t line_size;
	FILE *fp = fopen(argv[1], "r");
	void (*selector)(char **, char *);

	line_size = getline(&line_buf, &line_buf_size, fp);

	while (line_size >= 0)
	{
		line_count++;
		/*printf("line count [%06d]\n", line_count);*/
		/*printf("%s\n", line_buf);*/
		args = tokenization(line_buf);
		if (args[0] == NULL)
		{
			free(args);
			free(line_buf);
			continue;
		}
		selector = selectf(args);
		/*line_size: Size of every line*/
		/*line_buf: Data in every line*/
		/*printf("%ld\n", line_size);*/
		printf("%s\n", *args);
		/* Get the next line */
		line_size = getline(&line_buf, &line_buf_size, fp);
	}
	free(line_buf);
	line_buf = NULL;

	fclose(fp);

	return (EXIT_SUCCESS);
}
