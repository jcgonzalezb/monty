#include "monty.h"

int main(int argc, char **argv)
{
	char **args = NULL;
	char *line_buf = NULL;
	size_t line_buf_size = 0;
	int line_count = 0;
	ssize_t line_size;
	FILE *fp = fopen(argv[1], "r");
	void (*selector)();

	line_size = getline(&line_buf, &line_buf_size, fp);

	while (line_size >= 0)
	{
		line_count++;
		/*printf("line count [%06d]\n", line_count);*/
		/*printf("%s\n", line_buf);*/
		args = tokenization(line_buf);
		/*if (args[0] == NULL)*/
		/*{*/
		/*	free(args);*/
		/*	free(line_buf);*/
		/*	continue;*/
		/*}*/
		/*printf("%s\n", *args);*/
		selector = selectf(args);
		if (selector != NULL)
		{
			selector();

		}
		/*line_size: Size of every line*/
		/*line_buf: Data in every line*/
		/*printf("%ld\n", line_size);*/
		/* Get the next line */
		line_size = getline(&line_buf, &line_buf_size, fp);
	}
	free(line_buf);
	line_buf = NULL;

	fclose(fp);

	return (EXIT_SUCCESS);
}
