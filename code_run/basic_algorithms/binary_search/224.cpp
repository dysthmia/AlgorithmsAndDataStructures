#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() 
{
	int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i=0; i<n; i++){
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    for (int i=0; i<k; i++){

        bool contain = false;
        int element; cin >> element;
        int l = 0, r = n-1;

        while (l<=r){

            int mid = (l+r)/2;

            if (a[mid] < element){
                l = mid+1;
            } else if (a[mid]>element){
                r = mid-1;
            } else {
                contain = true;
                break;
            }
        }
        
        if (contain) {
            cout << "YES" << "\n";
        } else cout << "NO" << "\n";
    }

	return 0;
}
