# -*- coding:utf-8 -*-
'''
Challenge: StrToInt.py
Total Acceptence: 24.89%
Developer: lrushx
Process Time: Apr 09, 2018
https://www.nowcoder.com/practice/1277c681251b4372bdef344468e4f26e?tpId=13&tqId=11202&tPage=3&rp=3&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking
'''

class Solution:
    def StrToInt(self, s):
        if s == '': return 0
        l = len(s)
        sign = 1
        res, p = 0, 0
        if s[0] == '-' or s[0] == '+':
            if s[0] == '-': sign = -1 
            p += 1
        for i in range(p,l):
            num = ord(s[i])-48
            if 0<=num<=9:
                res = res*10+num
            else: return 0
        return sign*res

ss = "123"
s = Solution()
print(s.StrToInt(ss))

