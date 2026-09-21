#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

long long solve(const string& ballad, int n) {

    int count_spaces = count(ballad.begin(),ballad.end(),' ');
    n -= count_spaces;

    string s;
    s.reserve(n);

    for (char c : ballad){
        if (c!=' ')
            s+=c;
    }

    vector<vector<int>> pref (n+1,vector<int>(26,0));

    for (int i=0; i<n; i++){
        pref[i+1] = pref[i];
        pref[i+1][s[i] - 'a']++;
    }

    long long ans = 0;

    for (int i=0; i<n; i++){
        for (int j=0; j<26; j++){
            
            long long left = pref[i][j];

            long long right = pref[n][j] - pref[i+1][j];

            ans+=left*right;
        }
    }

    return ans;
}

int main(){

    string s;
    getline(cin , s);
    long long ans = solve(s,s.size());
    cout << ans << "\n";
}