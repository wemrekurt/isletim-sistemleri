#include <stdio.h>
#include <unistd.h>


int main() {
	pid_t pid;
	printf("\n\n");
	pid = fork();
	
	if(pid > 0){
		printf("p\n");
		return 0;
	}
	if(pid == 0){
		printf("c\n");
		return 0;
	}
	
	return 1;
	

}
