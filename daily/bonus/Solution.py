import collections
import heapq
import json
import random
import sys

# Set a higher recursion limit for safety, although the solution is iterative.
sys.setrecursionlimit(200000)

class Solution:
    """
    Contains the method to solve the Consul's Journey problem.
    This class will be instantiated by the test generation script.
    """
    def consulJourney(self, n: int, flights: list[list[int]], capital: int, destination: int, embassies: list[int], k: int) -> int:
        # --- Edge Case Handling ---
        if k == 0:
            adj = collections.defaultdict(list)
            for u, v, w in flights:
                adj[u].append((v, w))
            pq = [(0, capital)]
            min_times = {capital: 0}
            while pq:
                time, u = heapq.heappop(pq)
                if u == destination:
                    return time
                if time > min_times.get(u, float('inf')):
                    continue
                for v, weight in adj.get(u, []):
                    if time + weight < min_times.get(v, float('inf')):
                        min_times[v] = time + weight
                        heapq.heappush(pq, (min_times[v], v))
            return min_times.get(destination, -1 if min_times.get(destination, float('inf')) == float('inf') else min_times.get(destination))


        if k > len(embassies):
            return -1

        # --- Stage 1: Pre-computation (Building the Meta-Graph) ---
        adj = collections.defaultdict(list)
        rev_adj = collections.defaultdict(list)
        for u, v, w in flights:
            adj[u].append((v, w))
            rev_adj[v].append((u, w))

        memo_dijkstra = {}
        def dijkstra(start_node, graph_adj):
            # Memoization for Dijkstra runs to avoid re-computation if possible
            if (start_node, id(graph_adj)) in memo_dijkstra:
                return memo_dijkstra[(start_node, id(graph_adj))]

            distances = {i: float('inf') for i in range(n)}
            distances[start_node] = 0
            pq = [(0, start_node)]
            while pq:
                dist, u = heapq.heappop(pq)
                if dist > distances[u]:
                    continue
                for v_node, weight in graph_adj.get(u, []):
                    if distances[u] + weight < distances.get(v_node, float('inf')):
                        distances[v_node] = distances[u] + weight
                        heapq.heappush(pq, (distances[v_node], v_node))
            
            memo_dijkstra[(start_node, id(graph_adj))] = distances
            return distances

        from_capital_dist = dijkstra(capital, adj)
        to_dest_dist = dijkstra(destination, rev_adj)
        
        num_emb = len(embassies)
        emb_to_idx = {emb: i for i, emb in enumerate(embassies)}

        embassy_dists = [[float('inf')] * num_emb for _ in range(num_emb)]
        for i in range(num_emb):
            start_embassy_node = embassies[i]
            dists_from_emb = dijkstra(start_embassy_node, adj)
            for j in range(num_emb):
                if i == j: continue
                embassy_dists[i][j] = dists_from_emb.get(embassies[j], float('inf'))
        
        # --- Stage 2: TSP-style DP with Bitmasking ---
        dp = [[float('inf')] * num_emb for _ in range(1 << num_emb)]
        
        for i in range(num_emb):
            cost_to_first_emb = from_capital_dist.get(embassies[i], float('inf'))
            if cost_to_first_emb != float('inf'):
                dp[1 << i][i] = cost_to_first_emb
        
        for mask in range(1, 1 << num_emb):
            for i in range(num_emb):
                if (mask >> i) & 1:
                    if dp[mask][i] == float('inf'):
                        continue
                    for j in range(num_emb):
                        if not ((mask >> j) & 1):
                            new_mask = mask | (1 << j)
                            travel_cost = embassy_dists[i][j]
                            if travel_cost != float('inf'):
                                new_cost = dp[mask][i] + travel_cost
                                dp[new_mask][j] = min(dp[new_mask][j], new_cost)
        
        # --- Final Result Calculation ---
        min_total_time = float('inf')
        for mask in range(1 << num_emb):
            if bin(mask).count('1') == k:
                for i in range(num_emb):
                    if (mask >> i) & 1:
                        path_to_last_emb_cost = dp[mask][i]
                        if path_to_last_emb_cost != float('inf'):
                            final_leg_cost = to_dest_dist.get(embassies[i], float('inf'))
                            if final_leg_cost != float('inf'):
                                min_total_time = min(min_total_time, path_to_last_emb_cost + final_leg_cost)
                                
        return min_total_time if min_total_time != float('inf') else -1


def generate_test_case(case_id):
    """Generates a single test case with varying properties based on its ID."""
    if case_id < 20:
        n = random.randint(5, 20)
        m = random.randint(n, n * 2)
        num_emb = random.randint(1, min(n - 2, 6)) if n > 2 else 0
    elif case_id < 100:
        n = random.randint(20, 100)
        m = random.randint(n, n * 4)
        num_emb = random.randint(4, 10)
    elif case_id < 450:
        n = random.randint(1000, 40000)
        m = random.randint(n, n + 50000)
        num_emb = random.randint(10, 16)
    else:
        n = random.randint(45000, 50000)
        m = random.randint(140000, 150000)
        num_emb = 16

    flights = set()
    while len(flights) < m and len(flights) < n * (n - 1):
        u, v = random.sample(range(n), 2)
        flights.add((u, v))
    weighted_flights = [[u, v, random.randint(1, 1000)] for u, v in flights]
    
    num_special_nodes = min(n, num_emb + 2)
    if num_special_nodes < 2:
        return None 
    special_nodes = random.sample(range(n), num_special_nodes)
    
    capital, destination = special_nodes[0], special_nodes[1]
    embassies = special_nodes[2:]
    
    if not embassies:
        k = 0
    else:
        k = random.randint(1, len(embassies))

    if case_id % 20 == 5 and len(embassies) > 1:
        k = len(embassies) + 1 

    if case_id % 7 == 1 and embassies and k > 0 and k <= len(embassies):
        perm_emb = random.sample(embassies, k)
        path = [capital] + perm_emb + [destination]
        for i in range(len(path) - 1):
            u, v = path[i], path[i+1]
            if not any(f[0]==u and f[1]==v for f in weighted_flights):
                 weighted_flights.append([u,v, random.randint(1,100)])

    if case_id % 25 == 0 and n > 50 and embassies:
        target_emb = random.choice(embassies)
        weighted_flights = [f for f in weighted_flights if f[1] != target_emb]

    return {
        "n": n,
        "flights": weighted_flights,
        "capital": capital,
        "destination": destination,
        "embassies": embassies,
        "k": k
    }


def main():
    """Main function to generate and save 550 test cases."""
    print("Generating 550 test cases for 'The Consul's Journey'...")
    all_test_cases = []
    solver = Solution()
    
    i = 0
    while len(all_test_cases) < 550:
        if (len(all_test_cases) + 1) % 50 == 0:
            print(f"  Generated {len(all_test_cases) + 1}/550 cases...")
            
        test_case_input = generate_test_case(i)
        i += 1
        if test_case_input is None:
            continue
        
        expected_output = solver.consulJourney(
            test_case_input["n"],
            test_case_input["flights"],
            test_case_input["capital"],
            test_case_input["destination"],
            test_case_input["embassies"],
            test_case_input["k"]
        )
        
        all_test_cases.append({
            "case_id": len(all_test_cases),
            "input": test_case_input,
            "output": expected_output
        })

    file_path = "consul_journey_test_cases.json"
    with open(file_path, "w") as f:
        json.dump(all_test_cases, f, indent=2)

    print(f"\nSuccessfully generated 550 test cases and saved to '{file_path}'")


if __name__ == "__main__":
    main()