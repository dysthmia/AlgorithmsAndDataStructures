#include <iostream>
#include <vector>

using namespace std;

int main () {

    int n, k;
    cin >> n >> k;

    vector<int> v (n);
    for (int i=0; i<n; i++){
        cin >> v[i];
    }

    int sum = 0, count = 0;
    int l = 0;

    for (int r = 0; r<n; r++){
        sum += v[r];

        while (sum > k && l <= r){
            sum -= v[l];
            l++;
        }

        if (sum == k){
            count++;
        }
    }

    cout << count << "\n";

    return 0;
}