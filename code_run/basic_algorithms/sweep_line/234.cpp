#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() 
{
    int n, m;
    cin >> n >> m;

    vector<int> left;
    vector<int> right;

    while (n--){
        int64_t l, r; cin >> l >> r;
        if (l > r) swap(l, r);
        left.push_back(l);
        right.push_back(r);
    }

    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    for (int i=0; i<m; i++){
        int64_t point; cin >> point;
        // count = left (<= x) - right (< x)
        int l_side = upper_bound(left.begin(), left.end(), point) - left.begin();
        int r_side = lower_bound(right.begin(), right.end(), point) - right.begin();
        cout << l_side - r_side << " ";
    }

	return 0;
}
