## 815_Bus_Routes\[H\].py
## 592ms   %

'''
Total Accepted: 1.7K
Total Submissions: 5.4K
Developer: lrushx
Process Time: Apr 11, 2018
https://leetcode.com/problems/bus-routes/description/
'''

'''
We have a list of bus routes. Each routes[i] is a bus route that the i-th bus repeats forever. For example if routes[0] = [1, 5, 7], this means that the first bus (0-th indexed) travels in the sequence 1->5->7->1->5->7->1->... forever.

We start at bus stop S (initially not on a bus), and we want to go to bus stop T. Travelling by buses only, what is the least number of buses we must take to reach our destination? Return -1 if it is not possible.

Example:
Input: 
routes = [[1, 2, 7], [3, 6, 7]]
S = 1
T = 6
Output: 2
Explanation: 
The best strategy is take the first bus to the bus stop 7, then take the second bus to the bus stop 6.
Note:

1 <= routes.length <= 500.
1 <= routes[i].length <= 500.
0 <= routes[i][j] < 10 ^ 6.
'''

## 给一些bus路线，每个路线都是个list，包含该bus可以到stop，并且可以循环走。同个stop可以换乘。问从S到T最少需要坐几趟bus？
## 把原问题induce成以bus为节点的无向图，只要路线有公共stop的两趟bus，对应节点之间就有边，并且边长为1。
## 如此就是一个在以bus编号为节点的无向图中找从包含S的众节点到包含T的众节点的最短路径，BFS即可。
## 若induced graph的边长非1，则需要用Dijkstra


class Solution:
    def numBusesToDestination(self, routes, S, T):
        """
        :type routes: List[List[int]]
        :type S: int
        :type T: int
        :rtype: int
        """
        if S == T: return 0
        n = len(routes)
        edges = defaultdict(set)
        sets = [set(r) for r in routes]
        queue = [(i,1) for i,x in enumerate(sets) if S in x]
        target = [i for i,x in enumerate(sets) if T in x]

        if not target or not queue: return -1  # S or T not in any routes
        for i,x in enumerate(sets):
            for j in range(i+1,n):
                if x & sets[j]:
                    edges[i].add(j)
                    edges[j].add(i)
        # now we have a list of source, a list of target, and edges, it's a shortest path problem
        # and edge cost is 1, both BFS and Dijkstra available
        # of edge cost is non-negative, then only Dijkstra available

        i = 0
        visited = {x[0] for x in queue}
        while i < len(queue):
            u, step = queue[i]
            i += 1
            if u in target: return step
            for v in edges[u]:
                if not v in visited:
                    queue.append((v, step+1))
                    visited.add(v)
        return -1

