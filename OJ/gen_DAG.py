import random
import os

def generate_dag(N, M):
    assert M <= N * (N - 1) // 2, "Too many edges for DAG"

    nodes = list(range(1, N + 1))
    random.shuffle(nodes)  # Random topological order

    edges = set()

    # Try generating unique edges until we reach M
    while len(edges) < M:
        u_idx = random.randint(0, N - 2)
        v_idx = random.randint(u_idx + 1, N - 1)  # u_idx < v_idx ensures acyclic

        u = nodes[u_idx]
        v = nodes[v_idx]

        edges.add((u, v))

    return N, M, list(edges)

def write_testcase_to_file(test_id, N, M, edges, out_dir="testcases"):
    os.makedirs(out_dir, exist_ok=True)
    filename = os.path.join(out_dir, f"testcase_{test_id}.txt")

    with open(filename, "w") as f:
        f.write(f"{N} {M}\n")
        for u, v in edges:
            f.write(f"{u} {v}\n")

def generate_multiple_testcases(startin,num_cases, max_n=100000, max_m=100000):
    for i in range(1, num_cases + 1):
        N = random.randint(max_n // 2, max_n)
        max_possible_edges = N * (N - 1) // 2
        M = min(random.randint(max_m // 2, max_m), max_possible_edges)

        N, M, edges = generate_dag(N, M)
        write_testcase_to_file(startin+ i, N, M, edges)
        print(f"Generated testcase {startin + i}: N={N}, M={M}, edges written.")

generate_multiple_testcases(11,9,1e5,1e5)  # change number of testcases here
