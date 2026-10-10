
/*
Дан текст T и строка S.
Требуется найти подстроку S' в T такую, что она совпадает с S с точностью до перестановки букв.
В качестве ответа стоит вернуть индекс первого вхождения, или -1, если такая подстрока S' не нашлась.
("reebok", "bee") -> 1

rokeeb
*/

/*

            R E E B O K 

            R E E 

              E E B 

                E B O 

                  B O K 
*/


#include <iostream>
#include <string>
#include <map>

int solution (std::string t, size_t n, std::string s, size_t m) {

    size_t l = 0, r = 0;
    std::map<char, int> need, curr;

    for (int i=0; i<m; i++) need[s[i]]++;
    
    while (r < l + m) {
        curr[t[r]]++; 
        r++;
    }
        
    int matches = 0;
    for (auto& it : need) {
        if (curr[it.first]==need[it.first]) matches++;
    }

    while (r < n) {

        if (matches == need.size()) return l;
        
        auto it = need.find(t[r]);
        if (it != need.end()) {
            if (curr[t[r]] == it->second) matches--; // если совпадало то после добавления нового уже не будет совпадать
            curr[t[r]]++;                            // добавляем новый элемент
            if (curr[t[r]] == it->second) matches++; // если до этого не совпадало а сейчас совпало то увеличиваем mathces
        } else {
            curr[t[r]]++;
        }
        r++;

        // аналогичный для левого элемета 
        it = need.find(t[l]);
        if (it != need.end()) {
            if (curr[t[l]] == it->second) matches--;
            curr[t[l]]--;
            if (curr[t[l]] == it->second) matches++;
        } else {
            curr[t[l]]--;
        }
        l++;
    }

    if (matches == need.size()) return l; // проверяем последнее окно

    return -1;
}


int main () {
    std::string t, s;
    std::cin >> t >> s;

    auto indx = solution(t, t.length(), s, s.length());
    std::cout << indx << '\n';
}
