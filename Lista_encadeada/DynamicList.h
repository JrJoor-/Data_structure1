#ifndef __DYNAMIC_LIST_H__
#define __DYNAMIC_LIST_H__

#include <stdio.h>
#include <stdlib.h>

#define ErrorCode -1

/*typedef struct aluno{
	char* nome;
	int RA;
}Aluno;*/

typedef char Data; /*-1 para tipos primitivos, NULL para novos tipos de dados| typedef Aluno* Data;*/

typedef struct item Item;
struct item {
	Data data;
	Item* next_item;
};

typedef struct dinamiclist{
	int size;
	Item* first;
}DynamicList;

DynamicList* list_inicialize(); //inicializa

int list_is_empty(DynamicList* l); //estaVazia

int list_add(DynamicList* l, int index, Data data); //adiciona

int list_add_first (DynamicList* l, Data data); //adicionaInicio

int list_add_last (DynamicList* l, Data data); //adicionaFinal

int list_contains(DynamicList* l, Data data); //contem

Data list_get(DynamicList* l, int index); //retorna

Data list_get_first(DynamicList* l); //retornaPrimeiro

Data list_get_last(DynamicList* l); //retornaUltimo

int list_index_of(DynamicList* l, Data data); //primeiraOcorrencia

int list_last_index_of(DynamicList* l, Data data); //ultimaOcorrencia

Data list_remove(DynamicList* l, int index); //remove

Data list_remove_fist(DynamicList* l); //removePrimeiro

Data list_remove_last(DynamicList* l); //removeUltimo

void list_clear(DynamicList* l); //esvazia ou reinicializa

int list_size(DynamicList* l); //tamanho

void list_print(DynamicList* l); //imprime ou textualiza

#endif