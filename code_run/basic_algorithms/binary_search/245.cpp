#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());

    int k;
    cin >> k;

    while (k--) {
        int p;
        cin >> p;

        int ans = lower_bound(a.begin(), a.end(), p) - a.begin();
        cout << ans << '\n';
    }

    return 0;
}