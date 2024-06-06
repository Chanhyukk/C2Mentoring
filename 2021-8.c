#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    FILE *fp;
    int len = 0, wordcount = 0, charcount = 0, wordcon = 0;
    int c;
    if(argc > 1) {
        fp = fopen(*++argv, "r");
        while ((c = getc(fp)) != EOF) {
            putchar(c);
            charcount++;
            if (c == '\n') {
                len++;
            }
            if (isspace(c)) {
                if (wordcon) {
                    wordcount++;
                    wordcon = 0;
                }
            }
            else {
                wordcon = 1;
            }
        }
        fclose(fp);
        printf("%d %d %d %s\n", len, wordcount, charcount, *argv);
    }
    return 0;
}
