// 
// Число Фибоначи F(n) по модулю 1e6+3
// 

// 

//
//   Лёгкий способ за O(n)
//
//

// #include <iostream>
// const int64_t mod = 1e6+3;
// int main(){
//     int n; 
//     std::cin >> n;
//     int64_t f0 = 1, f1 = 1, fn = 1;
//     for (int i=2; i<=n; i++){
//         fn = (f0+f1)%mod;
//         f0 = f1;
//         f1 = fn;
//     }
//     std::cout << fn << "\n";
//     return 0;
// }




//
//   Более крутой способ за O(log(n))
//    почему то не работает при n = 7
//


#include <iostream>
#include <cstdint>

const int64_t  mod = 1e6+3;

struct Mat{
    int64_t a, b, c, d;  // a b 
                         // c d
};

Mat mul (const Mat& x,const Mat& y) {
    Mat new_map = {
        (x.a*y.a + x.b*y.c) % mod,
        (x.a*y.b + x.b*y.d) % mod,  // a b      f g       |af+bh       ag+bi|
        (x.c*y.a + x.d*y.c) % mod,  // c d  *   h i     = |cf+dh       cg+di|
        (x.c*y.b + x.d*y.d) % mod
    };
    return new_map;
}
//
// & — побитовое И (n = 13 например) 
//   n:  1 1 0 1
//   1:  0 0 0 1
//    ───────────
// n&1:  0 0 0 1
//
// n >> 1 сдвиг вправо
//    13 = 1 1 0 1
//           1 1 0 1 ?  <- правый бит (1) выпал
//         0 1 1 0  <- слева дописали 0
// _________________________________________
//
// res = I                      <- вместо 1
// base = M                    <-  вместо 2
// n = 13

// Пока n > 0:
//     если n & 1 == 1:  res = mul(res, base)   (res = res · base)
//     base = mul(base, base)                  (base = base²)
//     n = n >> 1
//
Mat mat_pow (Mat m, int64_t n){
    Mat res { 1,0,0,1 }; // при умнажении на неё ниче не произойдет
    while(n>0){
        if (n&1) res = mul(res,m);
        m = mul(m,m);
        n >>= 1;
    }
    return res;
}

int64_t fib (int64_t n){
    if (n==0) return 0;
    Mat m {1,1,1,0};
    Mat p = mat_pow(m, n);
    return p.b;
}

int main(){
    int64_t n;
    std::cin >> n;
    std::cout << fib(n) << "\n";
    return 0;
}
