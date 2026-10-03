#include <iostream>
#include <vector>

using namespace std;

/*
        1 вариант: 2 вниз, 1 вправо
        2 вариант: 1 вниз, 2 вправо
*/

int main () {

    int n, m;
    cin >> n >> m;

    vector<vector<int>> dp (n, vector<int>(m));
    dp[0][0] = 1;

    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (i+2<n && j+1<m){
                dp[i+2][j+1] += dp[i][j];
            }
            if (i+1<n && j+2<m){
                dp[i+1][j+2] += dp[i][j];
            }
        }
    }

    cout << dp[n-1][m-1] << '\n';
    return 0;
}