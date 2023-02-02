#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check1(char * str);
int check2(char * str1);

int check1(char *str){
  for(int i = 0; i < strlen(str); i ++) {
    if(str[i] != str[strlen(str)-1 - i]) {
      return 0;
    }
  }
  return 1;
}

int check2(char *str1){
  char str2[1024]; //string to copy to
  for(int i = 0; i < strlen(str1); i++) {
    str2[i] = str1[strlen(str1)-1 - i];
  }
  str2[strlen(str1)] = '\0';
  return !strcmp(str1, str2);
}

int main(int argc, char * argv[]){

  char str[1024];

  printf("Enter a string:\n");

  scanf("%1023s",str);
  
  if(check1(str)){
    printf("Palindrome according to check 1\n");
  }else{
    printf("NOT a palindrome according to check 1\n");
  }
   

  if(check2(str)){
    printf("Palindrome according to check 2\n");
  }else{
    printf("NOT a palindrome according to check 2\n");
  }
  
}
