from collections import defaultdict, deque

class Graph:
    def __init__(self):
        self.graph = defaultdict(list)

    def add_edge(self, u, v):
        self.graph[u].append(v)

    # Breadth First Search
    def bfs(self, start):
        visited = set()
        queue = deque([start])
        result = []

        while queue:
            node = queue.popleft()
            if node not in visited:
                visited.add(node)
                result.append(node)
                queue.extend(self.graph[node])

        return result

    # Depth First Search
    def dfs(self, start):
        visited = set()
        result = []

        def dfs_util(v):
            visited.add(v)
            result.append(v)
            for neighbour in self.graph[v]:
                if neighbour not in visited:
                    dfs_util(neighbour)

        dfs_util(start)
        return result


# Driver code with match-case
if __name__ == "__main__":
    g = Graph()

    # Taking input differently
    edges = [(0, 1), (0, 2), (1, 2),
             (2, 0), (2, 3), (3, 3)]
    for u, v in edges:
        g.add_edge(u, v)

    start_vertex = 2
    choice = input("Choose traversal (bfs/dfs): ").strip().lower()

    match choice:
        case "bfs":
            print("BFS Traversal:", g.bfs(start_vertex))
        case "dfs":
            print("DFS Traversal:", g.dfs(start_vertex))
        case _:
            print("Invalid choice! Please select bfs or dfs.")
