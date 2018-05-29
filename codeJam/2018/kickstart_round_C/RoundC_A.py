# https://codejam.withgoogle.com/codejam/contest/4384486/dashboard#s=p0

import sys
from collections import defaultdict
def dis(edges): # find exact one cycle in a graph, then find the minium dis from the cycle to any vertex
    edge = defaultdict(list)
    back = defaultdict(lambda: -1)
    for u,v in edges:
        edge[u].append(v)
        edge[v].append(u)
    visit = set()
    cycle = [False, None, None]
    def dfs(u):

        visit.add(u)
        for v in edge[u]:
            if cycle[0]: return
            if v in visit and v != back[u]:
                cycle[0], cycle[1], cycle[2] = True, u, v
                return
            elif v not in visit:
                back[v] = u
                dfs(v)

    for u in edge:
        if u not in visit:
            dfs(u)
        if cycle[0]: break
    v = cycle[1]

    queue = []
    res = [0] * (len(edges)+1)
    visit = set()
    while True:
        queue.append((v,0))
        visit.add(v)
        if v == cycle[2]:
            break
        v = back[v]


    #print([x for x,_ in queue])

    i = 0
    while i < len(queue):
        u,d = queue[i]
        i += 1
        for v in edge[u]:
            if v not in visit:
                res[v] = d+1
                queue.append((v,d+1))
                visit.add(v)
    return res[1:]

sys.setrecursionlimit(1500)

edges = [[1, 2],[2, 3],[3, 4],[2, 4],[5, 3]]
#edges = [[1,2],[3,2],[1,3]]
res = dis(edges)
#print(' '.join(map(str,res)))
t = int(input())  # read a line with a single integer
for ii in range(1, t + 1):
    n = int(input())
    edges = []
    for i in range(n):
        u,v = map(int,input().strip().split(" "))
        edges.append((u,v))
    res = dis(edges)
    print("Case #{}: {}".format(ii, ' '.join(map(str,res))))

    #a, b = map(int,s.split(" "))
    #s = [st for st in input().split(" ")]  # read a list of integers, 2 in this case
        

    # check out .format's specification for more formatting options

