#include "fakeQueue.h"

FakeQueue* fakeQueue_create()
{
	Stack* s1 = (Stack*)malloc( sizeof(Stack) );
	Stack* s2 = (Stack*)malloc( sizeof(Stack) );
	s1->top = 0;
	s2->top = 0;
}

void fakeQueue_free(FakeQueue* s1)
{
	printf("\nFakeQueue destroyed!\n");
	free(s1);
}

int fakeQueue_get_size(FakeQueue* s1)
{
	int tam = SIZE;
	return tam;
}

int fakeQueue_is_empty (FakeQueue* s1)
{
	if((*s1).s1.top== 0)
		return(1);
	else
		return(0);
}

int fakeQueue_is_full (FakeQueue* s1)
{
	if((*s1).s1.top==SIZE)
		return(1);
	else
		return(0);
}


int fakeQueue_add(FakeQueue* s1, char data)
{
	int i=0;
	if(fakeQueue_is_full(s1)==1)
	{
		printf("\nError: Queue is Full!\n");
		return 0;
	}

	else
	{		
		(*s1).s1.swet[(*s1).s1.top]= data;
		(*s1).s1.top++;
		printf("\nInserted | %c |\n", data);
	}

	return 1;
}

int fakeQueue_remove(FakeQueue* s1)
{
	if(fakeQueue_is_empty(s1) == 0 || (*s1).s2.top>0)
	{
		if((*s1).s2.top == 0)
		{
			FakeQueue_S1_S2(s1);
		}		
		
		printf("\nRemovido -- %c -- \n", (*s1).s2.swet[(*s1).s2.top-1]);
		(*s1).s2.swet[(*s1).s2.top]='\0';
		(*s1).s2.top--;

		return 1;
	}
	else
	{
		printf("\nError: Queue is empty!\n");
		return 0;
	}
}

int fakeQueue_get_first(FakeQueue* s1)
{	
	if(fakeQueue_is_empty(s1)==1)
		printf("\nError in funtion: fakeQueue_is_empty: FakeQueue is empty!\n\n");
	else
	{
		FakeQueue_S1_S2(s1);
		printf("\nGet First < %c >\n", (*s1).s2.swet[(*s1).s2.top-1]);
	
	}
	return (*s1).s1.swet[(*s1).s1.top-1];
}

int fakeQueue_get_last(FakeQueue* s1)
{
	if(fakeQueue_is_empty(s1)==0)
		printf("\nError in funtion: fakeQueue_is_empty: Queue is empty!\n\n");
	else
	{
		FakeQueue_S2_S1(s1);
		printf("\nGet Last < %c >\n", (*s1).s1.swet[(*s1).s1.top-1]);
	}
}

int FakeQueue_S1_S2(FakeQueue* s1)
{
	int i=0;
	int temp = (*s1).s1.top;
	while(i<temp)
	{
		(*s1).s2.swet[(*s1).s2.top] = (*s1).s1.swet[(*s1).s1.top-1];
		(*s1).s1.swet[(*s1).s1.top]='\0';
		(*s1).s2.top++;
		(*s1).s1.top--;
		i++;			
	}
}

int FakeQueue_S2_S1(FakeQueue* s1)
{
	int i=0;
	int temp = (*s1).s2.top;
	while(i<temp)
	{
		(*s1).s1.swet[(*s1).s1.top] = (*s1).s2.swet[(*s1).s2.top-1];
		(*s1).s2.swet[(*s1).s2.top]='\0';
		(*s1).s1.top++;
		(*s1).s2.top--;
		i++;			
	}
}

