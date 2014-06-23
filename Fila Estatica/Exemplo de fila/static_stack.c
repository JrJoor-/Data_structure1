#include "static_stack.h"

Stack* static_stack_create()
{
	Stack* temp = (Stack*)malloc( sizeof(Stack) );
	temp->top = 0;

	return temp;
}

int static_stack_is_full (Stack* temp)
{
	if(temp->top == SIZE)
		return(1);
	else
		return(0);
}

int static_stack_is_empty (Stack* temp)
{
	if(temp->top == 0)
		return(1);
	else
		return(0);
}

void static_stack_push (Stack* temp, char data)
{
	if(static_stack_is_full(temp) == 0)
	{
		temp->swet[temp->top]= data;
		temp->top++;
		printf("Push (%c)\n", data);
	}
	else
	{
		printf("Erro: pilha cheia!\n");
	}
}

void static_stack_pop (Stack* temp)
{
	if(static_stack_is_empty(temp) == 0)
	{
		printf("Pop () #%c\n", temp->swet[temp->top-1]);
		temp->swet[temp->top]= '\0';
		temp->top--;
	}
	else
	{
		printf("Erro: pilha vazia!\n");
	}
}

char static_stack_peek(Stack* temp)
{
	if(static_stack_is_empty(temp) == 1)
		return '\0';
	else
		return temp->swet[temp->top-1];
}

void static_stack_free(Stack* temp)
{
	free(temp);
}
