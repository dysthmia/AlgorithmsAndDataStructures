#include <iostream>
#include <vector>

using namespace std;

int main() 
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> pref (n+1, vector<int>(m+1,0));

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {

            int element;
            cin >> element;

            pref[i][j] = element + pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1];
        }
    }

    while (k--){

        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int sum = pref[x2][y2] - pref[x1-1][y2] - pref[x2][y1-1] + pref[x1-1][y1-1];
        cout << sum << "\n";
    }

	return 0;
}
