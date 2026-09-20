#include <iostream>
#include <cstdlib>
#include <cstdint>
#include <vector>

using namespace std;

int main() {

    int n;
    cin >> n;
    vector<int> tshirts (n);
    for (int i=0; i<n; i++){
        cin >> tshirts[i];
    }

    int m;
    cin >> m;
    vector<int> pants (m);
    for (int i=0; i<m; i++){
        cin >> pants[i];
    }

    int min = INT32_MAX;
    int t = 0, p = 0;
    int b_t = 0, b_p = 0;

    while (t<n && p<m){

        if (tshirts[t] < pants[p]) {
            t++;
        } else if (tshirts[t] > pants[p]) {
            p++;
        }

        if (abs(tshirts[t] - pants[p]) < min){
            min = abs(tshirts[t] - pants[p]);
            b_t = t; 
            b_p = p;
            if (min == 0) {break;}
        }
    }

    cout << tshirts[b_t] << " " << pants[b_p] << "\n";

	return 0;
}
