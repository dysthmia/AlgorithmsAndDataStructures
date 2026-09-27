#include <iostream>
#include <queue>

using namespace std;

const int n = 5;
const int64_t botva = 1e6;

int main() 
{
    queue<int> first;
    queue<int> second;

    for (int i=0; i<n; i++){
        int c; cin >> c;
        first.push(c);
    }

    for (int i=0; i<n; i++){
        int c; cin >> c;
        second.push(c);
    }

    int count = 0;
    bool endless = false;

    while (!first.empty() && !second.empty()){

        if (count > botva){
            endless = true;
            break;
        }

        int f = first.front(); first.pop();
        int s = second.front(); second.pop();

        if (f == 0 && s == 9){
            first.push(f); first.push(s);
        } else if (s == 0 && f == 9){
            second.push(f); second.push(s);
        } else if (f > s){
            first.push(f); first.push(s);
        } else if (f < s){
            second.push(f); second.push(s);
        }

        count++;
    }

    if (endless) {
        cout << "botva" << "\n";
    }

    if (first.empty()){
        cout << "second" << " " << count << "\n";
    } else if (second.empty()){
        cout << "first" << " " << count << "\n";
    }

	return 0;
}
