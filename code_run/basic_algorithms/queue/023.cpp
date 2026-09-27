#include <iostream>
#include <deque>

using namespace std;

int main() 
{
	int n; cin >> n;

    deque<int> left;
    deque<int> right;

    while (n--){
        char op; int x;
        cin >> op;

        if (op == '+'){
            cin >> x;
            right.push_back(x);
        } else if (op == '*'){
            cin >> x;
            right.push_front(x);
        } else if (op == '-'){
            int l = left.front();
            left.pop_front();
            cout << l << "\n";
        }

        if (left.size() < right.size()){
            int r = right.front();
            right.pop_front();
            left.push_back(r);
        }
    }
	return 0;
}
