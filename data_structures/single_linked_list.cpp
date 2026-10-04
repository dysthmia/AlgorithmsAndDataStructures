
template <typename T>
class SingleLinkedList {

    private:

        struct Node
        {
            T value;
            Node* next;

            Node (const T& val) :
                value(val), next(nullptr)
            {  
            }
        }; 

        Node _head;
        std::size_t _size;
    
    public:

        SingleLinkedList() 
            : _head(nullptr), _size(0)
        {
        }

        ~SingleLinkedList()
        {
            clear();
        }

        SingleLinkedList(const SingleLinkedList&) = delete;
        SingleLinkedList& operator= (const SingleLinkedList&) = delete;

        bool empty () const {
            return _head == nullptr;
        }

        std::size_t size () const {
            return _size;
        }

        void push_front (const T& value) {
            Node* node = new Node(value);
            node->next = _head;
            _head = node;
            _size++;
        }

        void push_back (const T& value) {
            Node* node = new Node(value);
            if (_head == nullptr){
                _head = node;
            } else {
                Node* cur = _head;
                while (cur->next != nullptr){
                    cur = cur->next;
                }
                cur->next = node;    
            }
            _size++;
        }

        void insert (std::size_t index, const T& value) {
            if (index > _size) {
                throw std::out_of_range("index out of range");
            }

            if (index == 0) {
                push_front (val);
                return;
            }

            Node* prev = _head;
            for (std::size_t i = 0; i+1<index; i++){
                prev = prev->next;
            }

            Node* node = new Node(value);
            node->next = prev->next;
            prev->next = node;
            _size++;
        }

        void pop_front () {
            if (_head == nullptr) {
                throw std::out_of_range("list is empty");
            }
            Node* cur = _head;
            _head = cur->next;
            delete cur;
            _size--;
        }

        void pop_back () {
            if (_head == nullptr) {
                throw std::out_of_range("list is empty");
            }

            if (_head->next == nullptr) {
                delete _head;
                _head = nullptr;
                _size--;
                return;
            }

            Node* cur = _head;
            while (cur->next->next != nullptr) {
                cur = cur->next;
            }

            delete cur->next;
            cur->next = nullptr;
            _size--;
        }

        void erase (std::size_t index) {
            if (index >= _size) {
                throw std::out_of_range("index out of range");
            }

            if (index == 0) {
                pop_front();
                return;
            }

            Node* cur = _head;
            for (std::size_t i = 0; i+1<index;i++) {
                cur = cur->next;
            }

            Node* target = cur->next;
            cur->next = target->next;
            delete target;
            _size--;
        }

        bool remove (const T& value) {
            if (_head == nullptr) {
                return false;
            }

            if (_head->value == value) {
                pop_front();
                return true;
            }

            Node* cur = _head;
            while (cur->next != nullptr && !(cur->next->value == value)) {
                cur = cur->next;
            }

            if (cur->next == nullptr) {
                return false;
            }

            Node* target = cur->next;
            cur->next = target->next;
            delete target;
            _size--;
            return true;
        }

        const T& at (std::size_t index) const {
            if (index >= _size) {
                throw std::out_of_range("index out of range");
            }

            Node* cur = _head;
            for (std::size_t i = 0; i < index; i++) {
                cur = cur->next;
            }
            return cur->value;
        }

        bool have_circle () const {
            Node* slow = _head;
            Node* fast = _head;

            while (fast != nullptr && fast->next != nullptr) {
                slow = slow->next;
                fast = fast->next->next;

                if (slow == fast) {
                    return true;
                }
            }

            return false;
        }
};
