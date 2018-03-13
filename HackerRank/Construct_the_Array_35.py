#!/bin/python3
'''
Instruction: HackerRank - Construct the Array - [M]
Success Rate: 50.94%
Max Score: 35
Difficulty: Medium
Submitted 267 times
Developer: lrushx
Process Time: Mar 10, 2018
https://www.hackerrank.com/challenges/construct-the-array/problem
'''

# Your goal is to find the number of ways to construct an array such that consecutive positions contain different values.
# Specifically, we want to construct an array with  elements such that each element between 1 and k, inclusive. We also want the first and last elements of the array to be 1 and x.
# Given n, k and x, find the number of ways to construct such an array. Since the answer may be large, only find it modulo 10^9+7.


import sys
from collections import defaultdict

def countArray(n, k, x):
    # Return the number of ways to fill in the array.
    if n == 3: return k-1-(x!=1)
    f = defaultdict(int)        # f[i,0] means the # of ways 1~i, and a[i] is not x, while f[i,1] means a[i] is x
    if x == 1: f[1,1], f[1,0] = 0, k-1
    else:      f[1,1], f[1,0] = 1, k-2
    MOD = 1000000007
    for i in range(2,n-1):
        f[i,1] = f[i-1,0]
        f[i,0] = (f[i-1,0]*(k-2) + f[i-1,1]*(k-1)) % MOD
    return f[n-2,0]
    
if __name__ == "__main__":
    n, k, x = input().strip().split(' ')
    n, k, x = [int(n), int(k), int(x)]
    answer = countArray(n, k, x)
    print(answer)

