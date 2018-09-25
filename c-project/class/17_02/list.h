#ifndef LIST_H_
#define LIST_H_

#define TSIZE 45

typedef enum bool{true,false
}bool;


struct film{
	char title[TSIZE];
	int rating;
	struct file * next;
};

typedef struct film Item;

typedef struct node
{
	Item item;
	struct node * next;	
} Node;

typedef Node * List;

extern void InitializeList(List * plist);

extern bool ListIsEmpty(const List * plist);

extern bool ListIsFull(const List * plist);

extern unsigned int ListItemCount(const List * plist);

extern bool AddItem(Item item,List * plist);

extern void Traverse(const List * plist,void (*pfun)(Item item));

extern void EmptyTheList(List * plist);

#endif


