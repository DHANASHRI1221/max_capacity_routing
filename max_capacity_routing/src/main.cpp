#include <bits/stdc++.h>
using namespace std;

#include "graph_loader.hpp"
#include "widest_path.hpp"
#include "heuristics.hpp"
#include "utils.hpp"

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N = 10000;
    string file = "../data/graph_simple.txt";

    cout << "[INFO] Loading graph...\n";
    Graph G = load_graph(file, N);

    mt19937 rng(1);
    uniform_int_distribution<int> dist(0, N - 1);

    for (int i = 1; i <= 5; i++) {
        int src = dist(rng);
        int dst = dist(rng);
        while (src == dst) dst = dist(rng);

        cout << "\n=== Pair " << i << " : " << src << " -> " << dst << " ===\n";

        // Widest Path
        TimePoint t1 = Clock::now();
        auto it1 = widest_path(G, src, dst);
        cout << "Widest-Dijkstra: cap=" << it1.second
             << " time=" << elapsed(t1) << "s\n";

        // Greedy
        t1 = Clock::now();
        auto it2 = greedy_widest(G, src, dst);
        cout << "Greedy:          cap=" << it2.second
             << " time=" << elapsed(t1) << "s\n";

        // Shortest Path Heuristic
        t1 = Clock::now();
        auto it3 = shortest_path_heuristic(G, src, dst);
        cout << "SP-Heuristic:    cap=" << it3.second
             << " time=" << elapsed(t1) << "s\n";
    }

    return 0;
}
