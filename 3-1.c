#include <stdio.h>

double add(char v[], int start, int end) {
    double number = 0.0;
    int point = -1;

    for (int i = start; i < end; i++) {
        if (v[i] >= '0' && v[i] <= '9') {
            number = number * 10 + (v[i] - '0');
        }
        if (v[i] == '.') {
            point = i;
            break;
        }
    }
    if (point != -1) {
        double fraction = 0.1;
        for (int i = point + 1; i < end; i++) {
            if (v[i] >= '0' && v[i] <= '9') {
                number += fraction * (v[i] - '0');
                fraction /= 10;
            }
        }
    }

    return number;
}

double cal(char a[], int n) {
    double num1;
    double num2;
    double sum;
    char ope;
    int i;
    for (i = 0; i < n; i++) {
        if (a[i] == '+' || a[i] == '-' || a[i] == '*' || a[i] == '/' || a[i] == '%') {
            ope = a[i];
            break;
        }
    }
    num1 = add(a, 0, i - 1);
    num2 = add(a, i + 2, n);
    switch(ope) {
        case '+':
            sum = num1 + num2;
            break;
        case '-':
            sum = num1 - num2;
            break;
        case '*':
            sum = num1 * num2;
            break;
        case '/':
            sum = num1 / num2;
            break;
        case '%':
            sum = (int) num1 % (int) num2;
            break;
    }
    return sum;
}

int main() {
    char c;
    int p = 0;
    int len;
    char arr[1000];
    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            arr[p] = '\0';
            len = p;
            p = 0;
            if ((int)cal(arr, len) == cal(arr, len)) {
                printf("%d\n", (int) cal(arr, len));
            }
            else {
                printf("%f\n", cal(arr, len));
            }
        }
        else {
            arr[p++] = c;
        }
    }
    return 0;
}
