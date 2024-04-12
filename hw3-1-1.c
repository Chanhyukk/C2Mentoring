#include <stdio.h>

int main() {
    int hex;
    int temp;
    int digit;
    int j;
    int count;
    for (int i = 33; i < 127; i += 6) {
        j = i;
        while (j < 127 && count < 6) {
            temp = j;
            digit = 1;
            hex = 0;
            while (temp > 0) {
                hex = hex + (temp % 16) * digit;
                temp /= 16;
                digit *= 10;
            }
            printf("%d %d %c ", j, hex, j);
            count++;
            j++;
        }
        printf("\n");
    }
    return 0;
}
