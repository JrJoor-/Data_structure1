#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct escola
{
	char* nome_escola;
	char* end_escola;
	int tel_escola;
}Escola;

typedef struct aluno {
	char nome_aluno[15];
	int matricula_aluno;
	Escola* escola_aluno; 
}Aluno;

//definicao do tipo de Data armazenado pela pilha
typedef Aluno* Data;

//definição do tipo de Data
typedef struct item Item;

//criação da estrutura item, que representa cada posição da pilha
struct item
{
	Data data;
	Item* next;
};

//definição da estrutura base da pilha
typedef struct stack {
    Item* 	top;
    int 	counter;
}Stack;



Stack* create_stack();

void free_stack(Stack *S);

int is_empty(Stack *S);

int is_full(Stack *S);

Data peek(Stack *S);

void push(Stack *S, Data d);

Data pop(Stack *S);
