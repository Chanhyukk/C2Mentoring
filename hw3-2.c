#include <stdio.h>

void swap(double* arr[], int left, int right) {
    double *temp;
    temp = arr[left];
    arr[left] = arr[right];
    arr[right] = temp;
}

int comp(double* a, double* b) {
    if (*a > *b) {
        return 1;
    }
    else if (*a == *b) {
        return 0;
    }
    else {
        return -1;
    }
}

void qsort(double* arr[], int start, int end, int (*comp)(double*, double*)) {
    int pivot;
    if (start >= end) {
        return;
    }
    swap(arr, start, (start + end) / 2);
    pivot = start;
    for (int i = start + 1; i <= end; i++) {
        if ((*comp)(arr[i], arr[start]) < 0) {
            swap(arr, ++pivot, i);
        }
    }
    swap(arr, start, pivot);
    qsort(arr, start, pivot - 1, comp);
    qsort(arr, pivot + 1, end, comp);
}

int main() {
    double arr[] = {1.1, 9.9, 2.2, 8.8, 3.3, 7.7, 4.4, 6.6, 5.5, 0.0};
    int size = sizeof(arr) / sizeof(arr[0]);
    double* arr_ptrs[size];
    for (int i = 0; i < size; i++) {
        printf("%.1f ", arr[i]);
    }
    printf("\n");
    for (int i = 0; i < size; i++) {
        arr_ptrs[i] = &arr[i];
    }
    qsort(arr_ptrs, 0, size - 1, comp);
    for (int i = 0; i < size; i++) {
        printf("%.1f ", *arr_ptrs[i]);
    }
    printf("\n");
    return 0;
}
