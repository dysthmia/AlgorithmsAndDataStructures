#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() 
{
	int n; cin >> n;

    priority_queue<int, vector<int>, greater<int>> a;
    
    for (int i=0; i<n; i++){
        int num; cin >> num;
        a.push(num);
    }
    
    double sum = 0;

    while (a.size() != 1){
        int l = a.top(); a.pop();
        int w = a.top(); a.pop();
        a.push(l+w);
        sum += (l+w) * 0.05;
    }

    cout << sum << "\n";

	return 0;
}
