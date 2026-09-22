#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n , r , c;
vector<int> s;    

bool can(int x){

    int ind = 0;
    int count = 0;

    while (ind + c - 1 < n) {
        if (s[ind+c-1]-s[ind] <= x){
            count++;
            ind+=c;
        }
        else {
            ind++;
        }
        if (count >= r) return true;
    }
    return false;
}

int main() 
{
    cin >> n >> r >> c;

    s.resize(n);
    for (int i=0; i<n; i++){
        cin >> s[i];
    }

    sort(s.begin(), s.end());

    int left = 0, right = s[n-1] - s[0];
    while (left < right){
        
        int mid = (left+right)/2;

        if (can(mid)){
            right = mid;
        }
        else left = mid+1;
    }
	
    cout << left << "\n";

	return 0;
}
