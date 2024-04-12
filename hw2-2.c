#include <stdio.h>

void printnum(int n) {
    if (n > 0) {
        int temp = n;
        int digit = 0;
        while (temp != 0) {
            digit++;
            temp /= 10;
        }
        char arr[digit];
        for (int i = digit - 1; i > -1; i--) {
            arr[i] = (n % 10);
            n /= 10;
        }
        for (int i = 0; i < digit; i++) {
            putchar(arr[i] + '0');
        }
    }
    else if (n < 0) {
        n *= -1;
        int temp = n;
        int digit = 0;
        while (temp != 0) {
            digit++;
            temp /= 10;
        }
        char arr[digit];
        for (int i = digit - 1; i > -1; i--) {
            arr[i] = (n % 10);
            n /= 10;
        }
        putchar('-');
        for (int i = 0; i < digit; i++) {
            putchar(arr[i] + '0');
        }
    }
    else {
        putchar('0');
    }
}

int calculator(int n, int prime, char op) {
    int sum = 0;
    switch (op) {
        case '+':
            sum = n + prime;
            break;
        case '-':
            sum = n - prime;
            break;
        case '*':
            sum = n * prime;
            break;
        case '/':
            sum = n / prime;
            break;
        case '%':
            sum = n % prime;
            break;
    }
    return sum;
}

int main() {
    int num = 0;
    char c;
    char ope = '\0';
    while ((c = getchar()) != EOF) {
        if (c >= '0' && c <= '9') {
            num = num * 10 + (c - '0');
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%') {
            ope = c;
            break;
        }
    }
    int primecount = 0;
    for (int i = 2; primecount < 10; i++) {
        int prime = 1;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                prime = 0;
                break;
            }
        }
        if (prime == 1) {
            primecount++;
            printnum(num);
            putchar(' ');
            putchar(ope);
            putchar(' ');
            printnum(i);
            putchar(' ');
            putchar('=');
            putchar(' ');
            printnum(calculator(num, i, ope));
            putchar('\n');
        }
    }
    return 0;
}
