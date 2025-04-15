import random
import os

def generate_test_case(file_name):
    T = 100
    
    with open(file_name, "w") as f:
        f.write(f"{T}\n")
        
        for _ in range(T):
            N = random.randint(3,10**5)
            # N = 10**4
            arr = [random.randint(-10**9, 10**9) for _ in range(N)]
            
            f.write(f"{N}\n")
            f.write(" ".join(map(str, arr)) + "\n")

for i in range(9,10):
    generate_test_case(f"/home/om/Acads/Codeforces-Contests/OJ/testcases_{i+1}.txt")
    print(f"Test case file 'testcases_{i+1}.txt' generated successfully!")