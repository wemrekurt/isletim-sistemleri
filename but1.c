#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>



// execlp("/bin/ls","ls",NULL);

int main(int argc, char *argv[]){
	pid_t pid;
	pid = fork();

	if(pid == 0){
		// child process
	}else if(pid > 0){
		wait(NULL);
		// parent process
		if(argc > 1){ 
			int ret;
  	  ret = execvp(argv[1],  argv+1);
			if (ret == -1) {
      	fprintf(stderr, "%s: %s: Böyle bir program yok", argv[0], argv[1] );	
				exit(EXIT_FAILURE);
	    }
		}
	}else{
		fprintf(stderr, "Hata!");
		return 1;
	}
			
	return 0;
}
