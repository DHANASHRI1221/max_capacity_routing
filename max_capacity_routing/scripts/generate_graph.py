import networkx as nx
import random
import os

# CHANGE THIS TO YOUR EXACT FOLDER
OUTPUT_PATH = r"C:\Users\DHANASHRI\Downloads\max_capacity_routing\data\graph_simple.txt"

def generate_network(n=10000, m=50000):
    print("[INFO] Generating synthetic graph...")

    # Ensure the directory exists
    os.makedirs(os.path.dirname(OUTPUT_PATH), exist_ok=True)

    G = nx.gnm_random_graph(n, m, seed=42)

    with open(OUTPUT_PATH, "w") as f:
        for u, v in G.edges():
            cap = random.randint(1, 100)
            lat = random.uniform(1.0, 10.0)
            f.write(f"{u} {v} {cap} {lat}\n")

    print(f"[INFO] Graph saved to {OUTPUT_PATH}")

generate_network()
