## 827_Making_A_Large_Island[H].py
## 116ms  %

'''
Total Accepted: 598
Total Submissions: 1.5K
Developer: lrushx
Process Time: Apr 28, 2018
https://leetcode.com/problems/making-a-large-island/description/
'''

'''
In a 2D grid of 0s and 1s, we change at most one 0 to a 1.

After, what is the size of the largest island? (An island is a 4-directionally connected group of 1s).

Example 1:

Input: [[1, 0], [0, 1]]
Output: 3
Explanation: Change one 0 to 1 and connect two 1s, then we get an island with area = 3.
Example 2:

Input: [[1, 1], [1, 0]]
Output: 4
Explanation: Change the 0 to 1 and make the island bigger, only one island with area = 1.
Example 3:

Input: [[1, 1], [1, 1]]
Output: 4
Explanation: Can't change any 0 to 1, only one island with area = 1.
'''

## 给一个0/1矩阵，4方向连续的1可以构成岛，求把1个0改成1可以构成最大岛的面积
## 遍历一遍矩阵，遇到1就用dfs染色来标记岛的编号并计算各个岛的面积，
## 在这里我用了defalut字典Area[i,j] = [area,idx]来表示某格的信息，
## 染色时直接赋值这个list再更新第0项，这样同属一个岛的点的信息会同时改变，避免再遍历一次
## 接着再遍历一遍0，面积记为1，往4个方向扩展，若扩展到岛并且岛编号不在set中则加上这个岛面积，并把编号加到set中，记下最大的面积即可


class Solution:
    def largestIsland(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        def dfs(i,j):
            area[i,j][0] += 1
            for di, dj in go:
                i1, j1 = i+di, j+dj
                if 0 <= i1 < h and 0 <= j1 < w and grid[i1][j1] and area[i1,j1][0] == 0:
                    area[i1,j1] = area[i,j]
                    dfs(i1,j1)
        if not grid or not grid[0]: return 0
        h, w = len(grid), len(grid[0])

        SUM = sum((sum(x) for x in grid))
        if h*w == SUM: return SUM
        
        res = 0
        go = [(0,-1),(0,1),(-1,0),(1,0)]
        area = collections.defaultdict(lambda: [0, 0])  # area, idx
        idx = 0
        for i, line in enumerate(grid):
            for j, c in enumerate(line):
                if c == 1 and area[i,j][0] == 0:
                    area[i,j][1] = idx
                    idx += 1
                    dfs(i,j)
                    #res = max(res, area[i,j][0])
        #res += 1    # one island+1
        for i, line in enumerate(grid):
            for j, c in enumerate(line):
                if c == 0:
                    newarea = 1
                    s = set()
                    for di, dj in go:
                        i1, j1 = i+di, j+dj
                        if 0 <= i1 < h and 0 <= j1 < w and grid[i1][j1] and area[i1,j1][1] not in s:
                            newarea += area[i1,j1][0]
                            s.add(area[i1,j1][1])
                    res = max(res, newarea)
        return res
        
