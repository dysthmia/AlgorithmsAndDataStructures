#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdint>

/*
    
        18 из 22 тестов OK

*/

using namespace std;

int prec (char c){
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    return 0;
}

bool apply (vector<int64_t>& nums, vector<char>& ops) {

    if (ops.empty() || nums.size() < 2) return false;

    char op = ops.back(); ops.pop_back();

    int64_t a = nums.back(); nums.pop_back();
    int64_t b = nums.back(); nums.pop_back();

    int64_t res = 0;

    if (op == '+') res = a + b;
    else if (op == '-') res = b-a;
    else if (op == '*') res = a * b;
    else if (op == '/' ) {
        if (a == 0) return false;
        res = b / a;
    }
    nums.push_back(res);
    return true;
}

int main() {
	string s;
    getline(cin, s);

    vector<int64_t> nums;
    vector<char> ops;

    bool wrong = false;

    size_t i = 0;
    while (i < s.size()) {
        
        char c = s[i];

        if (isspace(static_cast<unsigned char> (c))) {
            i++;
            continue;
        }

        if (isdigit(static_cast<unsigned char> (c))) {
            int64_t n = 0;
            while (i<s.length() && isdigit(static_cast<unsigned char> (s[i]))){
                n = n*10 + (s[i]-'0');
                i++;
            }
            nums.push_back(n);
            continue;
        }

        if (c == '(') {
            ops.push_back(c);
            i++;
            continue;
        }

        if (c == ')') {
            while (!ops.empty() && ops.back() != '(') {
                if (!apply(nums, ops)) {
                    wrong = true;
                    break;
                }
            }

            if (wrong) break;     

            if (ops.empty()) {               
                wrong = true;
                break;
            }

            ops.pop_back();                 
            i++;
            continue;
        }

        else if (c == '+' || c == '-' || c == '*' || c == '/') {
            while (!ops.empty() && ops.back() != '(' && prec(ops.back()) >= prec(c)) {
                if (!apply(nums, ops)) {
                    wrong = true;
                    break;
                }
            }

            ops.push_back(c);
            i++;
            continue;
        }

        else {
            wrong = true;
            break;
        }
    }

    while (!ops.empty()) {
        if (ops.back() == '(') {  
            wrong = true;
            break;
        }
        if (!apply(nums, ops)) {
            wrong = true;
            break;
        }
    }

    if (wrong || nums.size()!=1){
        cout << "WRONG" << "\n";
    } else {
        cout << nums.back() << "\n";
    }

	return 0;
}
