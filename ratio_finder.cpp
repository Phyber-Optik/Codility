#include<bits/stdc++.h>

using namespace std;

class Edge {
public:
    float multiplier;
    string destination;
    Edge(float mul, string des) : multiplier(mul), destination(des) {}
};

class Graph {
public:
    unordered_map<string, vector<Edge>>graph;
    void add_conversion(string src, string des, float mul) {
        graph[src].push_back(Edge(mul, des));
        graph[des].push_back(Edge(1.0 / mul, src));
    }

    float find_multiplier(string src, string des) {
        int sz = graph.size();
        unordered_set<string>visited;
        unordered_map<string, float>multipliers;
        queue<string>q;
        multipliers[src] = 1.0;
        q.push(src);
        while(!q.empty()) {
            string u = q.front();
            if(u == des) {
                return multipliers[u];
            }
            visited.insert(u);
            q.pop();
            for(auto v: graph[u]) {
                if(visited.find(v.destination) == visited.end()) {
                    multipliers[v.destination] = v.multiplier * multipliers[u];
                    q.push(v.destination);
                }
            }
        }
        return -1;
    }
};

int main() {
    Graph g = Graph();
    g.add_conversion("foot", "inch", 12.0);
    g.add_conversion("hand", "inch", 4);
    g.add_conversion("foot", "mile", 0.000189394);
    g.add_conversion("mile", "lightyear", 1.70108e-13);
    cout<<g.find_multiplier("hand", "lightyear");
}
