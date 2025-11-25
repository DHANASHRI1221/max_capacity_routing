#pragma once
#include <bits/stdc++.h>
#include "graph_loader.hpp"
#include "utils.hpp"
using namespace std;

pair<vector<int>, double> widest_path(const Graph &G, int src, int dst) {
    int n = G.size();
    vector<double> best(n, 0.0);
    vector<int> parent(n, -1);
    vector<int> vis(n, 0);

    best[src] = 1e18;

    priority_queue<pair<double,int>> pq;
    pq.push({best[src], src});

    while (!pq.empty()) {
        auto it = pq.top(); pq.pop();
        int u = it.second;
        double cap = it.first;
        if (vis[u]) continue;
        vis[u] = 1;

        if (u == dst) break;

        for (auto &e : G[u]) {
            double new_cap = min(cap, e.capacity);
            if (new_cap > best[e.to]) {
                best[e.to] = new_cap;
                parent[e.to] = u;
                pq.push({new_cap, e.to});
            }
        }
    }

    if (best[dst] == 0.0) return {{}, 0.0};

    vector<int> path;
    for (int v = dst; v != -1; v = parent[v]) path.push_back(v);
    reverse(path.begin(), path.end());

    return {path, best[dst]};
}
