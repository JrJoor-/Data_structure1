/*Dada uma Fila f e uma Pilha p, crie uma função que recebe e inverte f utilizando p (p deve ser
criada e destruída dentro da função, não sendo visível ao restante do programa). Crie também
uma função que recebe uma Fila f e imprime todos os seus elementos. Nota: p e f são estruturas
que trabalham apenas com caracteres. Utilize a seguinte especificação:
void invert_queue(Queue* q);
void print_queue(Queue* q);
*/

#include <stdio.h>
#include "static_queue.h"
#include "static_stack.h"

void invert_queue(Queue* q)
{
	int i=0;
	int tam = SIZE;
	Stack* p = static_stack_create();
	while(i<tam)
	{
		static_stack_push(p, static_queue_get_first(q));
		static_queue_remove(q);
		i++;
	}

	i=0;
	printf("\n\n");

	while(i<tam)
	{
		static_queue_add(q, static_stack_peek(p));
		static_stack_pop(p);
		i++;
	}
	static_stack_free(p);
}

void print_queue(Queue* q)
{
	int tam=SIZE;
	int i=0;
	while(i<tam)
	{
		static_queue_get_first(q);
		static_queue_remove(q);
		i++;
	}
}

void main()
{
	Queue* q = static_queue_create();
	char* c = "ABCDE";
	int i=0;
	while(c[i]!='\0')
	{
		static_queue_add(q, c[i]);
		i++;
	}
	invert_queue(q);
	print_queue(q);
	static_queue_free(q);
}
	
