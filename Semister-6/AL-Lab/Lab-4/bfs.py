from collections import deque


graph = {
    'A': [('B', 1), ('C', 4)],
    'B': [('D', 2), ('E', 5)],
    'C': [('E', 1)],
    'D': [],
    'E': []
}

def bfs(graph, start, goal):
    queue = deque([(start, [start])])
    visited = set()

    while queue:
        node, path = queue.popleft()

        if node == goal:
            return path

        visited.add(node)

        for neighbor, _ in graph[node]:
            if neighbor not in visited:
                queue.append((neighbor, path + [neighbor]))

    return None
print("BFS Path:", bfs(graph, 'A', 'E'))
