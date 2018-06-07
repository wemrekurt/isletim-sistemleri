#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
	int pid;
	pid = fork();
	
	if(pid > 0){
		// parent process
		wait(NULL); // önce çocuk çalışacak bu satırdan dolayı
		printf("child pid: %d , parent pid: %d \n", pid, getpid());
	}else if(pid == 0){
		// child process
		
		printf("child pid: %d , my pid: %d \n", pid, getpid());
		execlp("/bin/ls","ls",NULL);
	}else{
		// error
		return 1;
	}
	return 0;

}
