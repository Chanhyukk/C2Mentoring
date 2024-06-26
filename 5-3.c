#include <stdio.h>
#include <string.h>

int mystrlen(char *s) {
    int i;
    for (i = 0; *s != '\0'; i++) {
        s++;
    }
    return i;
}

int main() {
    char *s[] = {"This is Lab5", "Easy C Programming", "Have Fun"};
    printf("with strlen\n");
    int n = (int) (sizeof(s) / sizeof(char *));
    for (int i = 0; i < n; i++) {
        printf("%s %d\n", *(s + i), (int)strlen(s[i]));
    }
    putchar('\n');
    printf("without mystrlen\n");
    for (int i = 0; i < n; i++) {
        printf("%s %d\n", *(s + i), mystrlen(s[i]));
    }
    return 0;
}
