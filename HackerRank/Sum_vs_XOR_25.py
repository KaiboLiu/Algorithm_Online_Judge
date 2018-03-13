#!/bin/python3
'''
Instruction: HackerRank - Sum vs XOR - [M]
Success Rate: 69.20%
Max Score: 25
Difficulty: Medium
Submitted 12695 times
Developer: lrushx
Process Time: Mar 10, 2018
https://www.hackerrank.com/challenges/sum-vs-xor/problem
'''

# Given an integer, n, find each x such that:
# 0 <= x <= n
# n+x == n^x


import sys

def solve(n):
    # Complete this function
    mul = {0:2,1:1}
    res = 1
    while n > 0:
        tail = n & 1
        res *= mul[tail]
        n >>= 1
    return res

n = int(input().strip())
result = solve(n)
print(result)

