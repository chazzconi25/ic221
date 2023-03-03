#include <ctype.h>
#include <stdio.h>

void printer(char* name, int lineCount, int wordCount,
        int charCount, int lines, int words, int chars);

int main(int argc, char *argv[]) {
    int retVal = 0, lines = 0, words = 0, chars = 0, i = 1;
    int totalLines = 0, totalWords = 0, totalChars = 0;
    for(i=i;i < argc && argv[i][0] == '-'; i++) {
        if(argv[i][1] == 'l') {
            lines = 1;
        } else if(argv[i][1] == 'w') {
            words = 1;
        } else if(argv[i][1] == 'c') {
            chars = 1;
        } else {
            fprintf(stderr, "ERROR: unknown option \'%s\'\n", argv[i]);
            return 2;
        }
    }
    if(argc - i == 0) {
        argc = 1;
        i = 0;
    }
    for(i=i; i < argc; i++) {
        FILE *fp;
        char *name;
        if(argc == 1 || argv[i][0] == '+') {
            fp = stdin;
            name = "-stdin-";
        } else {
            fp = fopen(argv[i], "r");
            name = argv[i];
        }
        if(fp == NULL) {
            fprintf(stderr, "ERROR: file \'%s\' cannot be opened\n", name);
            retVal = 1;
        } else {
            int charCount = 0;
            int lineCount = 0;
            int wordCount = 0;
            char next = fgetc(fp);
            while(!feof(fp) && fp != NULL) {
                charCount++;
                if(next == '\n') {
                    lineCount++;
                }
                char temp = fgetc(fp);
                if(!((isspace(next) != 0 && isspace(temp) != 0) || 
                    (isspace(next) == 0 && isspace(temp) == 0))) {
                    wordCount++;
                }
                next = temp;
            }
            printer(name, lineCount, wordCount, charCount,
                    lines, words, chars);
            totalChars += charCount;
            totalLines += lineCount;
            totalWords += wordCount;
        }
    }
    if(!(argc <= 2)) {
        printer("total", totalLines, totalWords, totalChars,
                lines, words, chars);
    }
    return retVal;
}

void printer(char* name, int lineCount, int wordCount,
        int charCount, int lines, int words, int chars) {
    printf("%s ", name);
    if(lines) {
        printf("%d ", lineCount);
    }
    if(words) {
        printf("%d ", wordCount/2);
    }
    if(chars) {
        printf("%d ", charCount);
    }
    if(!lines && !words && !chars) {
        printf("%d %d %d\n", lineCount, wordCount/2, charCount);
    } else {
        printf("\n");
    }
}