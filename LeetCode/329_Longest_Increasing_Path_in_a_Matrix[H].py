## 329_Longest_Increasing_Path_in_a_Matrix\[H\].py
## 296ms  83.93%

'''
Total Accepted: 51.8K
Total Submissions: 138.3K
Developer: lrushx
Process Time: Apr 15, 2018
https://leetcode.com/problems/longest-increasing-path-in-a-matrix/description/
'''

'''
Given an integer matrix, find the length of the longest increasing path.

From each cell, you can either move to four directions: left, right, up or down. You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).

Example 1:

nums = [
  [9,9,4],
  [6,6,8],
  [2,1,1]
]
Return 4
The longest increasing path is [1, 2, 6, 9].
'''

## 给一个矩阵，找到上下左右移动递增序列的最大长度
## 我的方法是建立从小到大的边，给出节点idx后构成一个DAG，然后用topol执行viterbi算法 524ms/27.98%
## 参考方法是dfs+memorize，不用考虑topol结构，直接做竟然更快
## dfs+memorize的速度令人印象深刻，还不用考虑起点


class Solution:
    # solution1: topological sort+viterbi
    def longestIncreasingPath1(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: int
        """
        def connect(i1,j1,i2,j2):
            if i2 == h or j2 == w: return
            idx1, idx2 = i1*w+j1, i2*w+j2
            if matrix[i1][j1] < matrix[i2][j2]:
                edge[idx1].add(idx2)    # idx1-->idx2
                indegree[idx2] += 1
            elif matrix[i1][j1] > matrix[i2][j2]:
                edge[idx2].add(idx1)    # idx2-->idx1
                indegree[idx1] += 1
        
        def topol_order():  # no cycle guaranteed
            topol = []
            visit = set()
            for u in edge:
                if indegree[u] == 0:
                    topol.append(u)
                    visit.add(u)
            i = 0
            while i < len(topol):
                u = topol[i]
                i += 1
                for v in edge[u]:
                    if v not in visit:
                        indegree[v] -= 1
                        if indegree[v] == 0:
                            topol.append(v)
                            visit.add(v)
            return topol
        
        if len(matrix) == 0 or len(matrix[0]) == 0: return 0
        h,w = len(matrix), len(matrix[0])
        edge = collections.defaultdict(set)
        indegree = collections.defaultdict(int)
        for i in range(h):
            for j in range(w):
                connect(i,j,i+1,j)  # vertical edge
                connect(i,j,i,j+1)  # horizontal edge
                
        # topological sort        
        topol = topol_order()
        
        # viterbi with topological order
        opt = collections.defaultdict(lambda : 1)
        res = 1
        for u in topol:
            for v in edge[u]:
                opt[v] = max(opt[v], opt[u]+1)
                res = max(res, opt[v])    
        return res
    
    # solution2: dfs+memorization, better
    def longestIncreasingPath(self, matrix):
        def dfs(i, j):
            if not dp[i,j]:
                val = matrix[i][j]
                dp[i,j] = 1 + max( 
                        dfs(i,j-1) if j and matrix[i][j-1] < val else 0,
                        dfs(i,j+1) if j<w-1 and matrix[i][j+1] < val else 0,
                        dfs(i-1,j) if i and matrix[i-1][j] < val else 0,
                        dfs(i+1,j) if i<h-1 and matrix[i+1][j] < val else 0
                        )
            return dp[i,j]
            
        if not matrix or not matrix[0]: return 0
        h,w = len(matrix), len(matrix[0])
        dp = collections.defaultdict(int)
        return max(dfs(i,j) for i in range(h) for j in range(w))
