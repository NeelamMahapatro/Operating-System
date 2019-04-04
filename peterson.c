
#include <stdio.h> 
#include <stdlib.h> 
#include <pthread.h> 
 	int value, turn=0;
	int flag[2];

void entry(int id)
{
	flag[id] = 1;
	turn = 1 - id;
	while(flag[1-id] == 1 && turn == 1- id);
}
void exit1(int id)
{
	flag[id] = 0;
}
void *pth(void *value) 
{ 
    	int *val = (int*)value;
    	printf("Producer Thread:\n");
    	printf("%d\n", *val); 
	entry(0);
    		*val = *val - 100;
	exit1(0);
	printf("producer output %d\n", *val);
    	return NULL; 
} 
 
void *cth(void *value) 
{  
	int *val = (int *) value;
	printf("Consumer Thread:\n");
    	printf("%d\n", *val); 
	entry(1);
		*val = *val + 300;
	exit1(1);
	printf("consumer output %d\n", *val);
    	return NULL; 
} 
   
int main() 
{ 
	
	value = 1000;
	
	flag[1] = 0;
	flag[0] = 0;
	pthread_t producer, consumer;    
	pthread_create(&producer, NULL, pth,(void *)&value);
	pthread_create(&consumer, NULL, cth, (void *)&value);
	pthread_join(producer, NULL);
	pthread_join(consumer, NULL); 
        exit(0); 
}

