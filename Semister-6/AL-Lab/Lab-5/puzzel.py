import heapq

goal_state = ((1,2,3),(4,5,6),(7,8,0))

def misplaced_tiles(state):
    count = 0
    for i in range(3):
        for j in range(3):
            if state[i][j] != 0 and state[i][j] != goal_state[i][j]:
                count += 1
    return count

def manhattan_distance(state):
    distance = 0
    for i in range(3):
        for j in range(3):
            val = state[i][j]
            if val != 0:
                goal_x = (val-1)//3
                goal_y = (val-1)%3
                distance += abs(i-goal_x) + abs(j-goal_y)
    return distance

def get_neighbors(state):
    neighbors = []
    x,y = [(i,j) for i in range(3) for j in range(3) if state[i][j]==0][0]
    moves = [(0,1),(1,0),(0,-1),(-1,0)]

    for dx,dy in moves:
        nx, ny = x+dx, y+dy
        if 0 <= nx < 3 and 0 <= ny < 3:
            new_state = [list(row) for row in state]
            new_state[x][y], new_state[nx][ny] = new_state[nx][ny], new_state[x][y]
            neighbors.append(tuple(tuple(row) for row in new_state))
    return neighbors

def a_star(start, heuristic):
    pq = []
    heapq.heappush(pq, (heuristic(start), 0, start))
    visited = set()
    nodes_expanded = 0

    while pq:
        f, g, state = heapq.heappop(pq)

        if state == goal_state:
            return g, nodes_expanded

        if state in visited:
            continue

        visited.add(state)
        nodes_expanded += 1

        for neighbor in get_neighbors(state):
            if neighbor not in visited:
                heapq.heappush(pq, (g+1+heuristic(neighbor), g+1, neighbor))

    return None

# Initial state
start_state = ((1,2,3),(4,0,6),(7,5,8))

depth_h1, nodes_h1 = a_star(start_state, misplaced_tiles)
depth_h2, nodes_h2 = a_star(start_state, manhattan_distance)

print("H1 - Misplaced Tiles:")
print("Solution Depth:", depth_h1)
print("Nodes Expanded:", nodes_h1)

print("\nH2 - Manhattan Distance:")
print("Solution Depth:", depth_h2)
print("Nodes Expanded:", nodes_h2)
