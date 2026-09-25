#include <iostream>
#include <vector>

using namespace std;

int main() {

    int n, p, m;
    cin >> n >> p >> m;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long h = 0;

    for (int i = 0; i < n; i++) {
        h = (h * p + a[i]) % m;
    }

    cout << h << '\n';

    return 0;
}