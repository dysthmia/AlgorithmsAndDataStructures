#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() 
{
	int k;
    cin >> k;

    string c, f;
    cin >> c;
    cin >> f;

    int need[26] = {0};
    for (char ch : f){
        need[ch-'a']++;
    }

    int win[26] = {0};

    for (int i=0; i<c.length(); i++){

        win[c[i]-'a']++;

        if (i>=k) win[c[i-k]-'a']--;

        if (i >= k - 1){

            bool ok = true;

            for (int j=0; j<26; j++){
                if (win[j] > need[j]){
                    ok = false;
                    break;
                }
            }

            if (ok) {
                cout << "YES" << "\n";
                return 0;
            }
        }
    }

    cout << "NO" << "\n";
	return 0;
}
