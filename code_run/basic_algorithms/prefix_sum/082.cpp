#include <iostream>
#include <vector>

using namespace std;

int main() 
{
    int n;
    cin >> n;
    
    vector<int> time(1440, 0);

    for (int i=0; i<n; i++){

        int sh, sm, eh, em;
        cin >> sh >> sm >> eh >> em;

        int start = sh*60 + sm;
        int end = eh*60 + em;

        if (start == end){
            for (int i=0; i<1440; i++){
                time[i]++;
            }
        } else if (start < end) {
            for (int i=start; i<end; i++){
                time[i]++;
            }
        } else {
            for (int i=start; i<1440; i++){
                time[i]++;
            }
            for (int i=0; i<end; i++){
                time[i]++;
            }
        }

    }

    int ans = 0;
    for (int i=0; i<1440; i++){
        if (time[i]==n){
            ans++;
        }
    }

    cout << ans << "\n";

	return 0;
}
