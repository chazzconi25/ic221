#include <stdio.h>
#include <stdlib.h>

#include <string.h>

int main(int argc, char * argv[]){
  int i;
  char hello[] = "Hello World!";

  //simple copy routine
  char * str = malloc(strlen(hello));
  for(i = 0; i < strlen(hello); i ++){
    printf("%d",i);
    str[i] = hello[i];
    printf(" %c\n", str[i]);
  }
  

  printf("%s\n", str);
printf("%s\n", "test");
  free(str);
  return 0;
}
