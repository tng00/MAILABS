#include <stdio.h>
#include <assert.h>

void swap(int* a, int* b) {
    int c = *a;
    *a = *b;
    *b = c;
}

int main() {
    int n, i, j, k;
    scanf("%d", &n);
    assert(n >= 1 && n <= 7);
    int mat[n][n];
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            scanf("%d", &mat[i][j]);
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    for (k = 0; k < 2 * n - 1; ++k) {
        if (k < n) {
            i = 0;
            j = k;
        } else {
            i = k - n + 1;
            j = n - 1;
        }

        if (k % 2 != 0) {
            for (; i < n && j >= 0; ++i, --j) {
                printf("%d ", mat[i][j]);
            }
        }
        else {
            swap(&i, &j);
            for (; i >= 0 && j < n; --i, ++j) {
                printf("%d ", mat[i][j]);
            }
        }
    }
}
