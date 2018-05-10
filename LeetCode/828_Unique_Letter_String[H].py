## 828_Unique_Letter_String\[H\].py
## 72ms  %

'''
Total Accepted: 1.2K 
Total Submissions: 3.9K
Developer: lrushx
Process Time: May 10, 2018
https://leetcode.com/problems/unique-letter-string/description/
'''

'''
A character is unique in string S if it occurs exactly once in it.
For example, in string S = "LETTER", the only unique characters are "L" and "R".
Let's define UNIQ(S) as the number of unique characters in string S.
For example, UNIQ("LETTER") =  2.
Given a string S with only uppercases, calculate the sum of UNIQ(substring) over all non-empty substrings of S.
If there are two or more equal substrings at different positions in S, we consider them different.
Since the answer can be very large, retrun the answer modulo 10 ^ 9 + 7.

Example 1:
Input: "ABC"
Output: 10
Explanation: All possible substrings are: "A","B","C","AB","BC" and "ABC".
Evey substring is composed with only unique letters.
Sum of lengths of all substring is 1 + 1 + 1 + 2 + 2 + 3 = 10
'''

## 给一个由大写字母组成的字符串，求每个连续子串中只出现1次的字符总数
## 
## 不能在每个子串中找只出现1次的字符，而是反过来看，要看每个字符会在多少个子串中有贡献(成为唯一)
## **A**A***A*为例，第二个A只在第一、第三个A之间的子串中才有贡献，因为在第二个A左边插‘(’，右边插‘)’，贡献值/方案数为3*4
## 所以用一个数组记下每个字母最近出现的位置，和再前一次出现的位置occr[0..25][2]。
## 扫一遍字符串，位置i字符c，前2次位置occr[c][1]和occr[c][0]，答案+=(i-occr[c][0])*(occr[c][0]-occr[c][1])，然后更新occr[c]为(i,occr[c][0])。
## 再以末尾为i，再计算一遍所有字符c的贡献+=(len(s)-occr[c][0])*(occr[c][0]-occr[c][1])



class Solution:
# solution1, 624ms
    def uniqueLetterString1(self, S):
        occr = [(-1,-1) for _ in range(26)] # occr[i][0]: most recent pos of letter i; occr[i][1]: last pos of letter i
        MOD, res = 1000000007, 0
        for i, c in enumerate(S):
            idx = ord(c)-65
            occr[idx] = (i, occr[idx][0])
            for j in range(26):
                res = (res + (occr[j][0]-occr[j][1])) % MOD
        return res
    
    
# solution1, 72ms
    def uniqueLetterString(self, S):
        occr = [(-1,-1) for _ in range(26)] # occr[i][0]: most recent pos of letter i; occr[i][1]: second last pos of letter i
        MOD, res = 1000000007, 0
        l = len(S)
        for i, c in enumerate(S):
            idx = ord(c)-65
            j, k = occr[idx]
            res += (i-j)*(j-k)
            occr[idx] = (i, j)
        for idx in range(26):
            j, k = occr[idx]
            res += (l-j)*(j-k)
        return res % MOD
