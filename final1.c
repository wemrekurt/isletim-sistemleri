#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int a = 4, b = 0, c = 0, d = 0;
void *fun1(void *param);
void *fun2(void *param);
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
void *thread_result;


int main() {
	pthread_t t1pid;
	pthread_t t2pid;
	
	pthread_create(&t2pid, NULL, fun2, NULL);
	pthread_join(t2pid, NULL);
	pthread_create(&t1pid, NULL, fun1, NULL);
	pthread_join(t1pid, NULL);
	
	printf("c: %d \n", c); 	
}


void *fun1(void *param){
	if(a < 0){
		c = b - a;
	}else{
		c = b + a;
	}
}

void *fun2(void *param){
	pthread_mutex_lock(&mutex);
	b = 10;
	a = -3;
	pthread_mutex_unlock(&mutex);
}
