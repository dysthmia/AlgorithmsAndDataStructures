#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() 
{
    string s;
    getline (cin , s);

    vector<int> nums;
    vector<int> ops;

    size_t i = 0;

    while (i < s.length()){

        char c = s[i];

        if (isdigit(static_cast<unsigned char>(s[i]))){
            int n = s[i] - '0';
            nums.push_back(n);
        }
        else if (c == '+'){
            int a = nums.back(); nums.pop_back();
            int b = nums.back(); nums.pop_back();
            nums.push_back(a+b);
        }
        else if (c == '*'){
            int a = nums.back(); nums.pop_back();
            int b = nums.back(); nums.pop_back();
            nums.push_back(a*b);
        }
        else if (c == '-'){
            int a = nums.back(); nums.pop_back();
            int b = nums.back(); nums.pop_back();
            nums.push_back(b-a);
        }

        i++;
    }

    cout << nums.back() << "\n";

	return 0;
}
