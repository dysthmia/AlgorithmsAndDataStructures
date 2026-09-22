#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;
vector<int> l;

bool can (int x){

    int count = 0;
    int ind = 0;

    while (ind<n){

        count += l[ind]/x;

        if (count >= k) return true;
        
        ind++;
    }
    return false;
}

int main() 
{
    cin >> n >> k;

    l.resize(n);
    for (int i=0; i<n; i++){
        cin >> l[i];
    }

    sort (l.begin(), l.end());

    int left = 1, right = l[n -1];
    
    while (left <= right){

        int mid = (left + right)/2;

        if (can(mid)) {
            left = mid+1;
        }

        else right = mid - 1;
    }

    cout << right << "\n";
	return 0;
}
