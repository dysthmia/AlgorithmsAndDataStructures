#include <iostream>
#include <vector>

using namespace std;

int main() 
{
	int n;
    long long r;
    cin >> n >> r;

    vector<long long> d(n);
    for (int i=0; i<n; i++){
        cin >> d[i];
    }

    int right = 0;
    long long count = 0;

    for (int left=0; left<n; left++) {

        if (right < left+1){
            right = left + 1;
        }

        while (right < n && d[right] - d[left] <= r){
            right++;
        }

        count += n - right;
    }

    cout << count << "\n";

	return 0;
}