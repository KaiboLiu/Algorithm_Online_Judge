## 834_Sum_of_Distances_in_Tree\[H\].py
## 236ms  %

'''
Total Accepted: 639
Total Submissions: 2.3K
Developer: lrushx
Process Time: May 13, 2018
https://leetcode.com/problems/sum-of-distances-in-tree/description/
'''


'''
An undirected, connected tree with N nodes labelled 0...N-1 and N-1 edges are given.

The ith edge connects nodes edges[i][0] and edges[i][1] together.

Return a list ans, where ans[i] is the sum of the distances between node i and all other nodes.

Example 1:

Input: N = 6, edges = [[0,1],[0,2],[2,3],[2,4],[2,5]]
Output: [8,12,6,10,10,10]
Explanation: 
Here is a diagram of the given tree:
  0
 / \
1   2
   /|\
  3 4 5
We can see that dist(0,1) + dist(0,2) + dist(0,3) + dist(0,4) + dist(0,5)
equals 1 + 1 + 2 + 2 + 2 = 8.  Hence, answer[0] = 8, and so on.
Note: 1 <= N <= 10000
'''


## 给一个树形无环图，求每个点到其他所有点的距离和
## 可以把每个点当多叉树的root，遍历一遍求子树的size，sum[node]+=1+sum[child]+count[child]，第一个1表示child到node的距离，后2项目表示child的所有子孙通过child到node的距离和，要经过count[child]次
## 但是没必要循环n次把每个点都当root，为了避免重复，第一次post-oder遍历求出count，顺便求每个node到所有子节点的距离和
## 再来一次pre-order，把node的父节点的其余子节点的信息都加到node上


class Solution:
    def sumOfDistancesInTree(self, N, edges):
        """
        :type N: int
        :type edges: List[List[int]]
        :rtype: List[int]
        """
        def _count(root, visited = set()): # post-order traverse

            visited.add(root)
            for node in edge[root]:
                if node in visited: continue
                count[root] += 1+_count(node)
                res[root] += 1+count[node]+res[node]
            return count[root]
    
        def _sum(root, visited = set()):  # pre-order traverse

            visited.add(root)
            for node in edge[root]:
                if node in visited: continue
                res[node] = res[root]+N-1-(count[node]<<1)-1
                #count[node] = count[root] 
                _sum(node)
                
        res = [0] * N
        count = [0] * N
        edge = collections.defaultdict(set)
        for a, b in edges:
            edge[a].add(b)
            edge[b].add(a)
        
        _count(0)
        _sum(0)
        return res
                    
