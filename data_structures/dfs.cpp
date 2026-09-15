#include <iostream>
#include <vector>

using namespace std;

bool dfs(int i, int j,const vector<vector<int>>& matrix, vector<vector<bool>>& visited ) {
    
    if (i<0 || i>=n || j<0 || j>=m) {
        return false;
    }
    if (matrix[i][j]==1 || visited[i][j]){
        return false;
    }
    if (i==finishI && j == finishJ){
        return true;
    }

    visited[i][j]=true;
    
    if (dfs(i-1,j,matrix,visited)){
        return true;
    }
    if (dfs(i,j+1,matrix,visited)){
        return true;
    }
    if (dfs(i+1,j,matrix,visited)){
        return true;
    }
    if (dfs(i,j-1,matrix,visited)){
        return true;
    }

    return false;
}

int n,m;
int startI, startJ, finishI, finishJ;

int main(){

    cin >> n >> m;
    cin >> startI >> startJ >> finishI >> finishJ;

    vector<vector<int>> matrix (n,vector<int>(m));
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin >> matrix[i][j];
        }
    }

    vector<vector<bool>> visited (n, vector<bool>(m));
    bool haveWay = dfs(startI, startJ, matrix, visited);
    cout << (haveWay ? "YES" : "NO");

    return 0;
}