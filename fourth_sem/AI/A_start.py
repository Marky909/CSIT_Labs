# A* Search Algorithm (concise version)

adj_list = {
    's': [('a', 1), ('g', 10)],
    'a': [('b', 2), ('c', 1)],
    'b': [('d', 5)],
    'c': [('d', 3), ('g', 4)],
    'd': [('g', 2)],
    'g': []
}

heuristic = {'s': 5, 'a': 3, 'b': 4, 'c': 2, 'd': 6, 'g': 0}

def astar(adj_list, heuristic, start, goal):
    open_list, closed_list = {start}, set()
    g, parents = {start: 0}, {start: start}

    while open_list:
        n = min(open_list, key=lambda x: g[x] + heuristic[x])

        if n == goal:
            path = []
            while n != parents[n]:
                path.append(n)
                n = parents[n]
            path.append(start)
            path.reverse()
            print(f'Path found: {path}')
            return path

        open_list.remove(n)
        closed_list.add(n)

        for m, w in adj_list[n]:
            if m in closed_list: continue
            cost = g[n] + w
            if m not in open_list or cost < g.get(m, float('inf')):
                g[m] = cost
                parents[m] = n
                open_list.add(m)

    print('Path does not exist!')
    return None

# Run
print("----- A* Search -----")
start_node = input("Enter start node: ")
goal_node = input("Enter goal node: ")
astar(adj_list, heuristic, start_node, goal_node)
