#include <cstdio>


int abs (int x) {
    return (x < 0) ? -x : x;
}

int mod (int x, int m) {
    int r = x - (x / m) * m;
    return (r >= 0) ? r : r + abs(m);
}

int main() {
    int n;
    scanf_s("%d", &n);
    int m71 = 0,
        m72 = 0,
        m1 = 0,
        m2 = 0,
        max1 = 0,
        max2 = 0;
    for (int i = 1; i <= n; ++i) {
        int x;
        scanf_s("%d", &x);
        if (mod(x, 7) == 0 && mod(x, 160) == mod(m71, 160) && x > m71) {
            m71 = x;
        } else if (mod(x, 7) == 0 && mod(x, 160) != mod(m71, 160) && x > m71) {
            m72 = m71;
            m71 = x;
        } else if (mod(x, 7) == 0 && mod(x, 160) != mod(m71, 160) && x > m72) {
            m72 = x;
        } else if (mod(x, 7) != 0 && mod(x, 160) == mod(m1, 160) && x > m1) {
            m1 = x;
        } else if (mod(x, 7) != 0 && mod(x, 160) != mod(m1, 160) && x > m1) {
            m2 = m1;
            m1 = x;
        } else if (mod(x, 7) != 0 && mod(x, 160) != mod(m1, 160) && x > m2) {
            m2 = x;
        }
    }

    if (m71 == 0 && m72 == 0) {
        printf_s("%d %d", 0, 0);
    } else if (m72 == 0 && m2 == 0 && mod(m71, 160) == mod(m1, 160)) {
        printf_s("%d %d", 0, 0);
    } else {
        if (m71 + m72 > max1 + max2) {
            max1 = m71;
            max2 = m72;
        }
        if (m71 + m1 > max1 + max2 && mod(m71, 160) != mod(m1, 160)) {
            max1 = m71;
            max2 = m1;
        }
        if (m71 + m2 > max1 + max2 && mod(m71, 160) != mod(m2, 160)) {
            max1 = m71;
            max2 = m2;
        }
        printf_s("%d %d", max1, max2);
    }

}
