#include <stdio.h>
#include <unistd.h>
#include <signal.h>
int count = 8;

void handler(int signum){

  printf("Alarm!\n");
  count /= 2;
  alarm(count);
}

int main(){

  signal(SIGALRM, handler);
  alarm(count);

  while(1) pause();
}

