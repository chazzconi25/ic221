/* foo.c */
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void * foo(void * args){
  pthread_t thread;

  if(args == NULL){
    pthread_create(&thread, NULL, foo, (void *) 1);
  }
  while(1);
}

int main(int argc, char * argv[]){
  pthread_t threads[4];
  int i;

  for(i=0;i<4;i++){
    pthread_create(&threads[i], NULL, foo, NULL);
  }

  while(1);
}
