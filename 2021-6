#include <stdio.h>

long fiv(int n) {
    if (n < 3) {
        return 1;
    }
    else {
        return fiv(n - 1) + fiv(n - 2);
    }
}

int main() {
    long a, b;
    int x = 1;
    int count = 0;
    scanf("%ld %ld", &a, &b);
    if (0 <= a && a <= b && b <= 1000000000) {
        while (fiv(x) <= b) {
            if (a <= fiv(x)) {
                printf("%ld ", fiv(x));
                count++;
            }
            x++;
        }
    }
    printf("\n%d\n", count);
    return 0;
}
