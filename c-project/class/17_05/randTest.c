#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//#include "queue.h"

int main(void){
	srand((unsigned int)time(0));
	int num=rand()%3+1;
	printf("%d\n",num);
	return 0;
}