#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct tnode {
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
} Tree;

Tree *addTree(Tree *p, char *w) {
    int cond;
    if (!p) {
        p = (Tree*)malloc(sizeof(Tree));
        p->word = strdup(w);
        p->count = 1;
        p->left = NULL;
        p->right = NULL;
    }
    else if ((cond = strcmp(w, p->word)) == 0) {
        p->count++;
    }
    else if (cond < 0) {
        p->left = addTree(p->left, w);
    }
    else {
        p->right = addTree(p->right, w);
    }
    return p;
}

void treePrint(Tree *p) {
    static int i = 0;
    if (p) {
        treePrint(p->left);
        printf("%-4d %-15s\t\t", p->count, p->word);
        if (++i % 6 == 0) {
            printf("\n");
        }
        treePrint(p->right);
    }
}

void freeTree(Tree *p) {
    if (p) {
        freeTree(p->left);
        freeTree(p->right);
        free(p->word);
        free(p);
    }
}

int getword(FILE *fp, char *word) {
    char c;
    int cond = 0;
    while ((c = fgetc(fp)) != EOF) {
        if (isalpha(c)) {
            *word++ = c;
            cond = 1;
        }
        else {
            if (cond) {
                break;
            }
        }
    }
    *word = '\0';
    if (cond) {
        return 1;
    }
    else {
        return 0;
    }
}

int main() {
    FILE *fp = fopen("alice.txt", "r");
    if (fp == NULL) {
        printf("ERROR\n");
        return 1;
    }
    Tree *root = NULL;
    char word[100];
    while (getword(fp, word)) {
        root = addTree(root, word);
    }
    treePrint(root);
    freeTree(root);
    fclose(fp);
    return 0;
}
