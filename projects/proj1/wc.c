#include <ctype.h>
#include <stdio.h>
int main(int argc, char *argv[]) {
<<<<<<< HEAD
    FILE **files = FILE*[argc];
    for(int i = 0; i < argc; i++) {

    }
    FILE *fp = fopen(argv[1], "r");
=======
    FILE *fp;
    if(argv[1]) {
        fp = fopen(argv[1], "r");
    } else {
        fp = stdin;
    }
    
>>>>>>> 0aab333c00d44371bcd43489ff74831e9a0c0dfa
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
