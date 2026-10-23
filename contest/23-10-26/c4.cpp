//  Количество вершин в Боре [Сем]

#include <iostream>
#include <map>

struct Node {
    std::map<char, Node> next;
    // int count = 0;
} root;

int count = 1;

void insert (const std::string& s) {
    Node* v = &root;
    // ++v->count;
    for (const auto ch : s) {
        if (v->next.find(ch) == v->next.end()) {
            count++;
        }
        v = &v->next[ch];
        // ++v->count;
    }
}

int main () {
    int n; std::cin >> n;
    for (int i=0; i<n; i++) {
        std::string s; 
        std::cin >> s;
        insert(s);
    }

    std::cout << count << '\n';
    return 0;
}

