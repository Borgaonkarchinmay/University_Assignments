class Queue:
    queue = []

    def enque(self, ele):
        self.queue.append(ele)
    
    def isEmpty(self):
        if len(self.queue) == 0:
            return True
        else:
            return False

    def dequeue(self):
        if self.isEmpty():
            return 0
        else:
            return self.queue.pop(0)

    def showQueue(self):
        print()
        for ele in self.queue:
            print(str(ele) + " ", end = '')


class graph:
    grp = []
    nodes = 0
    edges = 0
    visited = []
    
    def __init__(self, nodes, edges):
        graph.nodes = nodes
        self.edges = edges
        self.visited = [0]*(nodes + 1)

        for i in range(0, nodes):
            self.grp.append([0]*nodes)

    def showGraph(self):
        for row in self.grp:
            for item in row:
                print(str(item) + " ", end='')
            print()

    def initGraph(self):
        
        for i in range(0, self.edges):
            n1, n2 = input("Enter edge=> node1 and node2:",).split()
            self.grp[int(n1) - 1][int(n2) - 1] = 1
            self.grp[int(n2) - 1][int(n1) - 1] = 1

    def dfs(self, node):
        self.visited[node] = 1
        print(str(node + 1) + " ", end='')

        for i in range(0, self.nodes):
            if self.grp[node][i] == 1 and self.visited[i] == 0:
                self.dfs(i)

    def DFS(self, node):
        print()
        self.visited = [0]*(self.nodes + 1)
        self.dfs(node)
        print() 
    
    def bfs(self, queue):
        
        if not queue.isEmpty():
            i = queue.dequeue()
            print(str(i + 1) + " ", end = '')

            for j in range(0, self.nodes):
                if self.grp[i][j] == 1 and self.visited[j] == 0:
                    queue.enque(j)
                    self.visited[j] = 1
            
            self.bfs(queue)

    def BFS(self, node):
        q1 = Queue()
        q1.enque(node)
        self.visited[node] = 1
        print()
        self.bfs(q1)



ver = int(input("enter no of vertices: ",))
edges = int(input("enter no of edges: ",))
g1 = graph(ver, edges)
g1.initGraph()
g1.showGraph()
g1.BFS(0)
g1.DFS(0)
