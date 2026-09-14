//
// Есть 3 числа a, n, m
// Надо найти сумму ряда 1/a + 2/a^2 + 3/a^3 +...+n/a^n по модулю m
// m - не обязательно должно быть простым

// расширенный алгоритм евклида какой то минус вайб

#include <iostream>

int64_t gcd (int64_t a, int64_t b, int64_t& x, int64_t& y){

    if (b==0) {
        x = 1;
        y = 0;
        return a;
    }

    int64_t x1, y1;
    int64_t g = gcd (b, a%b, x1, y1);

    x = y1;
    y = x1 - (a/b) * y1;

    return g;
}

int64_t mod_inv(int64_t a, int64_t m){

    int64_t x, y;
    int64_t g = gcd(a, m, x, y);

    if (g!=1) return -1; // крч тогда не существует обратного

    x = ((x%m)+m)%m;

    return x;
}

int64_t sum_mod (int64_t a, int64_t n, int64_t m){

    a = ((a%m)+m)%m;

    int64_t inv_a = mod_inv(a, m);
    if (inv_a == -1){return -1;} // то это оч плохо потому что не сущесвует обратного
    int64_t sum = 0, pow = 1;
    
    for (int64_t k = 1; k <= n; k++){
        pow = pow * inv_a % m;
        int64_t term = (pow * (k%m))%m;
        sum  = (sum + term)%m;
    }

    return ((sum%m)+m)%m;
}

int main(){

    int64_t a, n, m;
    std::cin >> a >> n >> m;

    int64_t x, y;
    int64_t g = gcd (a,m,x,y);

    int64_t sum = sum_mod(a, n, m);
    
    std::cout << sum << "\n";
    
    return 0;
}