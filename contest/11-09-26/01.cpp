// 
// Последняя цифра числа Фибоначи.
// 
// В единственной строке входных данных записано натуральное число n (1<= n <= 1000)
// Вывести последнюю цифру Fn
//
// 

#include <iostream>

int main(){
    
    int n;
    std::cin >> n;

    if (n <= 1) {
        std:: cout << 1 << "\n";
        return 0;
    }

    int f0 = 1, f1 = 1, fn = 0;

    for (int i=2; i<=n; i++){
        fn = (f0 + f1)%10;
        f0 = f1;
        f1 = fn;
    }

    std::cout << fn << "\n";

    return 0;
}

