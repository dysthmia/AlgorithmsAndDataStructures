#include <iostream>
#include <cstdint>
#include <vector>
#include <climits>

using namespace std;

int main() 
{
    int n, k;
    cin >> n >> k;

    vector<int> nv(n);
    for (int i = 0; i < n; i++) {
        cin >> nv[i];
    }

    vector<int> kv(k);
    for (int i = 0; i < k; i++) {
        cin >> kv[i];
    }

    for (int i = 0; i < k; i++) {

        int element = kv[i];

        int b_min = INT32_MAX;
        long long min_r = LLONG_MAX;

        int l = 0, r = n - 1;

        while (l <= r) {
            int mid = (l + r) / 2;

            if (nv[mid] < element) {
                l = mid + 1;
            }
            else if (nv[mid] > element) {
                r = mid - 1;
            }
            else {
                b_min = element;
                break;
            }

            long long diff = (long long)element - nv[mid];
            if (diff < 0) {
                diff = -diff;
            }

            if (diff < min_r || (diff == min_r && nv[mid] < b_min)) {
                min_r = diff;
                b_min = nv[mid];
            }
        }

        cout << b_min << "\n";
    }

    return 0;
}