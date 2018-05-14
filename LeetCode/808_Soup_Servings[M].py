## 808_Soup_Servings[M].py
## 48ms 86.99 %

'''
Total Accepted: 2K 
Total Submissions: 6.1K
Developer: lrushx
Process Time: May 11, 2018
https://leetcode.com/problems/soup-servings/description/
'''

## 有N,N单位的汤，分发给A和B,每次等概率方案为100/0, 75/25, 50/50和25/75，求A先分完的概率
## 虽然N可以很大，但是N>5000后答案就为1
## 可以用递归+memo，dfs(A,B,a={})表示各自剩下的量，如果其中一个为0，就按情况返回1/0.5/0，否则就返回a[A,B]，如果a[A,B]还没有，则把4中分法的答案加起来赋值后返回

class Solution:
    def soupServings(self, N):
        """
        :type N: int
        :rtype: float
        """
        
        def dfs(A, B, a = {}):
            if A == 0 and B != 0: return 1
            elif A != 0 and B == 0: return 0
            elif A == B == 0: return 0.5
            
            # If we reach here, it implies that neither A nor B is empty yet. 
            # If there exist previous calculated result, return it.
            if (A, B) in a: return a[A,B]
            
            # Otherwise, recursive for 4 possible selections
            f = dfs(A-min(A,100), B)+dfs(A-min(A,75), B-min(B,25))+dfs(A-min(A,50), B-min(B,50))+dfs(A-min(A,25), B-min(B,75))
            a[A,B] = f/4
            return a[A,B]
        if N >= 5000: return 1
        else: return dfs(N, N)
