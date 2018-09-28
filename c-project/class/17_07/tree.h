#ifndef _TREE_H_
#define _TREE_H_

typedef enum {false,true} bool;

#define SLEN 20

typedef struct item{
	char petname[SLEN];
	char petkind[SLEN];
}Item;

#define MAXITEMS 10

typedef struct trnode{
	struct trnode * left;
	struct trnode * right;
}Trnode;

typedef struct tree{
	Trnode * root;
	int size;
}Tree;

extern void InitializeTree(Tree * ptree);

extern bool TreeIsEmpty(Tree * ptree);

extern bool TreeIsFull(Tree * ptree);

extern int TreeItemCount(Tree * ptree);

extern bool AddItem(const Item * pi,Tree * ptree);

extern bool InTree(const Item * pi,const Tree * ptree);

extern bool DeleteItem(const Item * pi,Tree * ptree);

extern void Traverse(const Tree * ptree,void (*pfun)(Item item));

extern void DeleteAll(Tree * ptree);

#endif