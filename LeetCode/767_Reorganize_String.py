## 767_Reorganize_String.py
## 44ms   94.12%

'''
Total Accepted: 4.4K
Total Submissions: 12.4K
Instruction: LeetCode 767 - Reorganize String [M]
Developer: lrushx
Process Time: Mar 21, 2018
'''

'''
Given a string S, check if the letters can be rearranged so that two characters that are adjacent to each other are not the same.

If possible, output any possible result.  If not possible, return the empty string.

Example 1:

Input: S = "aab"
Output: "aba"
Example 2:

Input: S = "aaab"
Output: ""
'''


class Solution:
    def reorganizeString(self, S):
        """
        :type S: str
        :rtype: str
        """
        l = len(S)
        major = 'a'
        n = {'a':0}
        for ch in S:
            if ch not in n: n[ch] = 1
            else: n[ch] += 1
            if n[ch] > n[major]: major = ch
        if 2*n[major] > l+1: return ""
        n0 = n[major]
        res = ""
        a = [major for _ in range(n0)]
        i = 0
        for ch in sorted(S):
            if ch != major:
                a[i % n0] += ch
                i = (i+1) % n0
        print(a)
        return "".join(a)
            
