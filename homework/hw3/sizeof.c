#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]){

  int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int b[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  //copy from a to b
  for(int i =0; i < 10; i++) {
      b[i] = a[i];
  }
  for(int i = 0; i < 10; i++) {
    printf("%d\n",b[i]);
  }
}
