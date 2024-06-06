#include <stdio.h>

int min (int x, int y) {
    if (x > y) {
        return y;
    }
    else {
        return x;
    }
}


int main() {
    int n1, n2;
    scanf("%d %d", &n1, &n2);
    int gcd, lcm;
    for (int i = 1; i < min(n1, n2); i++) {
        if (n1 % i == 0 && n2 % i == 0) {
            gcd = i;
        }
    }
    lcm = gcd * (n1 / gcd) * (n2 / gcd);
    printf("%d\n", gcd);
    printf("%d\n", lcm);
    return 0;
}
