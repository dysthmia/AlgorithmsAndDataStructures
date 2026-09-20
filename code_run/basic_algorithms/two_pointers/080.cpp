#include <iostream>
#include <vector>

using namespace std;

int main(){

    int n, l;
    cin >> n >> l;

    vector<vector<int>> v(n, vector<int>(l));

    for (int i=0; i<n; i++){
        for (int j=0; j<l; j++){
            cin >> v[i][j];
        }
    }

    int slow = 0, fast = 1;

    while (fast < n && slow < n){

        vector<int> term;
        int h = 0, d = 0, c = 0;

        while (c<l){      
            if (v[fast][h]<=v[slow][d]){
                term.push_back(v[fast][h]);
                h++;
            } else {
                term.push_back(v[slow][d]);
                d++;
            }
            c++;
        }

        cout << term[l-1] << "\n";
        
        if (fast == n-1){
            slow++;
            fast = slow+1;
        }
        else {
            fast++;
        }
    }

    return 0;
}

