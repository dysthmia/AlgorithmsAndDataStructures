#include <iostream>
#include <vector>
#include <deque>
#include <iomanip>

using namespace std;

int main() 
{
    int n, k;
    cin >> n ;
    cin >> k;

    double sum = 0;
    vector<double> clients (n);
    for (int i=0; i<n; i++){
        cin >> clients[i];
        sum += clients[i];
    }

    double min_sum = sum;
    int left = 0, right = 0;

    double now_sum = 0;
    deque<double> now;

    while (right < n){

        while (right - left < k){
            now.push_back(clients[right]);
            now_sum += clients[right]; 
            right++;
        }

        min_sum = min(min_sum, sum - now_sum);

        now.pop_front();
        now_sum -= clients[left];
        left++;
    }

    cout << fixed << setprecision(12) << min_sum << "\n";

	return 0;
}
