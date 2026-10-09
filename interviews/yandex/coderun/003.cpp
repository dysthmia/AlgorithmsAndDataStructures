// минимум в плавающем окне

#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int n, k; cin >> n >> k;
    
    vector<int> v(n);
    for (int i=0; i<n; i++){
        cin >> v[i];
    }

    int left = 0, right = 0;
    multiset<int> now;

    while (right < n) {
        while (right<n && right < left + k) {
            now.insert(v[right]);
            right++;
        }
        cout << *now.begin() << '\n';
        now.erase(v[left]);
        left++;
    }

    return 0;
}