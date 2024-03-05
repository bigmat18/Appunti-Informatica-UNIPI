class Node():
    def __init__(self, state, father, action, cost):
        self.state = state
        self.father = father
        self.action = action
        self.cost = cost + father.cost

def BFS(problem):
    explored = [] # Insieme degli stati già visitati lista FIFO

    node = problem.initial_node
    if problem.goal_test(node.state):
        return node

    frontier = []
    frontier.append(node)
    while len(frontier) == 0:
        node = frontier.pop(0)
        explored.append(node)

        for child_node in problem.child_node(node):
            if child_node.state not in explored and child_node.state not in frontier:
                if problem.goal_test(child_node.state):
                    return child_node
                frontier.insert(child_node)
    return None