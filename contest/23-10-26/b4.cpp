// Кратчайший уникальный префикс строки

#include <iostream>
#include <vector>
#include <string>
#include <map>

struct Node {
    std::map<char, Node> next;
    int count = 0;
} root;

void insert(const std::string& s) {
    Node* v = &root;
    ++v->count;
    for (const auto ch : s) {
        v = &v->next[ch];
        ++v->count;
    }
}

std::string find(const std::string& s) {
    Node* v = &root;
    std::string res;
    for (const auto ch : s) {
        v = &v->next[ch];
        res.push_back(ch);
        if (v->count == 1) {
            return res;
        }
    }
    return "-";
}

int main () {
    int n;
    std::cin >> n;
    std::vector<std::string> words(n);
    for (auto& s : words) {
        std::cin >> s;
        insert(s);
    }
    for (const auto& s : words) {
        std::cout << find(s) << std::endl;
    }
}