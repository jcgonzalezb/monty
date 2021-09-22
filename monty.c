#include "monty.h"

int monty(FILE *fp)
{
	char **args = NULL;
	char *line_buf = NULL;
	size_t line_buf_size = 0;
	int line_count = 0;
	ssize_t line_size;
	void (*selector)();
	int validator_function;

	line_size = getline(&line_buf, &line_buf_size, fp);

	while (line_size >= 0)
	{
		line_count++;
		args = tokenization(line_buf);
		if (args[0] == NULL)
		{
			free(args);
			free(line_buf);
			continue;
		}
		selector = selectf(args);
		if (selector != NULL)
		{
			selector();
		}
		line_size = getline(&line_buf, &line_buf_size, fp);
	}
	free(line_buf);
	line_buf = NULL;
}
