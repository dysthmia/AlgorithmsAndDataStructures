#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

const int p = 31;
const int64_t mod = 1e9+7;

vector<int64_t> pref;
vector<int64_t> powr;

void fill(const string& s, int n) {
    pref.resize(n+1);
    powr.resize(n+1);
    powr[0] = 1;
    for (int i=1; i<=n; i++) {
        pref[i] = (pref[i-1] * p + (s[i-1] - 'a' + 1))%mod;
        powr[i] = (powr[i-1]*p)%mod;
    }
}

int64_t get_hash (int l, int r) {
    return ((pref[r] - pref[l-1] * powr[r-l+1])%mod + mod)%mod;
}

int main () {
    string s; cin >> s;
    int n = s.size();

    fill(s, n);

    unordered_set<int64_t> all_hashes (n*(n+1)/2);
    for (int i=1; i<n; i++) {
        for (int j=i; j<n-1; j++) {
            all_hashes.insert(get_hash(i, j));
        }
    }

    cout << all_hashes.size() << '\n';
    return 0;
}

