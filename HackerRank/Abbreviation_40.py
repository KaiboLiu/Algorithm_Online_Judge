#!/bin/python3
'''
Instruction: HackerRank - Abbreviation - [M]
Success Rate: 35.86%
Max Score: 40
Difficulty: Medium
Submitted 7424 times
Developer: lrushx
Process Time: Mar 10, 2018
https://www.hackerrank.com/challenges/abbr/problem
'''

# You can perform the following operation on some string, a:
# 
# Capitalize zero or more of a's lowercase letters at some index i (i.e., make them uppercase).
# Delete all of the remaining lowercase letters in a.
# Given q queries in the form of two strings, a and b, determine if it's possible to make a equal to b by performing the above operation on a. If a can be transformed into b, print YES on a new line; otherwise, print NO.
# 
# Input Format
# The first line contains a single integer, q, denoting the number of queries. The 2q subsequent lines describe each query in the following format:
# The first line of each query contains a single string, a.
# The second line of each query contains a single string, b.

import sys
from collections import defaultdict

def abbreviation(a, b):
    # Complete this function
    res = defaultdict(lambda: False)

    l1, l2 = len(a), len(b)
    if l1 < l2: return "NO"
    for i in range(-1,l1): res[i,-1] = True
    for j in range(l2):
        for i in range(l1):
            res[i,j] = (res[i-1,j-1] and a[i].upper() == b[j]) or (res[i-1,j] and a[i].islower())
    return "YES" if res[l1-1,l2-1] else "NO"


if __name__ == "__main__":
    q = int(input().strip())
    for a0 in range(q):
        a = input().strip()
        b = input().strip()
        result = abbreviation(a, b)
        print(result)

