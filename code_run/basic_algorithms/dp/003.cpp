#include <iostream>
#include <vector>
#include <string>

using namespace std;

void printm (const vector<vector<int>>& a){
    int rows = a.size();
    int cols = a[0].size();
    for (int i=0; i<rows; i++){
        for (int j=0; j<cols; j++){
            cout << a[i][j] << " ";
        }
        cout << '\n';
    }
}

int main () {

    int n, m;
    cin >> n >> m;

    vector<vector<int>> a (n, vector<int> (m));
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin >> a[i][j];
        }
    }

    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (i==0 && j==0) continue;
            if (i!=0 && j==0) a[i][j] += a[i-1][j];
            if (i==0 && j!=0) a[i][j] += a[i][j-1];
            if (i!=0 && j!=0) a[i][j] += max(a[i-1][j], a[i][j-1]);
        }
    }

    cout << a[n-1][m-1] << '\n';

    string s;
    int r = n-1, c = m-1;
    while (r!=0 && c!=0){
        if (a[r-1][c] > a[r][c-1]){
            s += 'D';
            r--;
        }
        else {
            s += 'R';
            c--;
        }
        s+=' ';
    }

    while (r!=0){
        s += 'D';
        r--;
        s+=' ';
    }

    while (c!=0){
        s += 'R';
        c--;
        s+=' ';
    }

    s.pop_back();
    reverse(s.begin(),s.end());
    
    cout << s << '\n';
    return 0;
}