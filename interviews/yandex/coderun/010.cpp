#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main () {

    string s; getline(cin , s);
    istringstream iss (s);

    int n; iss >> n;
    vector<int> indx;
    vector<long long> hght (n + 1); 

    for (int i=0; i<n; i++) 
        iss >> hght[i];

    hght[n] = 0; 

    long long best_sq = 0; 

    for (int i=0; i<=n; i++) { 
        while (!indx.empty() && hght[indx.back()] >= hght[i]) {
            int indx_top_hght = indx.back();
            long long top_hght = hght[indx_top_hght]; 
            indx.pop_back();
            
            int right = i;
            int left = (!indx.empty()) ? indx.back() : -1; 
            long long width = right - left - 1;

            best_sq = max(best_sq, top_hght * width);
        }
        indx.push_back(i);
    }

    cout << best_sq << '\n';
    return 0;
}