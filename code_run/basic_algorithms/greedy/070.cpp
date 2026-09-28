#include <iostream>
#include <vector>
#include <map>

using namespace std;


int main() 
{
	int n; cin >> n;
    map<int, int> a;

    for (int i=0; i<n; i++){
        int w, h; cin >> w >> h;
        if (a[w] < h) a[w] = h;
    }

    int max_height = 0;
    for (auto& it : a){
        max_height += it.second;
    }

    cout << max_height << '\n';
	return 0;
}
