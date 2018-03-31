## 788_Rotated_Digits.py
## 64ms   94.7%

'''
Total Accepted: 6.1K
Total Submissions: 12K
Instruction: LeetCode 788 - Rotated Digits [E]
Developer: lrushx
Process Time: Mar 31, 2018
'''

'''
X is a good number if after rotating each digit individually by 180 degrees, we get a valid number that is different from X.  Each digit must be rotated - we cannot choose to leave it alone.

A number is valid if each digit remains a digit after rotation. 0, 1, and 8 rotate to themselves; 2 and 5 rotate to each other; 6 and 9 rotate to each other, and the rest of the numbers do not rotate to any other number and become invalid.

Now given a positive number N, how many numbers X from 1 to N are good?

Example:
Input: 10
Output: 4
Explanation: 
There are four good numbers in the range [1, 10] : 2, 5, 6, 9.
Note that 1 and 10 are not good numbers, since they remain unchanged after rotating.
'''

class Solution:
# method1: construct, 64ms 94.7%
    def rotatedDigits(self, N):
        """
        :type N: int
        :rtype: int
        """
        def check(s):
            s1 = set(s)
            #return (not s1&invalid) and s1&change
            return set(s) & change
        
        def DFS(s,i,bound):
            if i == L:
                return 1 if check(s) else 0
            n = 0
            for ch in valid:
                if bound and ch > NS[i]: continue
                if bound and ch == NS[i]: n += DFS(s+ch,i+1, True)
                else: n += DFS(s+ch, i+1, False)
            return n
                    
        #f = [0,4,36,276,2004] #f[l] = 6*7**(l-1)-2*3**(l-1)
        #invalid = {'3','4','7'}
        change = {'2','5','6','9'}
        valid = {'0','1','2','5','6','8','9'}
        NS = str(N)
        L = len(NS)
        res = 0
                    
        for ch in valid:
            if ch < NS[0]: res += DFS(ch,1,False)
            elif ch == NS[0]: res += DFS(ch,1,True)
                
        return res


# method2: judge, 108ms 68.37%
    def rotatedDigits2(self, N):
        """
        :type N: int
        :rtype: int
        """
    
        def check(s):
            s1 = set(s)
            return (not s1&invalid) and s1&change
        invalid = {'3','4','7'}
        change = {'2','5','6','9'}
        
        res = 0
        for i in range(2,N+1):
            if check(str(i)): res += 1
        return res
        
        
        
