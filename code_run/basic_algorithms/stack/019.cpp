#include <iostream>
#include <string>
#include <vector>

using namespace std;

int prec(char op) {
    if (op == '!') return 3;
    if (op == '&') return 2;
    if (op == '|' || op == '^') return 1;
    return 0;
}

void apply(vector<int>& nums, vector<char>& ops){
    
    char op = ops.back(); ops.pop_back();

    if (op == '!') {              
        int a = nums.back(); nums.pop_back();
        nums.push_back(!a);
        return;
    }

    int a = nums.back(); nums.pop_back();
    int b = nums.back(); nums.pop_back();

    int n = 0;
    if (op == '|') n = (a || b);
    else if (op == '&') n = (a && b);
    else if (op == '^') n = (a ^ b);

    nums.push_back(n);
}

int main() 
{
	string s;
    getline(cin, s);

    vector<int> nums;
    vector<char> ops;

    size_t i = 0;
    while (i < s.length()){

        char c  = s[i];

        if (isdigit(static_cast<unsigned char>(c))){
            nums.push_back(c - '0');
            while (!ops.empty() && ops.back() == '!') {
                apply(nums, ops);
            }
        }
        if (c == '('){
            ops.push_back(c);
        }
        if (c == ')'){
            while (!ops.empty() && ops.back() != '(') {
                apply(nums, ops);
            }
            ops.pop_back();      
            while (!ops.empty() && ops.back() == '!') {
                apply(nums, ops);
            }
        }
        else if (c == '!') {
            ops.push_back(c);        
        }
        else if (c == '&' || c == '|' || c == '^') {
            while (!ops.empty() && ops.back() != '(' && prec(ops.back()) >= prec(c)) {
                apply(nums, ops);
            }
            ops.push_back(c);
        }
        i++;
    }

    while (!ops.empty()) {
        apply(nums, ops);
    }

    cout << nums.back() << endl;
    return 0;

	return 0;
}
