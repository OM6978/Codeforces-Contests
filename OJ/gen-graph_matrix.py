import random
import os

def generate_test_case(n, k, max_weight=1, mod=10**9 + 7):
    adj_matrix = [[random.randint(0, max_weight) for _ in range(n)] for _ in range(n)]
    return n, k, adj_matrix

def save_test_case(filename, n, k, adj_matrix):
    with open(filename, "w") as f:
        f.write(f"{n} {k}\n")
        for row in adj_matrix:
            f.write(" ".join(map(str, row)) + "\n")

def main():
    """Generates and saves multiple test cases for each subpart."""
    test_cases = {
        "subpart1": [(random.randint(5, 10), 2) for _ in range(5)],
        "subpart2": [(random.randint(10, 50), random.randint(2, 30)) for _ in range(5)],
        "subpart3": [(random.randint(50, 100), random.randint(10**8, 10**9)) for _ in range(5)]
    }
    
    for subpart, cases in test_cases.items():
        for i, (n, k) in enumerate(cases):
            os.system(f'touch {subpart}_test_case_{i + 1}.txt')
            n, k, adj_matrix = generate_test_case(n, k)
            save_test_case(f"/home/om/Acads/Codeforces-Contests/OJ/{subpart}_test_case_{i + 1}.txt", n, k, adj_matrix)
    
    print("Test cases generated and saved for all subparts.")

if __name__ == "__main__":
    main()