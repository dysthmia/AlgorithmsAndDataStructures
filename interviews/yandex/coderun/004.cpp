#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

class binary_tree {
    private:
        struct node {
            int value;
            node* left;
            node* right;

            node(const int& val) 
                : value(val), left(nullptr), right(nullptr)
            {
            }
        };
        node* _head;
        size_t _size;
    
        void make_head(int x) {
            _head = new node(x);
            _size++;
        }

        void insert_new_node (int x, node* cur) {
            if (x == cur->value) return;

            node*& child = (cur->value < x) ? cur->right : cur->left;

            if (child == nullptr) {
                child = new node(x);
                _size++;
            } else insert_new_node(x, child);
        }

        void print_rec (node* cur) const {
            if (cur == nullptr) return;
            print_rec(cur->left);
            cout << cur->value << ' ';
            print_rec(cur->right);
        }

        int get_height (node* cur) const  {
            if (cur == nullptr) return 0;
            int left_h = get_height(cur->left);
            int right_h = get_height(cur->right);
            return max(left_h, right_h) + 1;
        }

    public:
        binary_tree () : _head(nullptr), _size(0)
        {
        }

        void insert(int x) {
            if (_head == nullptr) make_head(x);
            insert_new_node (x, _head);
        }

        void print() const {
            if (_head == nullptr) {
                cout << "[empty]" << '\n';
                return;
            }
            print_rec(_head);
            cout << '\n';
        }

        void levels() const {
            cout << get_height(_head) << '\n';
        }
};


int main () {

    binary_tree bt;
    
    string s; 
    getline (cin, s);
    istringstream iss (s);

    int x; 
    while (iss >> x) {
        if (x!=0) {
            bt.insert(x);
        }
    }

    bt.levels();

    return 0;
}