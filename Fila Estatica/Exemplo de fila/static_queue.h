#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

typedef struct queue{
	int begin;
	int end;
	int counter;
	int element[SIZE];
}Queue;

Queue* static_queue_create();

void static_queue_free(Queue* temp);

int static_queue_get_size(Queue* temp);

int static_queue_is_empty (Queue* temp);

int static_queue_is_full (Queue* temp);

int static_queue_add(Queue* temp, char data);

int static_queue_remove(Queue* temp);

int static_queue_get_first(Queue* temp);

int static_queue_last(Queue* temp);
