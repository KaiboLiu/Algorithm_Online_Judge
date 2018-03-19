## 796_Rotate_String.py
## 36ms   95.95%

'''
Total Accepted: 7.4K
Total Submissions: 11.4K
Instruction: LeetCode 796 - Rotate String [M]
Developer: lrushx
Process Time: Mar 18, 2018
'''

'''
We are given two strings, A and B.

A shift on A consists of taking string A and moving the leftmost character to the rightmost position. For example, if A = 'abcde', then it will be 'bcdea' after one shift on A. Return True if and only if A can become B after some number of shifts on A.

Example 1:
Input: A = 'abcde', B = 'cdeab'
Output: true

Example 2:
Input: A = 'abcde', B = 'abced'
Output: false
'''



class Solution:
    def rotateString(self, A, B):

        if len(A) != len(B): return False
        if A == B: return True
        a = A[1:]+A[0]
        for _ in range(len(A)-1):
            if a == B: return True
            a = a[1:]+a[0]
        return False


class Solution:
    def check(self, A, B, i, l):
        for j in range(1,l-i):
            if A[i+j] != B[j]: return False
        for j in range(1,i):
            if A[j] != B[l-i+j]: return False
        return True
    
    def rotateString(self, A, B):
        """
        :type A: str
        :type B: str
        :rtype: bool
        """
        
        if len(A) != len(B): return False
        l = len(A)
        if self.check(A,B,0,l): return True
        for i in range(1,l):
            if A[i] == B[0] and A[0] == B[l-i]:
                if self.check(A,B,i,l): return True
        return False
        
