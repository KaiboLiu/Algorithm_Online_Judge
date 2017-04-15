# -*- coding: utf-8 -*-

#LeetCode - 392_Is_Subsequence.py
#192ms  74.79%

'''
Instruction: LeetCode 392 - Is Subsequence - [M]
Developer: lrushx
Process Time: Apr 13, 2017
'''
 
'''
Total Accepted: 28263
Total Submissions: 63778
Given a string s and a string t, check if s is subsequence of t.
You may assume that there is only lower case English letters in both s and t. t is potentially a very long (length ~= 500,000) string, and s is a short string (<=100).
A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ace" is a subsequence of "abcde" while "aec" is not).

Example 1:
s = "abc", t = "ahbgdc"
Return true.

Example 2:
s = "axc", t = "ahbgdc"
Return false.

Follow up:
If there are lots of incoming S, say S1, S2, ... , Sk where k >= 1B, and you want to check one by one to see if T has its subsequence. In this scenario, how would you change your code?
'''

#判断s是否为t的子串，可以不连续
#2个位置向后判断，复杂度O(mn)，range改成xrange，时间从682ms到192ms



class Solution(object):
    def isSubsequence(s, t):
        l1,l2 = len(s),len(t)
        if l1>l2:
            return False
        pos = 0
        for i in xrange(l1):
            flag = False
            for j in xrange(pos,l2):
                if s[i] == t[j]:
                    flag = True
                    pos = j+1
                    break
            if not flag:
                return False
        return True

'''
s = "abc"
t = "ahbgdc"

s = "axc"
t = "ahbgdc"
'''
s = "acb"
t = "ahbgdc"
print(isSubsequence(s,t))



