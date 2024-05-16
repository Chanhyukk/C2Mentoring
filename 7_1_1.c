#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

typedef struct tnode {
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
}Tree;

Tree *addtree(Tree *p, char *w)
{
    int cond;
    if(!p) {
        p = (Tree*)malloc(sizeof(Tree));
        p->word = strdup(w);
        p->count = 1;
        p->left = p->right = NULL;
    }
    else if((cond = strcmp(w, p->word)) == 0) {
        p->count++;
    }
    else if (cond < 0) {
        p->left = addtree(p->left, w);
    }
    else {
        p->right = addtree(p->right, w);
    }
    return p;
}

void treeprint(Tree *p)
{
    if (p !=NULL) {
        treeprint(p->left);
        printf("%4d %s\n", p->count, p->word);
        treeprint(p->right);
    }
}

int main() {
    char c;
    Tree *tree = NULL;
    char w[100];
    int i = 0;
    while ((c = getchar()) != EOF) {
        if (isalpha(c)) {
            w[i] = c;
            i++;
        }
        else {
            w[i] = '\0';
            tree = addtree(tree, w);
            i = 0;
        }
    }
    treeprint(tree);
    return 0;
}
