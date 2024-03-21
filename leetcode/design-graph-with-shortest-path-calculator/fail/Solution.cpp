#include <vector>
#include <map>
#include <string>
#include <iostream>

using namespace std;

long g_res = 2147483647;

class Graph {
public:

    long res;

    class Node
    {
        public:
            map<int, int> edges;
            int           from;

            Node(int from) {
                this->from = from;
            }

            Node(int from, int to, long cost) {
                this->edges[to] = cost;
                this->from = from;
            }

            void add(int to, long cost) {
                this->edges[to] = cost;
            }

            long search_path(map<int, Node> &m, int from, int to, long cost) {
                long res;

                if (to == this->from)
                    return cost;

                else if (from == this->from or this->edges.size() == 0)
                    return -1;

                for (auto node: edges) {
                    if (node.second + cost > g_res)
                        continue ;
                    cost += node.second;
                    auto it = m.find(node.first);
                    res = it->second.search_path(m, this->from, to, cost);
                    if (res > 0 and res < g_res)
                        g_res = res;
                    else
                        cost -= node.second;
                }
                return -1;
            }
    };

    map<int, Node>    m;

    Graph(int n, vector<vector<int>>& edges): res(0) {
        map<int, Node>::iterator  it;

        for (auto node: edges) {
            it = this->m.find(node[0]);
            if (it != this->m.end()) {
                it->second.add(node[1], node[2]);
            } else {
                this->m.insert(std::make_pair(node[0], Node(node[0], node[1], node[2])));
            }
            it = this->m.find(node[1]);
            if (it == this->m.end()) {
                this->m.insert(std::make_pair(node[1], Node(node[1])));
            }
        }
    }

    void addEdge(vector<int> edge) {
        auto it = this->m.find(edge[0]);
        if (it != this->m.end()) {
            it->second.add(edge[1], edge[2]);
        } else {
            this->m.insert(std::make_pair(edge[0], Node(edge[0], edge[1], edge[2])));
        }
    }

    int shortestPath(int node1, int node2) {
        long res;

        auto it = this->m.find(node1);
        if (it == this->m.end())
            return -1;

        it->second.search_path(this->m, -1, node2, 0);
        res = g_res;
        g_res = 2147483647;
        if (res == 2147483647)
            return -1;
        return res;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */

int main() {
	vector<vector<int>> vv = {{0, 2, 5}, {0, 1, 2}, {1, 2, 1}, {3, 0, 3}};
    vector<int> v = {1, 3, 4};
	Graph g(4, vv);

    cout << g.shortestPath(3, 2) << endl;
    cout << g.shortestPath(0, 3) << endl;
    g.addEdge(v);
    cout << g.shortestPath(0, 3) << endl;
    cout << g.shortestPath(1, 2) << endl;
	return 0;
}

