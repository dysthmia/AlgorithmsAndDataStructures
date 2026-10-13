#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main() 
{
    int64_t max_p1 = 0, max_p2 = 0;
    int64_t max_n1 = 0, max_n2 = 0;

    string s; getline (cin, s);
    istringstream iss (s);

    int x, y; 
    iss >> x >> y;

    max_p1 = max(x,y); max_p2 = min(x,y);
    max_n1 = min(x,y); max_n2 = max(x,y);

    while (iss >> x) {
        if (x >= max_p1) {
            max_p2 = max_p1;
            max_p1 = x;
        } else if (x > max_p2) {
            max_p2 = x;
        }

        if (x <= max_n1) {
            max_n2 = max_n1;
            max_n1 = x;
        } else if (x < max_n2) {
            max_n2 = x;
        }
    }

    if (max_p1 * max_p2 > max_n1 * max_n2) {
        cout << max_p2 << ' ' << max_p1 << '\n';
    } else cout << max_n1 << ' ' << max_n2 << '\n';

    return 0;
}
