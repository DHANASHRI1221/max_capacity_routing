#pragma once
#include <bits/stdc++.h>
#include "graph_loader.hpp"
#include "utils.hpp"
using namespace std;

// Greedy Heuristic
pair<vector<int>, double> greedy_widest(const Graph &G, int src, int dst) {
    int n = G.size();
    vector<int> vis(n, 0);
    vis[src] = 1;

    vector<int> path = {src};
    double bottleneck = 1e18;
    int curr = src;

    while (curr != dst) {
        double best_cap = -1;
        int best_v = -1;

        for (auto &e : G[curr]) {
            if (!vis[e.to] && e.capacity > best_cap) {
                best_cap = e.capacity;
                best_v = e.to;
            }
        }

        if (best_v == -1) return {{}, 0.0};

        bottleneck = min(bottleneck, best_cap);
        path.push_back(best_v);
        vis[best_v] = 1;
        curr = best_v;
    }

    return {path, bottleneck};
}


// Shortest-Path Heuristic (1/capacity)
pair<vector<int>, double> shortest_path_heuristic(const Graph &G, int src, int dst) {
    int n = G.size();
    vector<double> dist(n, 1e18);
    vector<int> parent(n, -1);

    dist[src] = 0;
    priority_queue<pair<double,int>, vector<pair<double,int>>, greater<pair<double,int>>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        auto it = pq.top(); pq.pop();
        int u = it.second;
        if (u == dst) break;

        for (auto &e : G[u]) {
            double w = 1.0 / e.capacity;
            if (dist[u] + w < dist[e.to]) {
                dist[e.to] = dist[u] + w;
                parent[e.to] = u;
                pq.push({dist[e.to], e.to});
            }
        }
    }

    if (dist[dst] == 1e18) return {{}, 0.0};

    vector<int> path;
    for (int v = dst; v != -1; v = parent[v]) path.push_back(v);
    reverse(path.begin(), path.end());

    double bottleneck = 1e18;
    for (int i = 0; i < path.size() - 1; i++) {
        int u = path[i], v = path[i + 1];
        for (auto &e : G[u]) if (e.to == v) bottleneck = min(bottleneck, e.capacity);
    }

    return {path, bottleneck};
}
