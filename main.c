#include "monty.h"
/**
 * main - Entry point
 * @argc: number of arguments passed by console.
 * @argv: list of arguments passed by console.
 * Return: EXIT_SUCCESS on success EXIT_FAILURE on error
 * main valida que los argumentos pasados por consola sean validos
 * si son validos pasa el archivo a la funcion monty, si no son
 * validos termina un el programa con un mensaje de error
*/
int main(int argc, char **argv)
{
	FILE *fp = NULL;
	/**
	 * argc_validator: Valida que se lean dos
	 * argumentos por consola
	 */
	argc_validator(argc);
	/**
	 * fopen recibe el argumento de la posicion 1
	 * y lo abre para lectura
	*/
	fp = fopen(argv[1], "r");
	/**
	 * se valida si el archivo es valido de lo contrario
	 * se muestra un error y se cierra el programa
	*/
	if(fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", fp);
		exit(EXIT_FAILURE);
	}
	/**
	 * la funcion monty continua con la ejecucion del programa
	 * recibe el archivo que ya fue abierto.
	*/
	monty(fp);
	fclose(fp);
	return (EXIT_SUCCESS);
}
