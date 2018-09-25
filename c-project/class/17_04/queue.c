#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

static void CopyToNode(Item,Node *);

void InitializeQueue(Queue * pq){
	pq->rear=pq->front=NULL;
	pq->items=0;
}

bool QueueIsEmpty(const Queue * pq){
	return pq->items==0;
}

bool QueueIsFull(const Queue * pq){
	return pq->items==MAXQUEUE;
}

bool QueueItemCount(const Queue * pq){
	return pq->items;
}

bool EnQueue(Item item,Queue * pq){
	if(pq->items>=MAXQUEUE){
		return false;
	}
	Node * pnew=(Node *)malloc(sizeof(Node));
	if(pnew==NULL){
		return false;
	}
	CopyToNode(item,pnew);
	pnew->next=NULL;
	if(pq->items==0){
		pq->rear=pq->front=pnew;
		pq->items++;
	}
	else{
		pq->rear->next=pnew;
		pq->rear=pnew;
		pq->items++;
	}
	return true;
}

bool DeQueue(Item * item,Queue * pq){
	Node * saveNode;
	if(QueueIsEmpty(pq)){
		return false;
	}
	*item=pq->front->item;
	saveNode=pq->front;
	pq->front=pq->front->next;
	pq->items--;
	free(saveNode);
	if(pq->items==0){
		pq->rear=NULL;
	}	
	return true;
}

void EmptyTheQueue(Queue * pq){
	Item item;
	while(!QueueIsEmpty(pq)){
		DeQueue(&item,pq);
	}

}

static void CopyToNode(Item item,Node * pnode){
	pnode->item=item;
} 

