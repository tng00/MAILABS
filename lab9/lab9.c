#include <cstdio>


int min (int x, int y) {
    return (x < y) ? x : y;
}

int max (int x, int y) {
    return -min(-x, -y);
}

int sign (int x) {
    if (x < 0) {
        return -1;
    }
    if (x > 0) {
        return 1;
    }
    return 0;
}

int abs (int x) {
    return (x < 0) ? -x : x;
}

int mod (int x, int m) {
    int r = x - (x / m) * m;
    return (r >= 0) ? r : r + abs(m);
}

int main() {
    const int i0 = 1,
              j0 = -30,
              l0 = 1;
    int ip = i0,
        jp = j0,
        lp = l0, ik, jk, lk;
    for (int i = 1; i <= 50; ++i) {
        int k = i - 1;
        ik = max(min(ip + jp - lp - k, ip - jp + lp - k), min(k + ip - jp - lp, k - ip - jp + lp));
        jk = jp + mod(lp * sign(jp), 20) + mod(k * sign(ip), 10);
        lk = abs(ip - jp + lp - k) * sign(ip) * sign(jp);
        ip = ik,
        jp = jk,
        lp = lk;
        int res = (ik - 10) * (ik - 10) + (jk - 10) * (jk - 10);
        if (res >= 25 && res <= 100) {
            printf("Success at step #%d\n"
                   "Coordinates: (%d, %d)\n"
                   "Motion parameter: %d", i, ik, jk, lk);
            break;
        }
        if (i == 50) {
            printf("Fail\n"
                   "Coordinates: (%d, %d)\n"
                   "Motion parameter: %d", ik, jk, lk);
        }
    }

}
