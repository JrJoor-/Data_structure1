#ifndef __DYNAMIC_QUEUE_H__
#define __DYNAMIC_QUEUE_H__

#include <stdio.h>
#include <stdlib.h>

//definicao do tipo de Data armazenado pela fila
typedef char Data;
//definicao do codigo de erro: NULL para ponteiros, -1 para tipos primitivos
#define ErrorCode -1

//definição do tipo de dado Item
typedef struct item Item;

//criação da estrutura item, que representa cada elemento da fila
struct item
{
	Data data;
	Item* next_item;
};

//definição da estrutura base da fila
typedef struct dynamic_queue {
	int size;
	Item* first;
}DynamicQueue;

DynamicQueue* dynamic_queue_create();

void dynamic_queue_free(DynamicQueue *q);

int dynamic_queue_is_empty(DynamicQueue *q);

Data dynamic_queue_get_first(DynamicQueue *q);

int dynamic_queue_add_last(DynamicQueue *q, Data d);

Data dynamic_queue_remove_first(DynamicQueue *q);

int dynamic_queue_get_size(DynamicQueue* q);

#endif
