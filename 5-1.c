#include <stdio.h>
#include <string.h>

void swap(int v[], int i, int j) {
    int temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void qsort(int v[], int left, int right) {
    int i, last;
    if (left >= right) {
        return;
    }
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++) {
        if (v[i] < v[left]) {
            swap(v, ++last, i);
        }
    }
    swap(v, left, last);
    qsort(v, left, last - 1);
    qsort(v, last + 1, right);
}

int main(int argc, char *argv[]) {
    char c;
    int arr[100];
    int i = 0;
    int sum = 0;
    while ((c = getchar()) != EOF) {
        if (c >= '0' && c <= '9') {
            sum = sum * 10 + c - '0';
        }
        else if (c == '\n') {
            arr[i] = sum;
            i++;
            sum = 0;
        }
    }
    arr[i] = '\0';
    printf("\nAfter Sort.\n");
    qsort(arr, 0, i - 1);
    if (strcmp(argv[argc - 1], "-n") == 0) {
        for (int j = i - 1; j > -1; j--) {
            printf("%d ", arr[j]);
        }
    }
    else {
        for (int j = 0; j < i; j++) {
            printf("%d ", arr[j]);
        }
    }

    return 0;
}
