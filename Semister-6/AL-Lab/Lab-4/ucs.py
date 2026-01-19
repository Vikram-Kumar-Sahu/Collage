import heapq


graph = {
    'A': [('B', 1), ('C', 4)],
    'B': [('D', 2), ('E', 5)],
    'C': [('E', 1)],
    'D': [],
    'E': []
}

def uniform_cost_search(graph, start, goal):
    priority_queue = [(0, start, [])]  # (cost, node, path)
    visited = set()

    while priority_queue:
        cost, node, path = heapq.heappop(priority_queue)

        if node in visited:
            continue

        path = path + [node]
        visited.add(node)

        if node == goal:
            return path, cost

        for neighbor, edge_cost in graph[node]:
            if neighbor not in visited:
                heapq.heappush(
                    priority_queue,
                    (cost + edge_cost, neighbor, path)
                )

    return None, float('inf')

path, cost = uniform_cost_search(graph, 'A', 'E')
print("Optimal Path:", path)
print("Total Cost:", cost)
