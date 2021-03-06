## 647_Palindromic_Substrings.py
## 120ms  88.14%

'''
Total Accepted: 39.3K
Total Submissions: 71.9K
Developer: lrushx
Process Time: Apr 27, 2018
https://leetcode.com/problems/palindromic-substrings/description/
'''

'''
Given a string, your task is to count how many palindromic substrings in this string.

The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.

Example 1:
Input: "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
Example 2:
Input: "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
'''

## 给一个字符串，输出所有回文子串的个数(包含单个)
## 数据量不大，最长1000，只要扫回文中间点，往左右扩，每扩一步结果+1即可，长度为1的直接把n加到结果中。
## 注意中间点也可能不是元素而是两个元素中间。

class Solution:
    def countSubstrings(self, s):
        """
        :type s: str
        :rtype: int
        """
        n = len(s)
        res = n
        for i,c in enumerate(s):
            l, r = i-1, i+1     # i as pivot
            while l>=0 and r < n and s[l] == s[r]:
                res += 1
                l -= 1
                r += 1
            l, r = i, i+1  # gap of i,i+1 as pivot
            while l>=0 and r < n and s[l] == s[r]:
                res += 1
                l -= 1
                r += 1
        return res
        
        
