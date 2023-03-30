#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

int count = 0;

void handler(int signum){
  printf("You Shot Me!\n");
  count++;

  if(count > 3){
    printf("I'm dead!\n");
    exit(1);
  }
}

int main(){

  //establish signal hander for SIGINT and SIGSTOP
  signal(SIGINT, handler);
  signal(SIGTSTP, handler);

  while(1);  //loop forever
}
