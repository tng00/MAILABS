#include <stdio.h>
#include <assert.h>

#define INF (int)__builtin_inff()

int main() {
    int n;
    scanf("%d", &n);
    assert(n <= 8);
    int mat[n][n],
        MinElem = INF,
        RowNum = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &mat[i][j]);
            if (mat[i][j] < MinElem) {
                MinElem = mat[i][j];
                RowNum = i;
            }
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    for (int i = RowNum, j = 0; j < n / 2; ++j) {
        int t = mat[i][j];
        mat[i][j] = mat[i][n - 1 - j];
        mat[i][n - 1 - j] = t;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}
