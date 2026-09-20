#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() 
{
    int n, k;
    cin >> n >> k;

    vector<int> v (n);
    for (int i=0; i<n; i++){
        cin >> v[i];
    }

    multiset<int> now;
    int left = 0, right = 0;

    while (left < n && right < n){

        while (right<n && right - left < k){
            now.insert(v[right]);
            right++;
        }

        cout << *now.begin() << "\n";

        now.erase(now.find(v[left]));
        left++;
    }

	return 0;
}
