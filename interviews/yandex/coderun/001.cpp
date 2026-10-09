// уникальные слова в тексте

#include <iostream>
#include <string>
#include <cctype>
#include <set>

using namespace std;

int main() 
{
    set<string> unique; 
    
    string s;
    while (cin >> s) {
        unique.insert(s);
    }

    cout << unique.size() << '\n';
	return 0;
}
