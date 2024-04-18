#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
    int row, column, num1, num2;
    row = atoi(argv[1]);
    if (strcmp(argv[2], "-r") == 0) {
        num1 = atoi(argv[3]);
        num2 = atoi(argv[4]);
        column = (num2 - num1 + 1) / row;
        int arr[row][column];
        for (int i = 0; i < row && num2 > num1; i++) {
            for (int j = 0; j < column; j++) {
                arr[i][j] = num2;
                num2--;
            }
        }
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
            }
            printf("\n");
        }
    }
    else {
        num1 = atoi(argv[2]);
        num2 = atoi(argv[3]);
        column = (num2 - num1 + 1) / row;
        printf("%d\n", column);
        int arr[row][column];
        for (int i = 0; i < row && num1 < num2; i++) {
            for (int j = 0; j < column; j++) {
                arr[i][j] = num1;
                num1++;
            }
        }
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                printf("%d ", arr[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
