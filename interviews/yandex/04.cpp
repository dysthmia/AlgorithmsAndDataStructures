#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

int main() {
    
    int n, k;
    cin >> n >> k;

    vector<long double> a(n);

    for (auto& x : a) {
        cin >> x;
    }

    long double left = 0.0L;
    long double right = *max_element(a.begin(), a.end());

    for (int it = 0; it < 200; ++it) {
        long double mid = (left + right) / 2.0L;

        long double need = 0.0L;

        for (long double x : a) {
            if (x > mid) {
                need += 1.0L - mid / x;
            }
        }

        if (need <= k) {
            right = mid;
        } else {
            left = mid;
        }
    }

    long double answer = 2.0L * right;

    cout << fixed << setprecision(12) << answer << '\n';

    return 0;
}