/*fight.c*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <fcntl.h>
int main(){
  pid_t cpid;

  int fd = open("fight.txt",O_RDONLY);
  char buf[1024];

  cpid = fork();
  if(cpid == 0){

    read(fd, buf, 10);
    exit(0);

  }else if(cpid > 0){
    wait(NULL); /* wait for child*/

    read(fd,buf, 10);
    write(1, buf, 10);
    exit(0);
  }
  exit(1); //fork failed
}