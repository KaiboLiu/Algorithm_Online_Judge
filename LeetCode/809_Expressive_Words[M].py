## 809_Expressive_Words[M].py 
## 60ms   %

'''
Total Accepted: 1.9K
Total Submissions: 5.5K
Developer: lrushx
Process Time: Apr 02, 2018
https://leetcode.com/problems/expressive-words/description/
'''

'''
给一个字符串S和一个字符串数组W，判断list中有多少个字符串可以通过若干自身字符<本地重复>到至少3个的方法变成S (a->aaa, aa->aaa, a->aaaa...)
'''

## 扫描字符串S，将单个字符和重复次数压入list中，然后用W中的字符串去比较。
## 剪枝：if set(w)-set(S) 则w不符合，不必再继续
## 注意S为空并且W中也有空字符串的情况
## 正则匹配找出不重复字符r'(.)\1*'，但是无法统计重复次数


class Solution:
    ## Solution1: regular, 60ms
    def expressiveWords(self, S, words):
        """
        :type S: str
        :type words: List[str]
        :rtype: int
        """
        l = len(S)
        res = 0
        
        if l == 0:
            for w in words: 
                if len(w) == 0: res += 1
            return res
        
        s = set(S)
        dic = {}
        n, count, prev = 0, 1, S[0]
        for i,x in enumerate(S[1:]+"A"):
            if x == prev: count += 1
            else: 
                dic[n] = (prev,count)
                prev, n, count = x, n+1, 1
                
        
        for w in words:
            if set(w)-s: continue
            idx, count, prev = 0, 1, w[0]
            valid = True
            for i,x in enumerate(w[1:]+"A"):
                if idx >= n or prev != dic[idx][0]: valid = False; break
                if x == prev: count += 1
                else: 
                    if count > dic[idx][1] or (count == 1 and dic[idx][1] == 2): valid = False; break
                    prev, idx, count = x, idx+1, 1
                    
            if valid and idx == n: res += 1
        return res


import re

    ## Solution2: regEx, 88ms
    def expressiveWords2(self, S, words):
        l = len(S)
        res = 0
        
        if l == 0:
            for w in words: 
                if len(w) == 0: res += 1
            return res
        pat = r'(.)\1*'
        S_re = re.findall(pat,S)
        count = [0] * len(S_re)
        i = j = 0
        for i0,ch in enumerate(S_re):
            while j < l and S[j] == ch:
                j += 1
            count[i0] = j-i
            i = j
        for w in words:
            l1 = len(w)
            if l1 > l: continue
            if  re.findall(pat,w) != S_re: continue
            i = j = 0; valid = True
            for i0,ch in enumerate(S_re):
                while j < l1 and w[j] == ch: j += 1
                if j-i > count[i0] or (j-i==1 and count[i0]==2): valid = False; break
                i = j
            if valid : res += 1
        return res
