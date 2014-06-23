#include "stack.h"

Stack* create_stack()
{
	Stack* S = (Stack*)malloc( sizeof(Stack));
	S->top = NULL;
	S->counter = 0;
	return S;
}

int is_empty(Stack *S)
{
	if(S->counter==0 )
	{
		printf("\nDynamic stack is empty\n\n");
		return 1;
	}
	else
		return 0;
}

Data peek(Stack *S)
{
	printf("\nTop stack | %s |\n\n", S->top->data->nome_aluno);
}

void push(Stack *S, Data d)
{
	Item* novo = (Item*)malloc( sizeof(Item));
	novo->next = S->top;
	novo->data = d;
	S->top = novo;
	S->counter++;
	printf("Aluno: %s embarcou! (Push).\n", S->top->data->nome_aluno);
}

Data pop(Stack *S)
{
	if(is_empty(S)==0)
	{
		Item* item_remover = S->top;
		Aluno* value = item_remover->data;
		S->top = item_remover->next;
		free(item_remover);
		S->counter--;

		return value;
	}
	else
		printf("\nStack is empty\n");
}

void free_stack(Stack *S)
{
	//A pilha tem varios itens, para limpar ela é necessário excluir todos os itens, para tanto é preciso chamar o pop que tem o free pra cada item;
	while(is_empty(S)==0)
		pop(S);
	
	free(S);
}
