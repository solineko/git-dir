#ifndef _Queue_H_
#define _Queue_H_

#define MAXQUEUE 45

typedef enum bool {
	false,
	true
} bool;

typedef struct item{
	long arrive;
	int processtime;
} Item;

typedef struct node{
	Item item;
	struct node * next;
} Node;

typedef struct queue{
	Node * front;
	Node * rear;
	int items;
} Queue;

extern void InitializeQueue(Queue *);

extern bool QueueIsFull(const Queue *);

extern bool QueueIsEmpty(const Queue *);

extern unsigned int QueueItemCount(const Queue *);

extern bool EnQueue(Item,Queue *);

extern bool DeQueue(Item *,Queue *);

extern void EmptyTheQueue(Queue * pq); 


#endif