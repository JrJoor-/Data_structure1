#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

typedef struct stack{
	char swet[SIZE];
	int top;
}Stack;

typedef struct fakequeue{
	Stack s1;
	Stack s2;
}FakeQueue;


FakeQueue* fakeQueue_create();

void fakeQueue_free(FakeQueue* s1);

int fakeQueue_get_size(FakeQueue* s1);

int fakeQueue_is_empty (FakeQueue* s1);

int fakeQueue_is_full (FakeQueue* s1);

int fakeQueue_add(FakeQueue* s1, char data);

int fakeQueue_remove(FakeQueue* s1);

int fakeQueue_get_first(FakeQueue* s1);

int fakeQueue_get_last(FakeQueue* s1);
