/* IC221 Lab: Signals
 * Program to time a process using alarms and kill if it runs more than 5 seconds.
 * YOUR NAME HERE
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/signal.h>
#include <sys/wait.h>
#include <sys/types.h>

int ticks = 0;
pid_t cpid;

void tick(int signum) {
  //TODO: complete the SIGALRM handler
  // On each alarm, print
  printf("%d: tick-tock\n", ++ticks);
  // If 5 ticks occur, kill the child with SIGKILL
  if(ticks ==  5) {
    kill(cpid, SIGKILL);
    return;
  }
  // (hint: don't forget to set the next alarm)
  alarm(1);
}

int main(int argc, char * argv[]) {

  if ((cpid = fork()) == 0) {
    /*CHILD*/
    execvp(argv[1], argv+1);
    perror(argv[1]);
    _exit(1);
  }
  else if (cpid > 0) {
    /*PARENT*/
    signal(SIGALRM, tick);
    alarm(1);

    //TODO: Complete the program
    wait(NULL);
    // If the child finished before 3 ticks:
    if(ticks < 3) {// If the child finished after 3 ticks but not killed:
      printf("Blast that grotesque ganglion! You let them get away!\n");
    } else if(ticks >= 3 && ticks < 5) {
      printf("Sayonara you shell-backed simpletons. I'll get you next time!\n");
    } else {// If the child was killed:
      printf("Tonight I dine on turtle soup! Muhaha!\n");
    }

  }
  else {
    /*ERROR*/
    perror("fork");
    _exit(1);
  }

  return 0;
}
