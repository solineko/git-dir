#include <stdio.h>

int main(void){
	int num=0;
	int arm=1;
	int * num_p=&num;
	*num_p=1;
	num_p=&arm;
	
	return 0;
}