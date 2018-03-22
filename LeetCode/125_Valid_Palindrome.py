## 125_Valid_Palindrome.py
## 72ms   82.5%

'''
Total Accepted: 216.3KK
Total Submissions: 803K
Instruction: LeetCode 125 - Valid Palindrome [E]
Developer: lrushx
Process Time: Mar 22, 2018
'''

'''
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.
'''


class Solution:
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        t = ''
        for ch in s:
            if ch.isalnum(): t += ch.lower()
        return t==t[::-1]
