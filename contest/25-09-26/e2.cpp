#include <iostream>
#include <string>
#include <vector>

/*
	    используем полиномиальный хэш
        ищем хэш подстроки    
*/

using namespace std;

const int p = 31;
const int64_t mod = 1e9+7;
vector<int64_t> pref;
vector<int64_t> pow_p;

// vector<int> get_pref_sum(const vector<int>& alph) {
// 	vector<int> pref_sum (alph.size()+1);
// 	for (int i=1; i<=alph.size(); i++) {
// 		pref_sum[i] += pref_sum[i-1] + alph[i-1];
// 	}
// 	return pref_sum;
// }

vector<int64_t> get_alph(const string& s) {
	vector<int64_t> alph (s.size()+1);
	for (int i=1; i<=s.size(); i++) {
    	alph[i] = (alph[i-1] * p + (s[i-1]-'a'+1)) % mod;
	}
	return alph;
}

int64_t get_hash (int l, int r) {
    int64_t hash = ((pref[r] - pref[l-1] * pow_p[r-l+1]) % mod + mod)%mod;
    return hash;
}

int main () {
	string s; cin >> s;
	pref = get_alph(s);
	
    pow_p.resize(s.size()+1);
    pow_p[0] = 1;
    for (int i = 1; i <= s.size(); i++) {
        pow_p[i] = (pow_p[i-1] * p) % mod;
    }

	int m; cin >> m;
	while (m--) {
    	int a, b, c, d;
    	cin >> a >> b >> c >> d;
    	
    	int64_t sum1 = get_hash(a, b);
       	int64_t sum2 = get_hash(c, d);
    
    	if (sum1==sum2) {
    		cout << "Yes" << '\n';
        } else cout << "No" << '\n';
	}
	return 0;
}