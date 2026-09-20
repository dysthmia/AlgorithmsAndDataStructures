#include <iostream>
#include <vector>

using namespace std;

int main() 
{
    int g, s;
    cin >> g >> s;

    vector<int> word(256,0);
    for (int i=0; i<g; i++){
        unsigned char letter;
        cin >> letter;
        word[letter]++;
    }

    vector<unsigned char> line(s);
    for (int i=0; i<s; i++){
        unsigned char letter;
        cin >> letter;
        line[i] = letter;
    }

    int count = 0;
    int left = 0, right = 0;

    int good = 0; 
    vector<int> now(256,0);
    for (int c = 0; c < 256; c++) {
        if (now[c] == word[c]) {
            good++;
        }
    }

    // крч вот тут good будет равен X
    // наша цель чтобы X = 256 тогда подстрока равна нашему слову

    while (right < s){

        unsigned char c = line[right]; // берем символ справа

        if (now[c] == word[c]) good--; // проверяем было ли равенство до увеличения
        now[c]++; // меняем 
        if (now[c] == word[c]) good++; // если после увеличения равны то увеличиваем

        if (right - left + 1 == g){

            if (good == 256) {
                count++;
            }

            unsigned char d = line[left]; // символ слева который надо удалить

            if (now[d] == word[d]) good--; // Проверяем равенство до уменьшения
            now[d]--; // уменьшаем
            if (now[d] == word[d]) good++; // Проверяем равенство после уменьшения

            left++;
        }
        right++;
    }

    cout << count << "\n";

    return 0;
}


