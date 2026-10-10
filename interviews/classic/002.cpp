/*
Дан неотсортированный массив целых неотрицательных чисел.

Необходимо отсортировать массив и представить его в виде строки, в которой:

одиночные числа записываются как есть;
последовательности из двух и более подряд идущих чисел заменяются диапазоном через -;
элементы разделяются запятой и пробелом.

Примеры:

1) 
Input:  1 5 6 7 8 10 15
Output: "1, 5-8, 10, 15"

2) 
Input:  5 4 3 2 1
Output: "1-5"
*/

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

std::string solution (std::vector<int>& v, size_t n) {

    sort(v.begin(), v.end());

    int start = 0;
    std::string ans = "";

    for (int i=1; i<=n; i++) {
        if (i == n || v[i] != v[i-1] + 1) {
            if (!ans.empty()) {
                ans += ", ";
            }
            if (start == i-1) {
                ans += std::to_string(v[start]);
            } else {
                ans += std::to_string(v[start]) + "-" + std::to_string(v[i-1]);
            }
            start = i;
        }
    }
    
    return ans;
}

int main () {

    std::string s;
    getline (std::cin, s);

    std::istringstream iss (s);
    std::vector<int> v;

    int x;
    while (iss >> x) 
        v.push_back(x);

    std::string ans = solution(v, v.size());
    std::cout << ans << '\n';

    return 0;
}