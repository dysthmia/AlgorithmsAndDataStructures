#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

bool areEqual (char a, char b){
    return tolower(static_cast<unsigned char> (a)) ==  tolower(static_cast<unsigned char> (b));
}

int main() 
{
    string s;
    getline(cin, s);

    s.erase(remove(s.begin(),s.end(),' '), s.end());
    // remove(s.begin(),s.end(),' ') -> возвращает итератор

    int l = 0, r = s.size()-1;
    while (l<r) {
        if (!areEqual(s[l],s[r])){
            cout << "It is not a palindrome" << endl;
            return 0;
        }
        l++;
        r--;
    }

    cout << "It is a palindrome" << endl;

	return 0;
}
