#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

int m;
const int64_t p = 1000000007;
const int64_t x = 263;
vector<vector<string>> hashes;

void read_hashes(const vector<vector<string>>& hashes){
    for (int i=0; i<hashes.size(); i++){
        for (int j=0; j<hashes[i].size(); j++){
            cout << hashes[i][j] << " " ;
        }
        cout << "\n";
    }
}

int get_hash (const string& word) {
    int64_t hash_code = 0;
    for (int i=word.size()-1; i>=0; i--){
        hash_code = (hash_code * x + word[i])%p;
    }
    return hash_code % m;
}

bool find (const string& word){
    bool have = false;
    int h = get_hash(word);
    for (int i=0; i<hashes[h].size(); i++){
        if (hashes[h][i] == word){
            have = true;
            break;
        }
    }
    return have;
}

void add (const string& word){
    if (find(word)) return;
    int h = get_hash(word);
    hashes[h].insert(hashes[h].begin(), word);
}

void check (const string& word){
    int num = stoi(word);
    for (int i = 0; i < hashes[num].size(); i++){
        cout << hashes[num][i] << " ";
    }
    cout << "\n";
}

void del (const string& word){
    int h = get_hash(word);
    if (hashes[h].empty()){
        return;
    }
    for (int i=0; i<hashes[h].size(); i++){
        if (hashes[h][i] == word){
            hashes[h].erase(hashes[h].begin() + i);
            return;
        }
    }
}

int main(){

    int n;
    cin >> m;
    cin >> n;

    hashes.resize(m);

    while (n--){

        string command, word;
        cin >> command >> word;

        if (command == "add"){
            add(word);
        } else if (command == "check"){
            check(word);
        } else if (command == "find") {
            if (find(word)){
                cout << "yes" << "\n";
            } else cout << "no" << "\n";
        } else {
            del(word);
        }
    }

    return 0;
}