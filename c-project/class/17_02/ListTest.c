#include <stdio.h>
#include <string.h>

#include "list.h"

void bool_say(bool word);

int main(void){
	List list;
	InitializeList(&list);
	Item item;
	strcpy(item.title,"QWQ");
	AddItem(item,&list);
	EmptyTheList(&list);
	bool_say(ListIsEmpty(&list));
	return 0;
}

void bool_say(bool word){
	if(word==true){
		printf("%s\n","true");
	}
	else{
		printf("%s\n","false");
	}
}