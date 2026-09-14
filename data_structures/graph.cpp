#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <set>
#include <map>

template<class T>
class graph {

    private:

        bool is_directed_;

        std::map<T, std::set<T>> graph_;

        enum class color_ {white, gray, black};

        bool find_cycle_(std::vector<T>& cycle){
            // (o_o) i dont wanna write this code;
        }
        
    public:

        graph (bool orientir){
            is_directed_ = orientir;
        }

        int vertex_count() const { return graph_.size(); }
        int edge_count() const {
            int sum = 0;
            for (auto& s : graph_) { sum += s.size(); }
            return sum;
        }

        void add_vertex(T vert){
            graph_[vert];
        }

        void add_edge(T from, T to){
            add_vertex(from);
            add_vertex(to);
            graph_[from].insert(to);
            if (is_directed_) {
                graph_[to].insert(from);
            }
        }

        void print() const {
            for (const auto& [key, value] : graph_) {
                std::cout << key << ": ";
                const char* sep = "";
                for (const auto& v : value) {
                    std::cout << sep << v;
                    sep = ", ";
                }
                std::cout << '\n';
            }
        }

        std::vector<T> BFS (int start) const {
            
            std::unordered_set<T> visited;
            std::queue<T> qu;
            std::vector<T> result;

            visited.insert(start);
            qu.push(start);
            
            while (!qu.empty()){

                T cur = qu.front();
                qu.pop();

                result.push_back(cur);

                auto it = graph_.find(cur);
                if (it == graph_.end()){
                    continue;
                }

                for (const auto& n : it->second){
                    if (visited.insert(n).second){
                        qu.push(n);
                    }
                }

            }

            return result;
        } 

        std::vector<T> DFS (int start) const {

            std::unordered_set<T> visited;
            std::stack<T> st;
            std::vector<T> result;

            visited.insert(start);
            st.push(start);

            while (!st.empty()) {
                
                T cur = st.top();
                st.pop();

                result.push_back(cur);

                auto it = graph_.find(cur);
                if (it == graph_.end()){
                    continue;
                }

                for (const auto& n : it->second){
                    if (visited.insert(n).second){
                        st.push(n);
                    }
                }
            }

            return result;
        } 

        bool has_cycle () const {
            std::vector<T> cycle;
            return find_cycle_(cycle);
        }

        std::vector<T> get_cycle () const {
            std::vector<T> cycle;
            find_cycle_(cycle);
            return(cycle);
        }
};

int main(){

    graph<int> gr(false);
    
    gr.add_edge(2,1);
    gr.add_edge(1,4);
    gr.add_edge(1,5);
    gr.add_edge(5,6);
    gr.add_edge(2,3);
    gr.add_edge(3,7);
    
    std::vector<int> dfs = gr.DFS(2);
    for (int i=0; i<dfs.size(); i++){
        std::cout<<dfs[i] << " ";
    }
    return 0;
}