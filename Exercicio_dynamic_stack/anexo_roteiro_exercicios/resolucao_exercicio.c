#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void imprime_escola(Escola* E)
{
	printf("\tEscola: %s | Endereço %s | Telefone %d\n", E->nome_escola, E->end_escola, E->tel_escola);
}

void imprime_aluno(Aluno* A)
{
	printf("Aluno: %s | Matricula: %d\n", A->nome_aluno, A->matricula_aluno);
	imprime_escola(A->escola_aluno);
}

void main()
{
	Escola* E1 = (Escola*)malloc(sizeof(Escola));
	Escola *E2 = (Escola*)malloc(sizeof(Escola));
	
	E1->nome_escola = "Escola_municipal";
	E1->end_escola = "Rua_principal";
	E1->tel_escola = 36231010;

	E2->nome_escola = "UTFPR";
	E2->end_escola = "Feroz II";
	E2->tel_escola = 30351010;

	Aluno* alunos[10];
	int i;
	for(i=0;i<10;i++)
	{
		alunos[i] = (Aluno*)malloc(sizeof(Aluno));

		char buff[15];
		sprintf(buff, "%d", i);

		strcpy(alunos[i]->nome_aluno,buff);
		if(i%2==0)
			alunos[i]->escola_aluno = E1;
		else
			alunos[i]->escola_aluno = E2;			
		alunos[i]->matricula_aluno = 100+i;
	}

	Stack* S = create_stack();

	for(i=0;i<10;i++)	push(S, alunos[i]);

	printf("\nRealizando a Viagem...\n\n");

	for(i=9;i>=0;i--) 
	{
		pop(S);
		imprime_aluno(alunos[i]);
	}

	free_stack(S);
}
