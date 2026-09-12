#include <iostream>
using namespace std;

const int mod = 11;

// сложение по модулю
int64_t modsum (int64_t a , int64_t b) {
    int64_t s = ((a%mod + b%mod)%mod + mod)%mod;
    return s;
}
// вычитание по модулю
int64_t modsub (int64_t a, int64_t b) {
    int64_t s = ((a%mod - b%mod)%mod + mod)%mod;
    return s;
}
// умножение по модулю
int64_t modmul (int64_t a, int64_t b) {
    int64_t s = (a*b%mod + mod)%mod;
    return s;
}
// возведение в степень по модулю
int64_t modpow (int64_t a, int64_t n) {
    if (n==0) return 1;
    if (n%2==0){
        return modpow(a*a%mod, n/2);
    }
    return a * modpow(a,n-1)%mod;
}
// деление по модулю (см. теорему ферма)
int64_t moddiv(int64_t a, int64_t b) {
    a = (a%mod + mod)%mod;
    b = (b%mod + mod)%mod;
    int64_t s = a * modpow(b,mod - 2)%mod;
    return s;
}
//
//        Теорема Ферма:
//    a/b = a · bᵖ⁻²   (mod p)
//    a^(mod-1) = 1
//    a^(-1) = a^(mod-2)
//
// *работает только с простыми p
//
int main() {
    return 0;
}