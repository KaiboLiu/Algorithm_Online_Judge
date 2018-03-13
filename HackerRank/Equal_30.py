#!/bin/python3
'''
Instruction: HackerRank - Equal - [M]
Success Rate: 46.74%
Max Score: 30
Difficulty: Medium
Submitted 16278 times
Developer: lrushx
Process Time: Mar 12, 2018
https://www.hackerrank.com/challenges/equal/problem
'''

# given array of n numbers, each round, add 1,2, or 5 to all but one element, and the n-1 elements get the same added number(1/2/5).
# what's the minimum round of operation to make all the n numbers same.



# add x to n-1 numbers is equivalent to deduct x from the rest element.
# so I just need to decide the target of deduction, and make all the elements deducted to the target and calculate the rounds for each element.
# 1,2 can make 1..4 with rounds of 1,1,2,2, and number x can be made of from 1,2,5 with f[x%5]+x//5 rounds.

import sys

def equal(arr):
    # Complete this function
    #f = {0:0,1:1,2:2,3:1,4:2}  # put 1,3,5
    f = {0:0,1:1,2:1,3:2,4:2}   # put 1,2,5
    def single(x):
        return f[x%5] + x//5
                    
    n = len(arr)
    Min, Max = min(arr), max(arr)
    num = (1,3,5)
    res = 1<<30
    for d in range(5):
        s = 0
        for x in arr: s += single(x-Min+d)
        
        res = min(res,s)
    return res


if __name__ == "__main__":
    t = int(input().strip())
    for a0 in range(t):
        n = int(input().strip())
        arr = list(map(int, input().strip().split(' ')))
        result = equal(arr)
        print(result)

