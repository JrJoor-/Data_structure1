#include <stdio.h>
#include <stdlib.h>
#include "dynamic_queue.h"

DynamicQueue* dynamic_queue_create()
{
	DynamicQueue* q = (DynamicQueue*)malloc(sizeof(DynamicQueue));
	q->first = NULL;
	q->size = 0;
	return q;
}

void dynamic_queue_free(DynamicQueue *q)
{
	while(dynamic_queue_is_empty(q)==0)
		dynamic_queue_remove_first(q);

	free(q);
}

int dynamic_queue_is_empty(DynamicQueue *q)
{
	if(q->size==0)
		return 1;
	else
		return 0;
}

Data dynamic_queue_get_first(DynamicQueue *q)
{
	if(dynamic_queue_is_empty(q)==1)
		return ErrorCode;
	else
		return q->first->data;
}

int dynamic_queue_add_last(DynamicQueue *q, Data d)
{
	Item* new_item = (Item*)malloc(sizeof(Item));
	Item* temp_item;
	
	if(new_item == NULL)
		return 0;
	new_item->next_item = NULL;
	new_item->data = d;

	if(dynamic_queue_is_empty(q)==1)
		q->first=new_item;
	
	else
	{
		temp_item = q->first;
		
		while(temp_item->next_item!=NULL)
		{
			temp_item = temp_item->next_item;
		}
		temp_item->next_item = new_item;
	}
	q->size++;
}

Data dynamic_queue_remove_first(DynamicQueue *q)
{
	if(dynamic_queue_is_empty(q)==1)
	{
		return ErrorCode;
	}		
	else
	{	
		Data temp_value = q->first->data;
		Item* temp = q->first->next_item;

		free(q->first);

		q->first = temp;
		q->size--;

		return temp_value;
	}
}

int dynamic_queue_get_size(DynamicQueue* q)
{
	return q->size;
}