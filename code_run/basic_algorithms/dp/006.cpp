#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){

    int n; cin >> n;
    vector<int> first(n);
    for (int i=0; i<n; i++){
        cin >> first[i];
    }

    int m; cin >> m;
    vector<int> second(m);
    for (int i=0; i<m; i++){
        cin >> second[i];
    }

    vector<vector<int>> dp (n+1,vector<int>(m));
    for (int i=1; i<n+1; i++){
        for (int j=1; j<m+1; j++){
            if (first[i-1]==second[j-1]){
                dp[i][j] += dp[i-1][j-1] + 1;
            } else if (dp[i-1][j] >= dp[i][j-1]){
                dp[i][j] = dp[i-1][j];
            } else dp[i][j] = dp[i][j-1];
        }
    }

    vector<int> ans (dp[n][m]);
    int l = n, w = m;
    while (l>0 && w>0) {
        if (first[l-1] == second[w-1]){
            ans.push_back(first[l-1]);
            l--; w--;
        } else if (dp[l-1][w] >= dp[l][w-1]){
            l--;
        } else w--;
    }

    reverse(ans.begin(), ans.end());

    for (int i=0; i<dp[n][m]; i++){
        cout << ans[i] << ' ';
    }
    cout << ' ';

    return 0;
}