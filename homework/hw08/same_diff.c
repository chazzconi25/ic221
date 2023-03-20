/* same_diff.c */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char * argv[]){

  pid_t cpid;
  int status;
  cpid = fork();
  
  if( cpid == 0 ){        // CHILD

    setpgid(cpid,cpid);      

    pid_t parent = getppid();
    pid_t parent_group = getpgid(parent);
    pid_t child = getpid();
    pid_t child_group = getpgrp();

    if(child_group == parent_group){ printf("Same process group\n"); }
    else { printf("Different process group\n"); }
    exit(0);

  }else if( cpid > 0 ){      // PARENT

    setpgid(cpid, cpid);    
    wait(&status);
    exit(0);

  }else{
    /*ERROR*/
    perror("fork");
    _exit(1);
  }

  return 0;
}