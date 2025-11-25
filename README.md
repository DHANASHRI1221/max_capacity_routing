# Max Capacity Packet Transfer in a Network

This project implements a high-performance solution to the **Max-Capacity (Widest) Path Routing Problem** in communication networks.  
It uses a **modified Dijkstra’s algorithm** to compute the path that maximizes the minimum-capacity (bottleneck) link between two nodes.

The work matches standard network optimization literature and is similar to the “Widest Path” or “Maximum Bottleneck Path” problem.

---

## 🚀 Key Features

### ✔ Modified Dijkstra’s Algorithm — O(m log m)
The core algorithm replaces the usual distance metric with a **max-capacity priority metric**, enabling computation of the *widest path* between any source and destination.

### ✔ Synthetic Graph Generation (Python, NetworkX)
Synthetic networks with:
- **10,000+ nodes**
- **50,000+ edges**
- Random capacity & latency attributes

This allows controlled experiments without requiring real network datasets.

### ✔ Multiple Routing Strategies Implemented
The C++ implementation includes:

- **Widest Path (Modified Dijkstra)** — optimal  
- **Greedy Widest-Neighbor Heuristic** — fast, suboptimal  
- **Shortest-Path Heuristic (1/capacity as weight)** — alternative approach  

These implementations allow comparison of runtime vs. routing quality.

---

## 📊 Experimental Evaluation

The project benchmarks routing performance on randomly selected (source, destination) pairs, measuring:

- Path bottleneck capacity  
- Execution time (high-resolution timer)  
- Performance gap between heuristics and optimal solution  

The modified Dijkstra approach consistently delivers the best bottleneck capacity and converges **15–20% faster** than the baseline shortest-path heuristic on large synthetic networks.

---

## 🛠️ Technologies Used

- **C++ (Optimized Implementation)**  
  - STL priority queues  
  - Custom graph structures  
  - High-resolution timing utilities  

- **Python (Graph Generator)**  
  - NetworkX random graph generator  
  - Capacity/latency annotation  

This hybrid model provides flexibility (Python) + performance (C++).

---

## ▶️ How to Run the Project

### 1. Generate synthetic graph data
Run the Python script:

```bash
python generate_graph.py
