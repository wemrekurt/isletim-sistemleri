#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int sum; // bu veri threadler arası paylaşılacak
void *runner(void *param); // threadler bu fonkisyonu çağıracak (burada void *param, argümanın tipsiz olduğunu ve daha sonra cast edileceğini gösterir)

int main(int argc, char *argv[]){
	pthread_t tid; // thread id
	pthread_attr_t attr; // thread özellikleri

	if(argc != 2){
		fprintf(stderr, "kullanim: a.out <int deger> \n");
		return -1;
	}

	if(atoi(argv[1]) < 0){
		fprintf(stderr, "%d sifirdan daha buyuk olmali", atoi(argv[1]));
		return -1;
	}
	
	pthread_attr_init(&attr); //get default attributes
	pthread_create(&tid, &attr, runner, argv[1]); //create thread
	pthread_join(tid, NULL); //threadin exitini(bitmesini) bekle, bekle ki sum set edilsin
	
	printf("sum = %d\n", sum);
}


void *runner(void *param) {
	int i, upper = atoi(param);
	sum = 0;
	
	for(i = 1; i <= upper; i++)
		sum += i;

	pthread_exit(0);	
}

