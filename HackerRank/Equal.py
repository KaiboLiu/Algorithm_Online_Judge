#!/bin/python3
'''
Instruction: HackerRank - Equal - [M]
Success Rate: 46.74%
Max Score: 30
Difficulty: Medium
Submitted 16278 times
Developer: lrushx
Process Time: Mar 10, 2018
https://www.hackerrank.com/challenges/equal/problem
'''
# unfinished

# In this problem you will be given a list of coin denominations and a target amount. Determine the number of ways the target amount can be arrived at using the denominations available.
# number of solutions for knapsack_unbounded
 

import sys
from collections import defaultdict
def equal(arr):
    # Complete this function
    def dp(x):
        if x in opt: return opt[x]
        for a in num:
            if x >= a: opt[x] = min(opt[x], dp(x-a)+1)
        return opt[x]
    
    def bottom_up(x):
        for x in range(1,x+1):
            for a in num:
                if x >= a: opt[x] = min(opt[x], opt[x-a]+1)
                    
    n = len(arr)
    Min, Max = min(arr), max(arr)
    opt = defaultdict(lambda:1<<20)
    opt[0] = 0
    num = (1,3,5)
    bottom_up(Max-Min+5)
    #res = 0
    res = 1<<30
    for d in range(10):
        s = 0
        for x in arr: s += opt[x-Min+d]
        res = min(res,s)
    return res


if __name__ == "__main__":
    t = int(input().strip())
    for a0 in range(t):
        n = int(input().strip())
        arr = list(map(int, input().strip().split(' ')))
        result = equal(arr)
        print(result)

