#include<bits/stdc++.h>

using namespace std;

class Node {
    int val;
    vector<Node*>neighbors;
public:
    Node(int val) : val(val) {}
    vector<Node*> get_neighbors() {
        return this->neighbors;
    }
    void add_neighbor(Node* node) {
        this->neighbors.push_back(node);
    }
    int get_val() {
        return this->val;
    }
};

class Graph {
    vector<Node*>nodes;
    unordered_map<Node*, int>visited;
    unordered_map<string, int>node_mapping;
    unordered_map<int, string>reverse_mapping;
    int cur_node_val;
    stack<string>order;

public:
    Graph() : cur_node_val(0) {}

    Node* get(string val) {
        if(node_mapping.find(val) == node_mapping.end()) {
            reverse_mapping[cur_node_val] = val;
            node_mapping[val] = cur_node_val++;
            Node* node = new Node(node_mapping[val]);
            nodes.push_back(node);
        }
        return nodes[node_mapping[val]];
    }

    void add_edge(string u, string v) {
        Node* u_node = get(u);
        Node* v_node = get(v);

        u_node->add_neighbor(v_node);
    }

    void find_order() {
        bool is_valid = true;
        for(auto node: this->nodes) {
            if(!visited[node]) {
                is_valid &= dfs(node);
            }
        }
        if(!is_valid) {
            printf("Ordering isn't possible");
        }
        else {
            while(!order.empty()) {
                cout<<order.top()<<" ";
                order.pop();
            }
        }
    }

    bool dfs(Node* node) {
        cout<<reverse_mapping[node->get_val()]<<endl;
        visited[node] = 1;
        bool ret = true;
        for(auto x: node->get_neighbors()) {
            if(!visited[x]) {
                ret &= dfs(x);
            }
            else if(visited[x] == 1){
                return false;
            }
        }
        visited[node] = 2;
        order.push(reverse_mapping[node->get_val()]);
        return ret;
    }
};

int main() {
    Graph graph = Graph();
    vector<string>subs = vector<string> {"a", "b", "c", "d", "e", "f"};
    for(auto x: subs){
        graph.get(x);
    }
    graph.add_edge("a", "d");
    graph.add_edge("f", "b");
    graph.add_edge("b", "d");
    graph.add_edge("f", "a");
    graph.add_edge("d", "c");
    graph.find_order();
    return 0;
}