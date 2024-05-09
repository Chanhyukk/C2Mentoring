#include <stdio.h>

void b (int *p) {
    printf("%d %d %d\n", p[0], p[-1], p[-2]);
    return;
}

int main() {
    int a[] = {0, 1, 2,3,4,5,6,7,8,9};
    int n = (int) (sizeof(a) / sizeof(int));
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    putchar('\n');
    b(a + n - 1);
    //a[]의 마지막 요소를 가리키는 포인터 전달함
    //마지막, 마지막 - 1, 마지막 - 2번째 요소 출력
    return 0;
}
