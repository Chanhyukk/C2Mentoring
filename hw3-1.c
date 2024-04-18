#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
    int row, num1, num2;
    row = atoi(argv[1]);
    int arr[row][5];
    if (strcmp(argv[2], "-r") == 0) {
        num1 = atoi(argv[3]);
        num2 = atoi(argv[4]);
        for (int i = 0; i < row && num2 > num1; i++) {
            for (int j = 0; j < 5; j++) {
                arr[i][j] = num2;
                num2--;
            }
        }
    }
    else {
        num1 = atoi(argv[2]);
        num2 = atoi(argv[3]);
        for (int i = 0; i < row && num1 < num2; i++) {
            for (int j = 0; j < 5; j++) {
                arr[i][j] = num1;
                num1++;
            }
        }
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}
