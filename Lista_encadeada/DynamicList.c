#include "DynamicList.h"

/*int is_data_equal (Data d1, Data d2)
{
	if(d1->RA == d2->RA)
		return 1;
	else
		return 0;
}*/

int is_data_equal (Data d1, Data d2)
{
	if( d1 == d2)
		return 1;
	else
		return 0;
}

print_item(Data d)
{
	printf(" %c ,", d);
}

/*print_item(Data d)
{
	printf("Nome: %s, | RA: %d", d->nome, d->RA);
}*/

DynamicList* list_inicialize() //inicializa
//Aloca, inicializa e retorna uma nova lista.
{
	DynamicList* l = (DynamicList*)malloc(sizeof(DynamicList));
	l->size=0;

	return l;
}

int list_is_empty(DynamicList* l) //estaVazia
//Retorna 1 se a lista está vazia, 0 caso contrário.
{
	if(l->size==0)
		return 1;
	else
		return 0;
}

int list_add(DynamicList* l, int index, Data data) //adiciona
/*Adiciona o inteiro na posição especificada da lista. Perceba que nenhuma outra operação de
adição precisa ser implementada. Basta ativar esta, mais genérica, com parâmetros. Retorna 1
em caso de sucesso e 0 caso contrário.*/
{
	if(index<=list_size(l))
	{
		Item* new_item = (Item*)malloc(sizeof(Item));

		new_item->data = data;
		new_item->next_item = NULL;

		if(index==0)
		{
			new_item->next_item = l->first; //O PROXIMO ITEM RECEBE TODA A LISTA

			l->first = new_item;

			l->size++;

			return 1;
		}

		else 
		{	
			Item* temp_item;

			temp_item = l->first; //ITEM TEMPORARIO RECEBE A LISTA.

			int i;

			for (i = 1; i < index; i++) 
			{	
				temp_item = temp_item->next_item; //PERCORRE ATÉ NA POSIÇÃO QUE DEVE ADICIONAR;
			}
			
			new_item->next_item = temp_item->next_item; //RECEBE O FINAL DA FILA

			temp_item->next_item = new_item; //COLOCA O NOVO ITEM NO MEIO DA FILA

			l->size++;

			return 1;
		}
	}
	else
		return 0;
}

int list_add_first (DynamicList* l, Data data) //adicionaInicio
{
	list_add(l, 0, data);
}

int list_add_last (DynamicList* l, Data data) //adicionaFinal
{
	list_add(l, list_size(l), data);
}

int list_contains(DynamicList* l, Data data) //contem
{
	Item* temp_item;

	temp_item = l->first; 

	int i;

	for (i = 0; i < list_size(l); i++) 
	{	
		if(is_data_equal(temp_item->data, data))
			return 1;

		temp_item = temp_item->next_item; //RETURN 0 ???? 
	}
	return 0;
}

Data list_get(DynamicList* l, int index) //retorna
{
	if (index>=list_size(l))
		return ErrorCode;

	if (list_is_empty(l)==1)
		return ErrorCode;

	Item* temp_item;

	temp_item = l->first; 

	int i;

	for (i = 0; i < index; i++) 
	{	
		temp_item = temp_item->next_item; 
	}

	return temp_item->data;
}

Data list_get_first(DynamicList* l) //retornaPrimeiro
{
	list_get(l, 0);
}

Data list_get_last(DynamicList* l) //retornaUltimo
{
	list_get(l, list_size(l)-1);
}

int list_index_of(DynamicList* l, Data data) //primeiraOcorrencia
{
	Item* temp_item;

	temp_item = l->first; 

	int i;
	int counter=0;

	for (i = 0; i < list_size(l); i++) 
	{	
		if(is_data_equal(data,temp_item->data) )
			return counter; 
		else
			temp_item = temp_item->next_item;
		
		counter++; 
	}
	return -1;

}

int list_last_index_of(DynamicList* l, Data data) //ultimaOcorrencia
{
	Item* temp_item;

	temp_item = l->first; 

	int i;
	int counter=0;
	int position=-2;

	for (i = 0; i < list_size(l); i++) 
	{	
		if( is_data_equal(data,temp_item->data) )
			position=counter;

		temp_item = temp_item->next_item;

		counter++;

	}
	if(position==-2)
		return -1;
	else
		return position;
}

Data list_remove(DynamicList* l, int index) //remove
{
	if(list_is_empty(l)==1)
		return ErrorCode;


	Data temp_value;

	if(index==0)
	{
		temp_value = l->first->data;
		Item* aux = l->first->next_item;

		free(l->first);

		l->first= aux;

	}

	else 
	{
		int i;

		Item* aux = l->first;

		for (i = 1; i < index; i++) 
			aux = aux->next_item;


		Item* rmv = aux->next_item;
		temp_value = rmv->data;
		aux->next_item = rmv->next_item;

		free(rmv);
	}
	l->size--;
	return temp_value;

}

int list_size(DynamicList* l) //tamanho
{
	return l->size;
}

Data list_remove_first(DynamicList* l)
{
	list_remove(l, 0);
}

Data list_remove_last(DynamicList* l) //removeUltimo
{
	list_remove(l, list_size(l)-1);
}

void list_clear(DynamicList* l) //esvazia ou reinicializa
{
	while(list_is_empty(l)!=1)
	{
		list_remove_last(l);
	}
}

void list_print(DynamicList* l) //imprime ou textualiza
{
	int i;
	printf("\n{");
	for(i=0;i<list_size(l); i++)
	{
		print_item(list_get(l, i));
	}
	printf("}\n");
}