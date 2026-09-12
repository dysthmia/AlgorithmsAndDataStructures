//
// даны четыре числа a,b,c,d
// нужно найти (ad+bc)/bd по модулю 1e9+7

#include <iostream>

const int64_t mod = 1e9+7;

int64_t modmul (int64_t x, int64_t y){
    x = (x%mod + mod)%mod;
    y = (y%mod + mod)%mod;
    return x*y%mod;
}

int64_t modsub (int64_t x, int64_t y){
    return ((x%mod + y%mod)%mod + mod)%mod;
}
//
// 1e9+7 - простое => по теореме Ферма
// x/y = x * y ^ (mod - 2)
// y^(-1) = y ^ (mod - 2)
//
int64_t modpow(int64_t x,int64_t n) {
    if (n==0) return 1;
    if (n%2==0){
        return modpow(x * x % mod,n/2);
    }
    return x*modpow(x,n-1)%mod;
}

int64_t moddiv (int64_t x, int64_t y){
    y = modpow(y, mod-2);
    return x*y%mod;
}


int main(){
    int64_t a,b,c,d;
    std::cin >> a >> b >> c >> d;
    int64_t ad = modmul (a,d);
    int64_t bc = modmul (b,c);
    int64_t bd = modmul (b,d);
    int64_t adbc = modsub(ad,bc);
    std::cout << moddiv(adbc,bd) <<"\n";
    return 0;
    
}