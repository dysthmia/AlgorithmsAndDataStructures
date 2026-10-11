#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
    
    int n; cin >> n;

    vector<int> alph (n);
    for (int i=0; i<n; i++) cin >> alph[i];

    int coolest = 0;
    for (int i=0; i<n-1; i++) {
        coolest += min(alph[i], alph[i+1]);
    }

    cout << coolest;

    return 0;
}