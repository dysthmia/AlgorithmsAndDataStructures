#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 700000;
const int MAX_K = 8;

// good[k][n] = n можно разложить на k различных
// возрастающих множителей > 1
vector<vector<bool>> good(MAX_K + 1, vector<bool>(MAX_N + 1, false));

// product     - произведение уже выбранных множителей
// start       - минимальный следующий множитель
// remaining   - сколько множителей ещё нужно выбрать
// k           - исходное значение k
void dfs(long long product, int start, int remaining, int k) {
    if (remaining == 0) {
        good[k][product] = true;
        return;
    }

    for (int x = start; ; ++x) {
        // product * x не должно превышать MAX_N
        if (product > MAX_N / x) {
            break;
        }

        dfs(product * x, x + 1, remaining - 1, k);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // k = 1:
    // любое число > 1 является 1-интересным
    for (int n = 2; n <= MAX_N; ++n) {
        good[1][n] = true;
    }

    // Для k >= 2 перебираем все возрастающие последовательности.
    for (int k = 2; k <= MAX_K; ++k) {
        dfs(1, 2, k, k);
    }

    // pref[k][i] = количество k-интересных чисел на [1; i]
    vector<vector<int>> pref(
        MAX_K + 1,
        vector<int>(MAX_N + 1, 0)
    );

    for (int k = 1; k <= MAX_K; ++k) {
        for (int i = 1; i <= MAX_N; ++i) {
            pref[k][i] = pref[k][i - 1] + good[k][i];
        }
    }

    int q;
    cin >> q;

    while (q--) {
        int k, l, r;
        cin >> k >> l >> r;

        // k > 8 невозможно при n <= 700000
        if (k > MAX_K) {
            cout << 0 << '\n';
            continue;
        }

        cout << pref[k][r] - pref[k][l - 1] << '\n';
    }

    return 0;
}