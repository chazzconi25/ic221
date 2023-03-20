/*terminate.c*/
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(){	
	pid_t cpid;

	cpid = fork();
	if( cpid == 0 ){
		setpgrp();
		while(1);
	}else if( cpid > 0 ){
		wait(NULL);
		exit(0);
	}
	exit(1);
}