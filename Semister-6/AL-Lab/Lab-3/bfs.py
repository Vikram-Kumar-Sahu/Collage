from collections import deque

def bfs(maze, start, end):
    n, m = len(maze), len(maze[0])
    visited = [[False]*m for _ in range(n)]
    q = deque()

    q.append(start)
    visited[start[0]][start[1]] = True
    nodes = 1

    directions = [(1,0), (-1,0), (0,1), (0,-1)]

    while q:
        x, y = q.popleft()

        if (x, y) == end:
            return nodes

        for dx, dy in directions:
            nx, ny = x + dx, y + dy
            if (0 <= nx < n and 0 <= ny < m and
                maze[nx][ny] == 1 and not visited[nx][ny]):
                visited[nx][ny] = True
                q.append((nx, ny))
                nodes += 1

    return nodes
