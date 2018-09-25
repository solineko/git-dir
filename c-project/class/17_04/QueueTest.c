#include <stdio.h>

#include "queue.h"

void s_log(int);

int main(void){
	Queue queue;
	Item item;
	item.gumption=3;
	InitializeQueue(&queue);
	EnQueue(item,&queue);
	s_log(QueueIsEmpty(&queue));
	EmptyTheQueue(&queue);
	s_log(QueueIsEmpty(&queue));
	return 0;
}

void s_log(int num){
	printf("%d\n",num);
}