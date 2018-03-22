## 784_Letter_Case_Permutation.py
## 80ms  61.42% 

'''
Total Accepted: 6.7K
Total Submissions: 12.9K
Instruction: LeetCode 784 - Letter Case Permutation [E]
Developer: lrushx
Process Time: Mar 21, 2018
'''

'''
Given a string S, we can transform every letter individually to be lowercase or uppercase to create another string.  Return a list of all possible strings we could create.

Examples:
Input: S = "a1b2"
Output: ["a1b2", "a1B2", "A1b2", "A1B2"]

Input: S = "3z4"
Output: ["3z4", "3Z4"]

Input: S = "12345"
Output: ["12345"]
'''

class Solution:
    def letterCasePermutation(self, S):
        """
        :type S: str
        :rtype: List[str]
        """
        
        res = ['']
        for ch in S:
            if ch.isalpha():
                res = [a+b for a in res for b in [ch.lower(),ch.upper()]]
            else:
                res = [a+ch for a in res]
        return res
