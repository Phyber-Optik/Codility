#include<bits/stdc++.h>

using namespace std;

class Node {
public:    
    int val;
    vector<Node*>neighbors;
    Node() {};
    Node(int val) {
        this->val = val;
    }
    void add_neighbor(Node* neighbor) {
        neighbors.push_back(neighbor);
    }
};

class Graph {
public:
    vector<Node*>nodes;
    unordered_map<int, int>node_mapping;
    unordered_map<Node*, bool>visited;
    int cur_node_val;
    
    Graph() {
        this->cur_node_val = 0;
    }
    
    Node* get_node(int u){
        if(node_mapping.find(u) == node_mapping.end()) {
            node_mapping[u] = this->cur_node_val++;
            Node* cur_node = new Node(node_mapping[u]);
            nodes.push_back(cur_node);
        }
        return nodes[node_mapping[u]];
    }

    vector<Node*> get_neighbors(Node* node) {
        return node->neighbors;
    }
    
    void add_edge(int u, int v) {
        Node* u_node = get_node(u);
        Node* v_node = get_node(v);

        u_node->add_neighbor(v_node);
        v_node->add_neighbor(u_node);
    }

    bool search(Node* root, Node* dest) {
        visited[root] = true;
        if(root == dest) return true;
        bool reachable = false;
        for(Node* x: get_neighbors(root)) {
            if(!visited[x]) {
                reachable |= search(x, dest);
            }
        }
        return reachable;
    }

    void check_reachability(int dest) {
        bool reachable = search(get_node(1), get_node(dest));
        if(reachable) {
            printf("Reachable\n");
        }
        else printf("Not reachable\n");
    }
};

int main() {
    Graph g = Graph();
    g.add_edge(1, 2);
    g.add_edge(2, 3);
    g.check_reachability(3);
    return 0;
}