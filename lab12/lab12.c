#include <stdio.h>
#include <stdlib.h>

int my_abs(int x) {
    return (x < 0) ? -x : x;
}

int main() {
    u_int arr[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int n;
    while (scanf("%d", &n) != EOF) {
        int num = my_abs(n);
        if (!num) {
            arr[num] |= 1u;
        } else {
            while (num > 0) {
                int digit = num % 10;
                arr[digit] |= 1u;
                num /= 10;
            }
        }
    }

    u_int res = 1;
    for (int i = 0; i < 10; ++i) {
        res &= arr[i];
    }

    if (res) {
        printf("ALL DIGITS DETECTED");
    } else {
        printf("SOME DIGITS ARE MISSING");
        int flag = 1;
        for (int i = 0; i < 10; ++i) {
            if (!arr[i]) {
                if (flag) {
                    printf(": %d", i);
                    flag = 0;
                } else {
                    printf(", %d", i);
                }
            }
        }
        printf(".");
    }
}
