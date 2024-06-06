#include <stdio.h>
#include <string.h>

// Bubble sort function to sort array of strings
void bsort(int n, char *arr[]) {
    char *temp;
    for (int j = 0; j < n - 1; j++) {
        for (int i = j + 1; i < n; i++) {
            if (strcmp(arr[j], arr[i]) > 0) {
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("No arguments provided.\n");
        return 1;
    }
    if (strcmp(argv[1], "-r") == 0) {
        bsort(argc - 2, argv);
        for (int i = argc - 1; i > 1; i--) {
            printf("%s ", argv[i]);
        }
    }
    else {
        bsort(argc - 1, argv);
        for (int i = 1; i < argc; i++) {
            printf("%s ", argv[i]);
        }
    }
    printf("\n");
    return 0;
}
