/*Utilizando duas Pilhas, simule o comportamento FIFO de uma Fila (implemente add, remove,
isEmpty, etc). Dica: crie uma nova estrutura chamada “FakeQueue”, dentro dela adicione duas
Pilhas. Crie também funções específicas para esta nova estrutura ex: “fake_queue_create”,
“fake_queue_add”, etc.*/
#include <stdio.h>
#include "fakeQueue.h"

main()
{
	FakeQueue* F = fakeQueue_create();
	char* C = "ABCDE";
	int i=0;

	while(C[i]!='\0')
	{
		fakeQueue_add(F, C[i]);
		i++;
	}

	fakeQueue_get_first(F);
	fakeQueue_get_last(F);
	fakeQueue_add(F, 'J');
	fakeQueue_remove(F);
	fakeQueue_remove(F);
	fakeQueue_remove(F);
	fakeQueue_remove(F);
	fakeQueue_remove(F);
	fakeQueue_remove(F);
	fakeQueue_remove(F);
	fakeQueue_add(F, 'Z');
	fakeQueue_add(F, 'X');
	fakeQueue_add(F, 'W');
	fakeQueue_get_first(F);
	fakeQueue_get_last(F);
	fakeQueue_remove(F);
	fakeQueue_remove(F);
	fakeQueue_remove(F);
	fakeQueue_free(F);
}
