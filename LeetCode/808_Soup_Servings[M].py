## 808_Soup_Servings[M].py
## 48ms 86.99 %

'''
Total Accepted: 2K 
Total Submissions: 6.1K
Developer: lrushx
Process Time: May 11, 2018
https://leetcode.com/problems/soup-servings/description/
'''



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
