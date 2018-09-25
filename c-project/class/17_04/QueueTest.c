#include <stdio.h>

#include "queue.h"

void s_log(int);

int main(void){
	Queue queue;
	Item item;
	item.gumption=3;
	InitializeQueue(&queue);
	EnQueue(item,&queue);
	Item saveItem;
	s_log(queue.items);
	s_log(DeQueue(&saveItem,&queue));
	s_log(saveItem.gumption);
	return 0;
}

void s_log(int num){
	printf("%d\n",num);
}