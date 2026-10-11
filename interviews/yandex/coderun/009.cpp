#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    long long k;
    cin >> k;

    string s;
    cin >> s;
    int n = (int)s.size();

    long long best = 0;

    for (char c = 'a'; c <= 'z'; ++c) {
        int l = 0;
        long long bad = 0;  // сколько символов в [l, r] не равны c

        for (int r = 0; r < n; ++r) {
            if (s[r] != c) ++bad;

            while (bad > k) {
                if (s[l] != c) --bad;
                ++l;
            }

            best = max(best, (long long)(r - l + 1));
        }
    }

    cout << best << '\n';
    return 0;
}