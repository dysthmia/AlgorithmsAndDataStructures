# Алгоритмы и структуры данных

## Типы данных C++ для алгоритмов

### Структуры данных

| Тип | Описание | Основные методы | Пример |
|---|---|---|---|
| `vector<T>` | Динамический массив | `push_back()` `pop_back()` `size()` `[]` `begin()/end()` | `vector<int> v = {1,2,3}; v.push_back(4);` |
| `deque<T>` | Двусторонняя очередь | `push_front()` `push_back()` `pop_front()` `pop_back()` | `deque<int> d; d.push_front(1);` |
| `stack<T>` | Стек (LIFO) | `push()` `pop()` `top()` `empty()` | `stack<int> s; s.push(5); s.top();` |
| `queue<T>` | Очередь (FIFO) | `push()` `pop()` `front()` `back()` | `queue<int> q; q.push(1);` |
| `priority_queue<T>` | Куча (max-heap по умолчанию) | `push()` `pop()` `top()` | `priority_queue<int> pq; pq.push(3);` |
| `set<T>` | Упорядоченное множество (дерево) | `insert()` `erase()` `find()` `count()` `lower_bound()` | `set<int> s; s.insert(5);` |
| `multiset<T>` | Множество с повторами | те же, что `set` | `multiset<int> ms; ms.insert(2);` |
| `unordered_set<T>` | Множество на хэш-таблице | `insert()` `find()` `erase()` `count()` | `unordered_set<int> us; us.insert(7);` |
| `map<K,V>` | Упорядоченный словарь | `insert()` `[]` `find()` `erase()` `count()` | `map<string,int> m; m["a"] = 1;` |
| `unordered_map<K,V>` | Словарь на хэш-таблице | те же, что `map` | `unordered_map<string,int> um; um["x"]++;` |
| `pair<A,B>` | Пара значений | `.first` `.second` `make_pair()` | `pair<int,int> p = {1,2};` |
| `tuple<...>` | Кортеж значений | `get<i>()` `make_tuple()` | `tuple<int,string,double> t = {1,"a",2.5};` |
| `string` | Строка | `substr()` `find()` `append()` `size()` `+` | `string s = "hello"; s += " world";` |
| `list<T>` | Двусвязный список | `push_back()` `push_front()` `insert()` `erase()` | `list<int> l; l.push_back(1);` |
| `bitset<N>` | Битовый набор | `set()` `reset()` `flip()` `count()` `test()` | `bitset<8> b; b.set(3);` |
| `array<T,N>` | Массив фиксированного размера | `size()` `fill()` `[]` | `array<int,5> a = {1,2,3,4,5};` |

## Сложность операций

| Структура | Вставка | Поиск | Удаление |
|---|:---:|:---:|:---:|
| `vector` | O(1) / O(n) | O(n) | O(n) |
| `set` / `map` | O(log n) | O(log n) | O(log n) |
| `unordered_set` / `unordered_map` | O(1)* | O(1)* | O(1)* |
| `stack` / `queue` / `deque` | O(1) | — | O(1) |
| `priority_queue` | O(log n) | O(1) (top) | O(log n) |

*в среднем; в худшем случае O(n)*

