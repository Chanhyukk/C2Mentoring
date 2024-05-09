#include <stdio.h>

int main() {
    int a[] = {1, 2, 3, 4, 5};
    int *p = a;
    for (int i = 0; i < 5; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    while (p - a < 5) {
        printf("%d ", *(p++));
    }
    return 0;
}
