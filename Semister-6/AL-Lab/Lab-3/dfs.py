dfs_nodes = 0

def dfs(x, y, maze, visited, end):
    global dfs_nodes
    n, m = len(maze), len(maze[0])

    # destination reached
    if (x, y) == end:
        return True

    visited[x][y] = True
    dfs_nodes += 1

    directions = [(1,0), (-1,0), (0,1), (0,-1)]

    for dx, dy in directions:
        nx, ny = x + dx, y + dy
        if (0 <= nx < n and 0 <= ny < m and
            maze[nx][ny] == 1 and not visited[nx][ny]):
            if dfs(nx, ny, maze, visited, end):
                return True

    return False
