//
// Дано число n
// Найти  n! по модулю 10^6 + 3
//
//


// 6! = 1 * 2 * 3 * 4 * 5 * 6
// это всё умножение по модулю


#include <iostream>

const int64_t mod = 1e6+3;

int64_t fact (int64_t n){
    if (n>=mod) return 0;
    int64_t res = 1;
    for (int i=2; i<=n; i++){
        res = res*i%mod;
    }
    return res;
}

int main(){
    int64_t n;
    std::cin >> n;
    std::cout << fact(n) << "\n";
    return 0;
}