#include <ctype.h>
#include <stdio.h>
int main(int argc, char *argv[]) {
    FILE *fp = fopen(argv[1], "r");
    if(fp == NULL) {
        return 1;
    }
    int charCount = 0;
    int lineCount = 0;
    int wordCount = 0;
    char next = fgetc(fp);
    int prevSpace = isspace(next);
    while(!feof(fp)) {
        if(next == '\n') {
            lineCount++;
        }
        charCount++;
        next = fgetc(fp);
        if(isspace(next) && prevSpace) {
            wordCount++;
        } 
    }
    printf(" %d %d %d\n", lineCount, wordCount, charCount);
    return 0;
}
