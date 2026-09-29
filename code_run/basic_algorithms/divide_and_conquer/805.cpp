#include <iostream>

using namespace std;

using int64 = long long;

int64 A, B, MOD;

// умножение двух матриц 2x2, результат в r
void mul(int64 x00, int64 x01, int64 x10, int64 x11,
         int64 y00, int64 y01, int64 y10, int64 y11,
         int64 &r00, int64 &r01, int64 &r10, int64 &r11) {
    r00 = (x00 * y00 + x01 * y10) % MOD;
    r01 = (x00 * y01 + x01 * y11) % MOD;
    r10 = (x10 * y00 + x11 * y10) % MOD;
    r11 = (x10 * y01 + x11 * y11) % MOD;
}

int main() {
    cin >> A >> B;
    cin >> MOD;

    A %= MOD;
    B %= MOD;

    int Q;
    cin >> Q;

    while (Q--) {
        int64 x, y, n;
        cin >> x >> y >> n;
        x %= MOD;
        y %= MOD;

        if (n == 0) { cout << x << '\n'; continue; }
        if (n == 1) { cout << y << '\n'; continue; }

        // Считаем T^(n-1), где T = [[A, B], [1, 0]]
        // result = единичная матрица
        int64 r00 = 1, r01 = 0, r10 = 0, r11 = 1;
        int64 b00 = A, b01 = B, b10 = 1, b11 = 0;

        int64 e = n - 1;
        while (e > 0) {
            if (e & 1) {
                int64 n00, n01, n10, n11;
                mul(r00, r01, r10, r11, b00, b01, b10, b11,
                    n00, n01, n10, n11);
                r00 = n00; r01 = n01; r10 = n10; r11 = n11;
            }
            int64 n00, n01, n10, n11;
            mul(b00, b01, b10, b11, b00, b01, b10, b11,
                n00, n01, n10, n11);
            b00 = n00; b01 = n01; b10 = n10; b11 = n11;
            e >>= 1;
        }

        // [F_n; F_{n-1}] = T^(n-1) * [F_1; F_0] = T^(n-1) * [y; x]
        int64 ans = (r00 * y + r01 * x) % MOD;
        cout << ans << '\n';
    }
    return 0;
}