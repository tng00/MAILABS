#include <stdio.h>
#include <stdlib.h>

int my_abs(int x) { // мои кубики
    return (x < 0) ? -x : x;
}

int main() {
    u_int AllDigits = 1023; // 1111111111b
    u_int found = 0;
    int n;
    while (scanf("%d", &n) != EOF) {
        int num = my_abs(n);
        if (!num) {
            found |= 1u;
        } else {
            while (num > 0) {
                u_int digit = num % 10;
                found |= 1u << digit;
                num /= 10;
            }
        }
    }



    if (found == AllDigits) {
        printf("ALL DIGITS DETECTED");
    } else {
        printf("SOME DIGITS ARE MISSING");
        u_int MissedDigits = found ^ AllDigits;
        int flag = 1;
        for (u_int i = 0; i < 10; ++i) {
            if ((1u << i) & MissedDigits) {
                if (flag) {
                    printf(": %d", i);
                    flag = 0;
                } else {
                    printf(", %d", i);
                }
            }
        }
        printf(".\n");
    }
}
