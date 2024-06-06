#include <stdio.h>

int dtob(int n) {
    int bin = 0;
    int digit = 1;
    while (n > 0) {
        int temp = n % 2;
        n /= 2;
        bin = bin + digit * temp;
        digit *= 10;
    }
    return bin;
}

int main() {
    int demical;
    printf("Enter demical number: ");
    scanf("%d", &demical);
    printf("Binary number is: %d\n", dtob(demical));
    return 0;
}
