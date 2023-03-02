#include <ctype.h>
#include <stdio.h>
int main(int argc, char *argv[]) {
    FILE *fp;
    if(argv[1]) {
        fp = fopen(argv[1], "r");
    } else {
        fp = stdin;
    }
    
    if(fp == NULL) {
        printf("AAAAAAAAAAa");
        return 1;
    }
    int charCount = 0;
    int lineCount = 0;
    int wordCount = 0;
    char next = fgetc(fp);
    while(!feof(fp) || (fp == stdin && next != '\n')) {
        printf("%d", next != '\n');
        charCount++;
        if(next == '\n') {
            lineCount++;
        }
        char temp = fgetc(fp);
        if(!((isspace(next) != 0 && isspace(temp) != 0) || (isspace(next) == 0 && isspace(temp) == 0))) {
            wordCount++;
        }
        next = temp;
    }
    printf(" %d %d %d\n", lineCount, wordCount/2, charCount);
    return 0;
}
