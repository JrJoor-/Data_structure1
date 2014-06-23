#include <stdio.h>
#include "dynamic_queue.h"



void main()
{
	DynamicQueue* q = dynamic_queue_create(); 

	printf("adding 'x': %s\n",dynamic_queue_add_last(q,'x')?"success":"failed");
	printf("adding 'y': %s\n",dynamic_queue_add_last(q,'y')?"success":"failed");
	printf("adding 'z': %s\n",dynamic_queue_add_last(q,'z')?"success":"failed");
	printf("adding 'w': %s\n",dynamic_queue_add_last(q,'w')?"success":"failed");
	printf("adding 'u': %s\n",dynamic_queue_add_last(q,'u')?"success":"failed");
	printf("adding 'o': %s\n",dynamic_queue_add_last(q,'o')?"success":"failed");

	printf("removed: %c\n",dynamic_queue_remove_first(q));
	printf("removed: %c\n",dynamic_queue_remove_first(q));
	printf("adding 'a': %s\n",dynamic_queue_add_last(q,'a')?"success":"failed");
	printf("adding 's': %s\n",dynamic_queue_add_last(q,'s')?"success":"failed");
	printf("adding 'd': %s\n",dynamic_queue_add_last(q,'d')?"success":"failed");

	printf("removed: %c\n",dynamic_queue_remove_first(q));
	printf("adding 'f': %s\n",dynamic_queue_add_last(q,'f')?"success":"failed");
	printf("adding 'g': %s\n",dynamic_queue_add_last(q,'g')?"success":"failed");

	printf("removed: %c\n",dynamic_queue_remove_first(q));
	printf("adding 'k': %s\n",dynamic_queue_add_last(q,'k')?"success":"failed");

	printf("removed: %c\n",dynamic_queue_remove_first(q));
	printf("adding 'l': %s\n",dynamic_queue_add_last(q,'l')?"success":"failed");

	printf("removed: %c\n",dynamic_queue_remove_first(q));
	printf("removed: %c\n",dynamic_queue_remove_first(q));
	printf("removed: %c\n",dynamic_queue_remove_first(q));
	printf("removed: %c\n",dynamic_queue_remove_first(q));
	printf("removed: %c\n",dynamic_queue_remove_first(q));
	printf("removed: %c\n",dynamic_queue_remove_first(q));

	printf("size: %d\n", dynamic_queue_get_size(q));

	dynamic_queue_free(q); 
	
}
