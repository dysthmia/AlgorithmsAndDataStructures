// Сколько слов с данным префиксом?

#include <iostream>
#include <map>

struct Node {
    std::map<char, Node> next;
    int count = 0;
} root;

void insert (const std::string& s) {
    Node* v = &root;
    ++v->count;
    for (const auto ch : s) {
        v = &v->next[ch];
        ++v->count;
    }
}

int find(const std::string& s) {
    Node* v = &root;
    for (const auto ch : s) {
        auto it = v->next.find(ch);
        if (it == v->next.end()) {
            return 0;
        }
        v = &it->second;
    }
    return v->count;
}

int main () {
    int n, m;
    std::cin >> n;
    for (int i=0; i<n; i++){
        std::string s; 
        std::cin >> s;
        insert(s);
    }
    std::cin >> m;
    for (int i=0; i<m; i++){
        std::string s; 
        std::cin >> s;
        std::cout << find(s) << '\n';
    }
    return 0;
}