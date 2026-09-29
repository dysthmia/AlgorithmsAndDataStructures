#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() 
{
    int n, d;
    cin >> n >> d;

    vector<pair<int,int>> a(n);
    int max_seat = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
        max_seat = max(max_seat, a[i].first);
    }

    vector<int> diff(max_seat + d + 2, 0);

    for (int i = 0; i < n; i++) {
        int l = a[i].first;
        int r = l + d + 1;
        diff[l]++;
        diff[r]--;
    }

    int variants = 0;
    int cur = 0;
    for (int i = 0; i <= max_seat; i++) {
        cur += diff[i];
        variants = max(variants, cur);
    }

    if (variants == 0) variants = 1;

    sort(a.begin(), a.end());

    vector<int> ans(n);
    for (int j = 0; j < n; j++) {
        int originalIndex = a[j].second;
        ans[originalIndex] = j % variants + 1;
    }

    cout << variants << '\n';
    for (int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';

    return 0;
}