#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

void print_set(set<int> s){
    for (auto& it : s){
        cout << it << " ";
    }
    cout << "\n";
}

int main() {

    int n, m;
    cin >> n >> m;

    vector<int> anna(n);
    for (int i=0; i<n; i++){
        cin >> anna[i];
    }

    vector<int> borya(m);
    for (int i=0; i<m; i++){
        cin >> borya[i];
    }

    sort(anna.begin(),anna.end());
    sort(borya.begin(),borya.end());

    set<int> match;
    set<int> a_;
    set<int> b_;

    int a = 0, b = 0;

    while (a<n && b<m){
        if (anna[a] == borya[b]){
            match.insert(anna[a]);
            a++;
            b++;
        }
        else if (anna[a] < borya[b]){
            a_.insert(anna[a]);
            a++;
        }
        else if(anna[a] > borya[b]){
            b_.insert(borya[b]);
            b++;
        }
    }
    
    while (a<n){
        a_.insert(anna[a]);
        a++;
    }
    while (b<m){
        b_.insert(borya[b]);
        b++;
    }

    cout << match.size() << "\n";
    print_set(match);
    
    cout << a_.size() << "\n";
    print_set(a_);

    cout << b_.size() << "\n";
    print_set(b_);

	return 0;
}