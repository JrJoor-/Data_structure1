#include "DynamicList.h"

main()

{
	DynamicList* l = list_inicialize();

	/*Aluno* Al1 = (Aluno*)malloc(sizeof(Aluno));
	Aluno* Al2 = (Aluno*)malloc(sizeof(Aluno));

	Al1->RA = 1516;
	Al1->nome = "JOAO";

	Al2->RA = 2324;
	Al2->nome = "SIBA";
	*/

	printf("\nInseriu? %s", list_add_last(l, 'a')?"sim":"não");
	printf("\nInseriu? %s", list_add_last(l, 'b')?"sim":"não");

	printf("\nFirst %c\n", list_get_first(l));
	printf("\nLast %c\n", list_get_last(l));

	printf("\nInseriu? %s", list_add_last(l, 'c')?"sim":"não");
	printf("\nInseriu? %s", list_add_last(l, 'd')?"sim":"não");
	printf("\nInseriu? %s", list_add_first(l, 'e')?"sim":"não");
	printf("\nInseriu? %s", list_add_first(l, 'f')?"sim":"não");
	printf("\nInseriu? %s", list_add_first(l, 'g')?"sim":"não");

	printf("\nFirst %c\n", list_get_first(l));
	printf("\nLast %c\n", list_get_last(l));

	list_print(l);

	printf("\nSize %d\n", list_size(l));

	list_clear(l);

	printf("\nSize %d\n", list_size(l));

	printf("\nInseriu? %s", list_add_last(l, 'c')?"sim":"não");
	printf("\nInseriu? %s", list_add_last(l, 'd')?"sim":"não");
	printf("\nInseriu? %s", list_add_first(l, 'e')?"sim":"não");
	printf("\nInseriu? %s", list_add_first(l, 'f')?"sim":"não");
	printf("\nInseriu? %s", list_add_first(l, 'g')?"sim":"não");

	list_print(l);

	list_remove_first(l);	
	list_remove_first(l);	
	list_remove_first(l);	
	
	list_print(l);
}