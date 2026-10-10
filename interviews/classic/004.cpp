/*
Дан массив целых чисел и некоторое целое неотрицательное число K.
Необходимо определить длину максимального подмассива из единиц,
который можно получить заменой не более K любых элементов массива.

Примеры:
findMaxLengthOfOnes([1, -2, 3, -4, 1], 2) == 3
findMaxLengthOfOnes([1, 1, 1, 1], 1) == 4
findMaxLengthOfOnes([1, 3, 1, 3, 1, 7, 1, 1], 2) == 6

2
1 -2 3 -4 1

*/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

int findMaxLengthOfOnes (std::vector<int>& v, int k) {
    size_t l = 0, r = 0;
    int max_length = 0, bad = 0;
    while (r < v.size()) {
        while (r < v.size() && bad <= k) {
            if (v[r] != 1) bad++;
            r++;
        }
        while (bad > k) {
            if (v[l] != 1) bad--;
            l++;
        }
        max_length = std::max(max_length, static_cast<int>(r - l));
    }
    return max_length;
}

int main () {
    int k = 2;
    std::vector<int> v = {1, -2, 3, -4, 1};

    int ans = findMaxLengthOfOnes (v, k);
    std::cout << ans << '\n';

    return 0;
}