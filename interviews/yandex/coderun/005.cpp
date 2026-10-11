#include <iostream>
#include <set>

using namespace std;

int main () {
    int n, m; 
    cin >> n >> m;

    set<int> left, right;

    while (n--) {
        int a, b;
        cin >> a >> b;
        left.insert(a);
        right.insert(b);
    }

    for (int i=0; i<m; i++) {
        int x; cin >> x;

        auto left_it = left.upper_bound(x);
        auto right_it = right.lower_bound(x);

        int count_l = distance(left.begin(), left_it);
        int count_r = distance(right.begin(), right_it);

        int ans = count_l - count_r;

        cout << ans << ' ';
    }

    return 0;
}