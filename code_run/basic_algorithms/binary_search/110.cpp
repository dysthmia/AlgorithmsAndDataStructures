#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdint>


using namespace std;

int main() 
{
	int n; cin >> n;

    vector<int> a(n);
    for (int i=0; i<n; i++){
        cin >> a[i];
    }

    sort (a.begin(),a.end());

    int m; cin >> m;

    for (int i=0; i<m; i++){

        int element; cin >> element;

        int l = 0, r = n - 1;

        int min_d = INT32_MAX;
        int b_min = INT32_MAX;

        while (l <= r){

            int mid = (l+r)/2;

            int diff = a[mid] - element;
            if (diff < 0) diff = - diff;

            if (diff < min_d){
                min_d = diff;
                b_min = a[mid];
            }

            if (a[mid] < element){
                l = mid+1;
            } else if (a[mid] > element){
                r = mid - 1;
            } else {
                b_min = element;
                break;
            }
            
        }
        cout << b_min << "\n";
    }

	return 0;
}
