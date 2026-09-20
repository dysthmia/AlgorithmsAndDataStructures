#include <iostream>
#include <vector>

using namespace std;

int main() {
    
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Сжатие цветов на случай, если они не от 1 до K
    vector<int> vals = a;
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());

    for (int &x : a) {
        x = lower_bound(vals.begin(), vals.end(), x) - vals.begin();
    }

    int m = vals.size();
    vector<int> cnt(m, 0);

    int l = 0;
    int distinct = 0;
    int bestL = 0, bestR = n - 1;
    int bestLen = n + 1;

    for (int r = 0; r < n; r++) {
        int color = a[r];

        if (cnt[color] == 0) {
            distinct++;
        }
        cnt[color]++;

        while (distinct == k) {
            int len = r - l + 1;

            if (len < bestLen) {
                bestLen = len;
                bestL = l;
                bestR = r;
            }

            int leftColor = a[l];
            cnt[leftColor]--;

            if (cnt[leftColor] == 0) {
                distinct--;
            }

            l++;
        }
    }

    cout << bestL + 1 << ' ' << bestR + 1 << '\n';

    return 0;
}