//
//
// Возведение в степень за O(log(n))

//
#include <iostream>

int64_t suppower(int a,int n){
    if (n == 0) return 1;
    if (n%2 == 0) {
        int64_t half = suppower(a,n/2);
        return half * half;
    }
    return a * suppower(a, n-1);
}

int main(){
    int a, n;
    std::cin >> a >> n;
    std::cout << suppower(a,n) << "\n";
    return 0;
}