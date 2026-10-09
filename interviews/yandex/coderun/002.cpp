// синонимы через свою структуру

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct node {
    string s;
    node* synonim;
};

int main() 
{
	int n; cin >> n;
    vector<node> my_dict (2 * n);

    while (n--) {
        string w1, w2; cin >> w1 >> w2;
        
        my_dict.push_back({w1,nullptr});
        my_dict.push_back({w2,nullptr});

        node* a = &my_dict[my_dict.size()-2];
        node* b = &my_dict[my_dict.size()-1];

        a -> synonim = b;
        b -> synonim = a;
    }

    string word; cin >> word;
    for (auto& it : my_dict) {
        if (it.s == word){
            cout << it.synonim->s << '\n';
        }
    }

	return 0;
}
