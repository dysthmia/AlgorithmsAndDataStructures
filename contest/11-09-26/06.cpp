
// В данной задаче Вам необходимо найти для натурального числа a 
// такое натуральное число x, не большее 10^9 + 9 что 
// a*x−1 делится на 10^9 + 9 (найти обратное по модулю)

// В первой строке записано число T колво тестовых примеров
// В каждой из следкющих T строк записано число a


// условие a*x ≡ 1 (mod 10^9+9) 10^9+9 - простое число => по теореме Ферма
// представим x это a^(-1), => по теореме Ферма x = a^(mod-2)
// 
// 

#include <iostream>

const int64_t mod = 1e9+9;

int64_t modpow (int64_t a, int64_t n){
    if (n==0) return 1;
    if (n%2==0){
        return modpow(a*a%mod,n/2);
    }
    return a*modpow(a,n-1)%mod;
}

void solve(int64_t a){
    std::cout << modpow(a,mod-2) << "\n";
}

int main(){
    int t; std::cin >> t;
    for (int i=0; i<t; i++){
        int64_t a; std::cin >> a;
        solve(a);
    }
    return 0;
}