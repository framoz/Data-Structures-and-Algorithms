// -------------------------------------------------------------
// Algorithms and Data Structures 2024/2025 - LEIC (FCUP/FEUP)
// http://www.dcc.fc.up.pt/~pribeiro/aulas/aed2425/
// -------------------------------------------------------------
// A simple lightweight graph class
// Last update: 24/11/2024
// -------------------------------------------------------------

#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <list>
#include <memory>
#include <queue>
#include <algorithm>

class Graph {
    struct Edge {
        int dest; // Destination node
        int weight; // An integer weight
    };

    struct Node {
        std::list<Edge> adj; // The list of outgoing edges (to adjacent nodes)
        bool visited; // Has the node been visited in a graph traversal?
        int distance;
        int parent;
    };

    int n; // Graph size (vertices are numbered from 1 to n)
    bool hasDir; // false: undirected; true: directed
    std::vector<Node> nodes; // The list of nodes being represented

public:
    // Constructor: nr nodes and direction (default: undirected)
    Graph(int num, bool dir = false) : n(num), hasDir(dir), nodes(num + 1) {
    }

    // Add edge from source to destination with a certain weight
    void addEdge(int src, int dest, int weight = 1) {
        if (src < 1 || src > n || dest < 1 || dest > n) return;
        nodes[src].adj.push_back({dest, weight});
        if (!hasDir) nodes[dest].adj.push_back({src, weight});
    }

    // --------------------------------------------------------------

    // Read a graph in the format:
    // nr_nodes directed/undirected weighted/unweighted
    // nr_edges
    // src_1 dest_1 <weight_1>
    // src_2 dest_2 <weight_2>
    // ...
    // src_n dest_n <weight_n>
    static Graph *readGraph() {
        int n;
        std::string sdirection, sweight;
        std::cin >> n >> sdirection >> sweight;
        bool directed = (sdirection == "directed") ? true : false;
        bool weighted = (sweight == "weighted") ? true : false;

        Graph *g = new Graph(n, directed);
        int e;
        std::cin >> e;
        for (int i = 0; i < e; i++) {
            int u, v, w = 1;
            std::cin >> u >> v;
            if (weighted) std::cin >> w;
            g->addEdge(u, v, w);
        }
        return g;
    }

    // --------------------------------------------------------------
    // Depth-First Search (DFS): example implementation
    // --------------------------------------------------------------
    void dfs(int v) {
        std::cout << v << " "; // show node order
        nodes[v].visited = true;
        for (auto e: nodes[v].adj) {
            int w = e.dest;
            if (!nodes[w].visited)
                dfs(w);
        }
    }

    // --------------------------------------------------------------
    // Breadth-First Search (BFS): example implementation
    // --------------------------------------------------------------
    void bfs(int v) {
        for (int i = 1; i <= n; i++) nodes[i].visited = false;
        std::queue<int> q; // queue of unvisited nodes
        q.push(v);
        nodes[v].visited = true;
        while (!q.empty()) {
            // while there are still unvisited nodes
            int u = q.front();
            q.pop();
            std::cout << u << " "; // show node order
            for (auto e: nodes[u].adj) {
                int w = e.dest;
                if (!nodes[w].visited) {
                    q.push(w);
                    nodes[w].visited = true;
                }
            }
        }
    }


    // --------------------------------------------------------------

    // ---------------------------------------------------------
    // TODO: put the functions you need to implement below this
    // ---------------------------------------------------------

    int distance(int v, int b) {
        if (v == b) return 0;
        bool connects = false;
        for (int i = 1; i <= n; i++) nodes[i].visited = false;
        std::queue<int> q; // queue of unvisited nodes
        q.push(v);
        nodes[v].distance = 0;
        nodes[v].visited = true;
        while (!q.empty()) {
            // while there are still unvisited nodes
            int u = q.front();
            q.pop();
            //  std::cout << u << " ";  // show node order
            for (auto e: nodes[u].adj) {
                int w = e.dest;
                if (!nodes[w].visited) {
                    q.push(w);
                    nodes[w].visited = true;
                    nodes[w].distance = nodes[u].distance + 1;
                    if (w == b) connects = true;
                }
            }
        }

        if (!connects) return -1;
        return nodes[b].distance - nodes[v].distance;
    }

    int singleDiameter(int v) {
        int max = 0;
        int visits = 1;
        for (int i = 1; i <= n; i++) nodes[i].visited = false;
        std::queue<int> q; // queue of unvisited nodes
        q.push(v);
        nodes[v].distance = 0;
        visits++;
        nodes[v].visited = true;
        while (!q.empty()) {
            // while there are still unvisited nodes
            int u = q.front();
            q.pop();
            //  std::cout << u << " ";  // show node order
            for (auto e: nodes[u].adj) {
                int w = e.dest;
                if (!nodes[w].visited) {
                    q.push(w);
                    nodes[w].visited = true;
                    nodes[w].distance = nodes[u].distance + 1;
                    visits++;
                    //std::cout << visits << " ";
                    if (nodes[w].distance > max) max = nodes[w].distance;
                }
            }
        }
        if (visits != nodes.size()) return -1;
        return max;
    }

    int diameter() {
        int res = -1;

        for (int i = 1; i <= n; i++) {
            int sd = singleDiameter(i);
            if (sd == -1) return sd;
            if (sd > res) res = sd;
        }
        return res;
    }


    std::list<int> shortestPath(int a, int b) {
        std::list<int> res;
        if (a == b) {
            res.push_back(a);
            return res;
        }
        getPath(a, b, res);
        return res;
    }

    void getPath(int v, int b, std::list<int> &path) {
        for (int i = 1; i <= n; i++) {
            nodes[i].visited = false;
            nodes[i].distance = 0;
            nodes[i].parent = 0;
        }

        std::queue<int> q; // queue of unvisited nodes
        q.push(v);
        nodes[v].visited = true;
        nodes[v].parent = v;
        while (!q.empty()) {
            // while there are still unvisited nodes
            int u = q.front();
            q.pop();
            //std::cout << u << " ";  // show node order
            for (auto e: nodes[u].adj) {
                int w = e.dest;
                if (!nodes[w].visited) {
                    q.push(w);
                    nodes[w].visited = true;
                    nodes[w].distance = nodes[u].distance + 1;
                    nodes[w].parent = u;

                } else if (nodes[w].parent > u and nodes[w].distance == nodes[u].distance +1) {
                    nodes[w].parent = u;
                }
            }
        }
        if (nodes[b].parent == 0) { return; }
        int x = b;
        path.push_front(x);
        while (x != v) {
            x = nodes[x].parent;
            path.push_front(x);
        }
    }


};

#endif
