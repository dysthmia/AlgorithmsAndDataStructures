/*
Необходимо объединить все пересекающиеся отрезки и вернуть массив 
непересекающихся отрезков, покрывающих те же точки, что и исходные.
Отрезки могут идти в произвольно порядке, не обязательно по возрастанию

1) 
Input: {{1,3}, {2,3}, {4,5}}
Output: {{1,3}, {4,5}}

2)
Input: {{1,3}, {2,6}, {8,10}, {9,12}}
Output: {{1,6}, {8,12}}
*/

/*
    1 ... 4             
        2 ... 5.        
                        
                    
    1 ... 4             
      2.3
    

    1 ... 4             
            5 ... 6
*/

#include <iostream>
#include <cctype>
#include <algorithm>

using namespace std;

void print_vp (const vector<vector<int>>& v) {
    for (int i=0; i<v.size();i++) {
        cout << v[i][0] << ' ' << v[i][1] << '\n';
    }
}

vector<vector<int>> solution (vector<vector<int>>& v) {
    if (v.size() <= 1) return v;

    sort(v.begin(),v.end());

    vector<vector<int>> res;
    res.push_back(v[0]);

    for (int i=1; i<v.size(); i++) {
        if (v[i][0] <= res.back()[1]) {
            res.back()[1] = max(res.back()[1], v[i][1]);
        } else {
            res.push_back(v[i]);
        }
    }

    return res;
}

int main () {
    vector<vector<int>> v = {{4,5}, {1,3}, {2,3}};
    solution(v);
    return 0;
}