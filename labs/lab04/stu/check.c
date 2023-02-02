#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char * argv[]){
  //TODO: Complete the program 

  //ERROR string for you to use to pass automated tests (print stderrr!)
  //  -- "ERROR: require credit card number\n"
  if(argc == 1) {
    printf("%d", )
    fprintf(stderr, "ERROR: require credit card number\n");
    return 1;
  }

  //  -- "ERROR: Invalid credit card number: Bad Length\n"
  if(strlen(argv[0]) != 16) {
    fprintf(stderr, "ERROR: require credit card number\n");
    return 2;
  }
  //  -- "ERROR: Invalid credit card number: Bad number '%c'\n"
  for(int i = 0; i < strlen(argv[0]); i++) {
    if(!(argv[0][i] >= '0' && argv[0][i] <= '9')) {
      fprintf(stderr, "ERROR: Invalid credit card number: Bad number '%c'\n", argv[0][i]);
      return 2;
    }
  }

  // OUTPUT strinsg for you to use to pass automated tests
  //  --  printf("VALID\n");
  //  -- printf("INVALID\n");
  int total = 0;
  for(int i = 0; i < strlen(argv[0]); i++) {
    int val = argv[0][i] - '0';
    if(val*2 > 9) {
      val = val % 10 + 1;
    }
    total += val;
  }

  if(total%10 == 0) {
    printf("VALID\n");
  } else {
    printf("INVALID\n");
  }


  // RETURN values to use
  //  -- return 0 : valid credit card number
  //  -- return 1 : error occured
  //  -- return 2 : invalid credit card number


}
