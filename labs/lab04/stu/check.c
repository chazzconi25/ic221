#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char * argv[]){
  //TODO: Complete the program 

  //ERROR string for you to use to pass automated tests (print stderrr!)
  //  -- "ERROR: require credit card number\n"
  if(argc == 1) {
    fprintf(stderr, "ERROR: require credit card number\n");
    return 1;
  }

  //  -- "ERROR: Invalid credit card number: Bad Length\n"
  if(strlen(argv[1]) != 16) {
    fprintf(stderr, "ERROR: Invalid credit card number: Bad Length\n");
    return 1;
  }
  //  -- "ERROR: Invalid credit card number: Bad number '%c'\n"
  for(int i = 0; i < strlen(argv[1]); i++) {
    if(!(argv[1][i] >= '0' && argv[1][i] <= '9')) {
      fprintf(stderr, "ERROR: Invalid credit card number: Bad number '%c'\n", argv[1][i]);
      return 1;
    }
  }

  // OUTPUT strinsg for you to use to pass automated tests
  //  --  printf("VALID\n");
  //  -- printf("INVALID\n");
  int total = 0;
  for(int i = 0; i < strlen(argv[1]); i++) {
    int val = argv[1][i] - '0';    
    if(i % 2 == 0) {
      val *= 2;
      if(val*2 > 9) {
        val = val% 10 + 1;
      }
    }
    total += val;
  }

  if(total%10 == 0) {
    printf("VALID\n");
    return 0;
  } else {
    printf("INVALID\n");
    return 2;
  }


  // RETURN values to use
  //  -- return 0 : valid credit card number
  //  -- return 1 : error occured
  //  -- return 2 : invalid credit card number


}
