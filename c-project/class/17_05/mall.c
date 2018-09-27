#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "queue.h"

#define MIN_PER_HR 60.0//

bool newcustomer(double);
Item customertime(long);


int main(void){
	Queue line;
	Item temp;//新的顾客数据
	int hours;//模拟的小时数
	int perhour;//每小时平均多少位顾客
	long cycle;//循环计数器		
	long cyclelimit;//循环计数器上限
	long turnaways=0;//团队列已满被拒人数
	long customers=0;//加入队列的顾客数量
	long served=0;//在模拟期间咨询过sigmund的顾客数量
	long sum_line=0;//累计的队列总长
	int wait_time=0;//从当前到sigmund空闲所需的时间
	double min_per_cust;//顾客到来的平均时间
	long line_wait=0;//队列累计的等待时间

	InitializeQueue(&line);
	srand((unsigned int)time(0));
	puts("Case study:Sigmund Lander's Advice Booth");
	puts("Enter the number of simulation hours");
	scanf("%d",&hours);
	cyclelimit=MIN_PER_HR*hours;
	puts("Enter the average number of customers per hour:");
	scanf("%d",&perhour);
	min_per_cust=MIN_PER_HR/perhour;
	for(cycle=0;cycle<cyclelimit;cycle++){
		if(newcustomer(min_per_cust)){
			if(QueueIsFull(&line)){
				turnaways++;
			}
			else{
				customers++;
				temp=customertime(cycle);
				EnQueue(temp,&line);
			}
		}
		if(wait_time<=0&&!QueueIsEmpty(&line)){
			DeQueue(&temp,&line);
			wait_time=temp.processtime;
			line_wait+=cycle-temp.arrive;//当前时间减去到达时间得到该顾客在队列中等待直到移出队列的时间；
			served++;
		}
		// else{
		// 	wait_time--;
		// }
		if(wait_time>0){
			wait_time--;
		}
		sum_line+=QueueItemCount(&line);
	}
	if(customers>0){
		printf("customers accepted: %ld\n",customers);
		printf("customers served: %ld\n",served);
		printf("turnaways: %ld\n",turnaways);
		printf("average queue size:%.2f\n",(double)sum_line/cyclelimit);
		printf("average wait time: %.2f minutes\n",(double)line_wait/served);
	}
	else{
		puts("No customers!");
	}
	EmptyTheQueue(&line);
	puts("Bye!");
	return 0;
}

bool newcustomer(double x){
	if(rand()*x/RAND_MAX<1){ //rand()/RAND_MAX得到一个0~1之间的随机数,再与x相乘得到当前时间点(cycle)是否有新客户到来，如果结果小于1则为有否则为无;
		return true;
	}
	else{
		return false;
	}
}

Item customertime(long when){
	Item cust;
	cust.processtime=rand()%3+1; //对rand()结果进行求余运算结果范围为0~2,由于需要的是0~3之间的随机数所以在此基础之上+1；
	cust.arrive=when;
	return cust;
}