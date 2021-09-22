#ifndef MONTY_H
#define MONTY_H
#define TOK_DELIM " \t\r\n\a\\$"

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
/*typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;*/

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

typedef struct structur
{
	char *program;
	void (*f)(char **, char *);
} order;

char **tokenization(char *line);
stack_t push (stack_t **head, const int n);
void (*selectf(char **args))(char **args, char *line);
void (*selector)(char **, char *);
void argc_validator(int argc);
void _isdigit(char *args, int line_count);
void _push();
void pall();

#endif
