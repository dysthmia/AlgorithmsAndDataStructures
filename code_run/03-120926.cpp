#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {

    int n, m;
    cin >> n >> m;

    vector<vector<int>> a (n, vector<int>(m));
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin >> a[i][j];
        }
    }

    vector<vector<char>> p (n, vector<char>(m));
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (i==0 && j==0){
            } else if (i==0){
                a[i][j] += a[i][j-1];
                p[i][j] = 'L';
            } else if (j==0){
                a[i][j] += a[i-1][j];
                p[i][j] = 'U';
            } else {
                if (a[i-1][j] >= a[i][j-1]){
                    a[i][j] += a[i-1][j];
                    p[i][j] = 'U';
                } else {
                    a[i][j] += a[i][j-1];
                    p[i][j] = 'L';
                }
            }
        }
    }

    string s;
    int i = n-1, j = m-1;
    while (i!=0 || j!=0){
        if (p[i][j] == 'U'){
            s += "D ";
            i--;
        } else {
            s+= "R ";
            j--;
        }
    }
    reverse(s.begin(),s.end());

    cout << a[n-1][m-1]<<"\n";
    cout << s << "\n";

    return 0;
}