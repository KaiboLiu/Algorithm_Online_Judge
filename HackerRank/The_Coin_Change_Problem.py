#!/bin/python3
'''
Instruction: HackerRank - The Coin Change Problem - [M]
Success Rate: 77.19%
Max Score: 60
Difficulty: Medium
Submitted 42876 times
Developer: lrushx
Process Time: Mar 06, 2018
https://www.hackerrank.com/challenges/coin-change/problem
'''

# In this problem you will be given a list of coin denominations and a target amount. Determine the number of ways the target amount can be arrived at using the denominations available.
# number of solutions for knapsack_unbounded
 


import sys
from collections import defaultdict
# number of solutions for knapsack_unbounded
# opt[x,i] = sum{ opt[x-k*c[i], i-1] }, k=0..x//c[i]
def getWays(X, c):
    # Complete this function
    def solution(x,i):
        
        if (x,i) in opt or i < 0: return opt[x,i]
        res, K = 0, x // c[i]
        for k in range(K+1):
            res += solution(x-k*c[i], i-1)
        opt[x,i] = res
        return res
    n = len(c)
    opt = defaultdict(int)
    for i in range(-1,n): opt[0,i] = 1
        
    return solution(X,n-1)
    
    
n, m = input().strip().split(' ')
n, m = [int(n), int(m)]
c = list(map(int, input().strip().split(' ')))
# Print the number of ways of making change for 'n' units using coins having the values given by 'c'
ways = getWays(n, c)
print(ways)

