#include <iostream>
#include <vector>

using namespace std;

void print_m (const vector<vector<int>>& v,int n ,int m ){
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cout << v[i][j] << " ";
        }
        cout << "\n";
    }
}

int main(){

    int n; cin >> n; 
    vector<int> a(n);
    for (int i=0; i<n; i++){
        cin >> a[i];
    }

    int m; cin >> m; 
    vector<int> b(m);
    for (int i=0; i<m; i++){
        cin >> b[i];
    }

    vector<vector<int>> dp (n, vector<int>(m,0));

    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (a[i] == b[j]) {
                dp[i][j] = (i==0 || j==0) ? 1 : dp[i-1][j-1] + 1;
            } else {
                int up = (i>0) ? dp[i-1][j] : 0;
                int left = (j>0) ? dp[i][j-1] : 0;
                dp[i][j] = max(up,left);
            }
        }
    }

    int i = n-1, j = m - 1;
    
    vector<int> s;

    while (i >= 0 && j >= 0) {
        if (a[i] == b[j]) {
            s.push_back(a[i]);
            i--; j--;
        } else if (i > 0 && (j == 0 || dp[i-1][j] >= dp[i][j-1])) {
            i--;
        } else {
            j--;
        }
    }

    reverse(s.begin(), s.end());

    for (int k = 0; k < (int)s.size(); k++) {
        if (k > 0) cout << " ";
        cout << s[k];
    }

    return 0;
}