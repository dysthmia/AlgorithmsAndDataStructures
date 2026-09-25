#include <iostream>
#include <string>

using namespace std;

int main (){

    long long p,m;
    cin >> p >> m;

    string s;
    cin >> s;

    long long h = 0;
    for (int i=0; i < s.length(); i++){
        h = (h * p + (s[i] - 'a' + 1)) % m;
    }

    cout << h << "\n";
    return 0;
}