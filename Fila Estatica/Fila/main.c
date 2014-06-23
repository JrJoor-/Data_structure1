
#include <stdio.h>
#include "static_queue.h"

void main()
{
	Queue* q = static_queue_create();
	int x=2;
	static_queue_add(q, 4);
	static_queue_add(q, x);
	static_queue_add(q, static_queue_get_first(q));
	static_queue_add(q, (3+static_queue_get_first(q)));
	static_queue_add(q, 0);	
	static_queue_remove(q);
	while(static_queue_is_empty(q)==0)
	{
		x=static_queue_remove(q);
		printf("\n--%d--\n", x);
	}
	static_queue_free(q);
}
	
