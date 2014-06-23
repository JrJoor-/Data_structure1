#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

typedef struct stack{
	char swet[SIZE];
	int top;
}Stack;

Stack* static_stack_create();

int static_stack_is_full (Stack* temp);

int static_stack_is_empty (Stack* temp);

void static_stack_push (Stack* temp, char data);

void static_stack_pop (Stack* temp);

char static_stack_peek(Stack* temp);

void static_stack_free(Stack* temp);
