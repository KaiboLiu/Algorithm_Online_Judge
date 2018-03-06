'''
Instruction: HackerRank - The Longest Increasing Subsequence - [A]
Success Rate: 40.13%
Max Score: 60
Difficulty: Advanced
Submitted 13737 times
Developer: lrushx
Process Time: Mar 05, 2018
'''

#The task is to find the length of the longest subsequence in a given array of integers such that all elements of the subsequence are sorted in strictly ascending order. This is called the Longest Increasing Subsequence (LIS) problem.



#!/bin/python3

import sys

import bisect
def lis(s):     # pos is the index in s, idx is the index in f[i], f[i] is the the min ending value for a i-length Lis
    if len(s) < 2: return len(s)
    f, history = [], []
    for pos, ch in enumerate(s):
        idx = bisect.bisect_left(f,ch)
        if idx >= len(f): 
            f.append(ch)
            history.append([pos])
        elif f[idx] != ch: 
            f[idx] = ch
            history[idx].append(pos)

    res, idx = [], len(s)
    for l in history[::-1]:
        while l[-1] >= idx:
            l.pop()
        res.append(s[l[-1]])
        idx = l[-1]
    return len(res)


def longestIncreasingSubsequence(arr):
    return lis(arr)
    # Complete this function

    
    

if __name__ == "__main__":
    n = int(input().strip())
    arr = []
    arr_i = 0
    for arr_i in range(n):
       arr_t = int(input().strip())
       arr.append(arr_t)
    result = longestIncreasingSubsequence(arr)
    print(result)

