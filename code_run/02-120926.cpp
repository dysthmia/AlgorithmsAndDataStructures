#include <iostream>

using namespace std;

int main(){

    int n,m;
    cin >> n >> m;

    vector<vector<int>> vec (n, vector<int>(m));
    for (int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> vec[i][j];
        }
    }
    
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (i == 0 && j!=0){
                vec[i][j] += vec[i][j-1];
            } else if (j==0 && i!=0) {
                vec[i][j] += vec[i-1][j];
            } else if (i>0 && j>0) {
                vec[i][j] += min(vec[i-1][j],vec[i][j-1]);
            }
        }
    }

    cout << vec[n-1][m-1]<< "\n";

    return 0;
}