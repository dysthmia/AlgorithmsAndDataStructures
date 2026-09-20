#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>


using namespace std;

int main() 
{
    int n, s;
    cin >> n;
    cin >> s;

    if (s >= n) {
        cout << "INF" << "\n";
        return 0;
    }

    vector<int> t(n);
    for (int i=0; i<n; i++){
        cin >> t[i];
    }

    sort(t.begin(), t.end());

    int left = 0, right = 0;
    int min_t = INT16_MAX;

    while (right < n){

        while (right - left < s) {
            right++;
        }

        if (right < n) {
            min_t = min(min_t, t[right]-t[left]);
        }
        
        left++;
    }

    if (min_t==0){
        cout << "Impossible"<<"\n";
        return 0;
    }

    cout << min_t << "\n";
	return 0;
}
