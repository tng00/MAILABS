#include <stdio.h>
#include <assert.h>

int main() {
    int n;
    scanf("%d", &n);
    assert(n <= 7);
    int mat[n][n];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &mat[i][j]);
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    int k = 0,
        cells = 0,
        i;
    while (cells < n * n) {
        for (i = k; i <= n - 1 - k; ++i) {
            printf("%d ", mat[k][i]);
            ++cells;
        }
        for (i = k + 1; i <= n - 1 - k; ++i) {
            printf("%d ", mat[i][n - 1 - k]);
            ++cells;
        }
        for (i = n - 2 - k; i >= k; --i) {
            printf("%d ", mat[n - 1 - k][i]);
            ++cells;
        }
        for (i = n - 2 - k; i >= 1 + k; --i) {
            printf("%d ", mat[i][k]);
            ++cells;
        }
        ++k;
    }
}
