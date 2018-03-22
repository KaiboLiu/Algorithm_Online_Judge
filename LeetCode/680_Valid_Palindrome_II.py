## 680_Valid_Palindrome_II.py
## 92ms   97.56%

'''
Total Accepted: 24.6K
Total Submissions: 76.1K
Instruction: LeetCode 680 - Valid Palindrome II [E]
Developer: lrushx
Process Time: Mar 21, 2018
'''

'''
Given a non-empty string s, you may delete at most one character. Judge whether you can make it a palindrome.

Example 1:
Input: "aba"
Output: True
Example 2:
Input: "abca"
Output: True
Explanation: You could delete the character 'c'.
Note:
The string will only contain lowercase characters a-z. The maximum length of the string is 50000.
'''

class Solution:
    def validPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        if s == s[::-1]: return True
        i,j = 0,len(s)-1
        dele = 1
        while i < j:
            if s[i] == s[j]:    i,j = i+1,j-1
            else:
                t1, t2 = s[i+1:j+1], s[i:j]
                return t1==t1[::-1] or t2==t2[::-1]
        return True
