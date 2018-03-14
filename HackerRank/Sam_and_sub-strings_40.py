#!/bin/python3
'''
Instruction: HackerRank - Sam and sub-strings - [M]
Success Rate: 56.83%
Max Score: 40
Difficulty: Medium
Submitted 10527 times
Developer: lrushx
Process Time: Mar 14, 2018
https://www.hackerrank.com/challenges/sam-and-substrings/problem
'''

# given a string S containing a number in format of string, whose length can be 10^5. Return the sum of all its substring, mod 10^9+7.
# The sub-strings of 123 are 1, 2, 3, 12, 23, 123 which sums to 164. 


# I cannot use i,j to extract the subsring s[i..j], which would result in TLE
# My approach is O(n)
# think about the exmple 567, I set a column sum, c=0
# for s[0]=5, c=c*10+s[0]*1=5, is the sum of all the substrings ending with s[0](5)
# for s[1]=6, c=c*10+s[1]*2=62, is the sum of all the substrings ending with s[1](6)
# for s[2]=7, c=c*10+s[2]*3=641, is the sum of all the substrings ending with s[2](7)
# sum all the c, is the final result: 708(5+6+7+56+67+567)
# 5
# 56,6
# 567,67,7

import sys

def substrings(balls):
    # Complete this function
    n = len(balls)
    res, MOD = 0, 10**9+7
    column = 0
    for i in range(n):
        column = (column * 10 + int(balls[i])*(i+1)) % MOD
        res = (res + column) % MOD
    return res
if __name__ == "__main__":
    balls = input().strip()
    result = substrings(balls)
    print(result)

