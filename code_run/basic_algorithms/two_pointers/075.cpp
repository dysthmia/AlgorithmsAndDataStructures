#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(){

    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    map<char, int> dict;

    int l = 0;
    int b_len = 0, b_start = 0;

    for (int r = 0; r<n; r++){

        dict[s[r]]++;

        while (dict[s[r]] > k && l<=r){
            dict[s[l]]--;
            l++;
        }

        int len = r -l +1;

        if (len > b_len){
            b_len = len;
            b_start = l;
        }
    }

    cout << b_len << " " << b_start+1 << "\n";

    return 0;
}