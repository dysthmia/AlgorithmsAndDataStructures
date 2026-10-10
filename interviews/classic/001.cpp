/*
Дан массив чисел в рандомном порядке,  например [1, 5, 2, 5, 0, 1, 3, 0, 15] 
Надо преобразовать его так чтобы все нули оказались в конце, 
а предыдущие элементы сохранили порядок, то есть
[1, 5, 2, 5, 0, 1, 3, 0, 15]  -> [1, 5, 2, 5, 1, 3, 15, 0, 0]

Вход:                               Выход:
1 5 2 5 0 1 3 0 15                  1 5 2 5 1 3 15 0 0 
*/ 

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

void solution (std::vector<int>& v, size_t n) {
    size_t w = 0, r = 0;
    while (r < n) {
        if (v[r] != 0) {
            v[w] = v[r];
            w++;
        }
        r++;
    }
    for (size_t i = w; i<n; i++) {
        v[i] = 0;
    }
}

void print_v (std::vector<int>& v, size_t n) {
    for (size_t i=0; i<n; i++) {
        std::cout << v[i] << ' ';
    }
    std::cout << '\n';
}

int main() {

    std::string s;
    getline(std::cin, s);

    std::vector<int> v;
    std::istringstream iss (s);
    
    int x;
    while (iss >> x) v.push_back(x);

    print_v (v, v.size());
    solution(v, v.size());
    print_v (v, v.size());

    return 0;
}