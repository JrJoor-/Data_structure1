#include "static_queue.h"

Queue* static_queue_create()
{
	Queue* temp = (Queue*)malloc( sizeof(Queue) );
	temp->counter = 0;
	printf("\nQueue create!\n");
	return temp;
}

void static_queue_free(Queue* temp)
{
	printf("\nQueue destroyed!\n");
	free(temp);
}

int static_queue_get_size(Queue* temp)
{
	int tam = SIZE;
	return tam;
}

int static_queue_is_empty (Queue* temp)
{
	if(temp->counter== 0)
		return(1);
	else
		return(0);
}

int static_queue_is_full (Queue* temp)
{
	if(temp->counter == SIZE)
		return(1);
	else
		return(0);
}

int static_queue_add(Queue* temp, int data)
{
	if(static_queue_is_full(temp))
	{
		printf("Erro: fila cheia!\n");
		return 0;
	}

	if(static_queue_is_empty(temp) == 1)
	{
		temp->begin=0;
		temp->end=0;
	}
	else
	{
		temp->end++;
		if(temp->end >= SIZE)
			temp->end = 0;
	}
	
	temp->element[temp->end]=data;
	temp->counter++;
	
	printf("Inserted= %d | begin=%d | end=%d | counter=%d\n", data, temp->begin, temp->end, temp->counter);

	return 1;
}


int static_queue_remove(Queue* temp)
{
	if(static_queue_is_empty(temp) == 0)
	{
		printf("removed:%d\n", temp->element[temp->begin]);
		
		temp->begin++;
		if(temp->begin >= SIZE)
			temp->begin = 0;

		temp->counter--;

		return 1;
	}
	else
	{
		printf("Erro: pilha vazia!\n");
		return 0;
	}
}

int static_queue_get_first(Queue* temp)
{	
	if(static_queue_is_empty(temp)==1)
		printf("\nError in funtion: static_queue_is_empty: Queue is empty!\n\n");
	else
		printf("\n%d\n", temp->begin);
}

int static_queue_get_last(Queue* temp)
{
	if(static_queue_is_empty(temp)==1)
		printf("\nError in funtion: static_queue_is_empty: Queue is empty!\n\n");
	else
		printf("\n%d\n", temp->end);
}
