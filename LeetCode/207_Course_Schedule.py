## 207_Course_Schedule.py
## 56ms   87.93%

'''
Total Accepted: 119.2K
Total Submissions: 354.2K
Instruction: LeetCode 207 - Course Schedule [M]
Developer: lrushx
Process Time: Mar 31, 2018
'''

'''
There are a total of n courses you have to take, labeled from 0 to n - 1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

For example:

2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0. So it is possible.

2, [[1,0],[0,1]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
'''

## topological sort, to check if it is acyclic



from collections import defaultdict

class Solution:
    def canFinish(self, numCourses, prerequisites):
        """
        :type numCourses: int
        :type prerequisites: List[List[int]]
        :rtype: bool
        """
        # topological sort
        edge = defaultdict(set)
        degree = [0] * numCourses
        for (u,v) in prerequisites:
            degree[u] += 1
            edge[v].add(u)
        queue = []
        for u in range(numCourses):
            if degree[u] == 0:
                queue.append(u)
                
        i = 0
        used = set()
        while i < len(queue):
            u = queue[i]
            i += 1
            used.add(u)
            for v in edge[u]:
                if v not in used:
                    degree[v] -= 1
                    if degree[v] == 0: queue.append(v)
                        
        return False if len(queue) < numCourses else True
