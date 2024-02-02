#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
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
typedef struct stack_s
{
        int n;

        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - code and its function
 * @opcode: the code
 * @f: function to handle the code
 *
 * Description: code and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *code;

        void (*f)(stack_t **stack, unsigned int line_number);

} instruction_t;

extern stack_t *headNode;
typedef void (*op_func)(stack_t **, unsigned int);

/*file operations*/
void open_f(char *nameFile);

int parse(char *buff, int line_number, int form);

void readf(FILE *fd);
int len_chars(FILE *);
void get_func(char *, char *, int, int);

/*Stack operations*/
stack_t *create(int n);

void nodeFree(void);
void displayStack(stack_t **stack_node, unsigned int line_number);

void insertToStack(stack_t **new, unsigned int line);

void insertToQueue(stack_t **new, unsigned int line);

void invoke_function(op_func func, char *operation, char *val, int line, int form);

void displayTop(stack_t **stack_node, unsigned int line_number);

void deleteTop(stack_t **stack_node, unsigned int line_number);

void nopFunc(stack_t **stack_node, unsigned int line_number);

void swapNodes(stack_t **stack_node, unsigned int line_number);

/*Math operations with nodes*/
void add(stack_t **stack_node, unsigned int line_number);

void subtract(stack_t **stack_node, unsigned int line_number);

void devide(stack_t **stack_node, unsigned int line_number);

void multiplay(stack_t **stack_node, unsigned int line_number);

void modulas(stack_t **stack_node, unsigned int line_number);

/*String operations*/
void displayChar(stack_t **stack_node, unsigned int line_number);

void displayString(stack_t **stack_node, unsigned int line_number);

void rotate(stack_t **stack_node, unsigned int line_number);

/*Error hanlding*/
void handleError(int code, ...);

void handleMoreErrors(int code, ...);

void handleStringErrors(int code, ...);

void rotateReverse(stack_t **stack_node, unsigned int line_number);

#endif

