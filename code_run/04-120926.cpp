#include <iostream>
#include <vector>

using namespace std;

int main(){

    int n, m;
    cin >> n >> m;

    vector<vector<int>> a (n , vector<int>(m, 0));
    a[0][0] = 1;

    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (i+2<n && j+1<m){
                a[i+2][j+1] += a[i][j];
            } 
            if (i+1 < n && j+2 < m) {
                a[i+1][j+2] += a[i][j];
            }
        }
    }
    
    cout << a[n-1][m-1];
    
    return 0;
}