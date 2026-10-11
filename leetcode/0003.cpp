#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0; 
        size_t cur_length = 0;
        size_t max_length = 0;
        map<char, int> dict;
        for (int r=0; r<s.length(); r++) {
            if (dict[s[r]] == 0) {
                dict[s[r]]++;
                cur_length++;
            } else {
                while (dict[s[r]] > 0) {
                    if (dict[s[l]] > 0) {
                        dict[s[l]]--;
                        cur_length--;
                    }
                    l++;
                }
                dict[s[r]]++;
                cur_length++;
            }
            max_length = max(max_length, cur_length);
        }
        return max_length;
    }
};


int main () {
    Solution obj;
    string s = "pwwkew";
    int a = obj.lengthOfLongestSubstring(s);
    cout << a << '\n';
}