//
// Данны a b
// Вычилисть a^2 - b^2 по модулю 10^6 + 7
// 

#include <iostream>

const int64_t mod = 1e6 + 7; 

int64_t modpow (int64_t a, int64_t n ) {
    if (n==0) return 1;
    if (n%2 == 0) {
        return modpow(a*a%mod, n/2);
    }
    return a * modpow(a,n-1)%mod;
}
int64_t sub (int64_t a, int64_t b){
    return ((a%mod-b%mod)%mod + mod)%mod;
}

int main(){
    int64_t a,b;
    std::cin >> a >> b;
    a = modpow(a,2); 
    b = modpow(b,2);
    std::cout << sub(a,b) << "\n";
    return 0;
}