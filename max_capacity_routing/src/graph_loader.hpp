#pragma once
#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int to;
    double capacity;
    double latency;
};

using Graph = vector<vector<Edge>>;

Graph load_graph(string filename, int n) {
    Graph G(n);
    ifstream in(filename);
    int u, v;
    double cap, lat;

    while (in >> u >> v >> cap >> lat) {
        G[u].push_back({v, cap, lat});
        G[v].push_back({u, cap, lat});
    }
    return G;
}
