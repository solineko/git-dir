#include <stdio.h>
#include <stdlib.h>

#include "tree.h"

static Trnode * MakeNode(Item *);
static void AddNode(Trnode * new_node,Trnode * root);

bool AddItem(const Item * pi,Tree * ptree){
	Trnode * new_node;
	if(TreeIsFull(ptree)){
		fprintf(stderr,"Tree is full\n");
		return false;
	}
	
}



static Trnode * MakeNode(Item * pi){
	Trnode * new_node;
	new_node=(Trnode *)malloc(sizeof(Trnode));
	if(new_node!=NULL){
		new_node->item=*pi;
		new_node->left=NULL;
		new_node->right=NULL;
	}
	return new_node;
}

static void AddNode(Item * new_node,Trnode * root){
	if(ToLeft(&new_node->item,&root->item)){
		if(root->left==NULL){
			root->left=new_node;
		}
		else{
			AddNode(new_node,root->left);
		}
	}
	else if(ToRight(&new_node->item,&root->item)){
		if(root->right==NULL){
			root->right=new_node;
		}
		else{
			AddNode(new_node,root->right);
		}
	}
	else{
		fprintf(stderr,"location error in AddNode()\n");
		exit(1);
	}
}

static bool ToLeft(const Item * i1,const Item * i2){

}