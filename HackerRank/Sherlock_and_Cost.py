#!/bin/python3
'''
Instruction: HackerRank - Sherlock and Cost - [M]
Success Rate: 61.26%
Max Score: 50
Difficulty: Medium
Submitted 13384 times
Developer: lrushx
Process Time: Mar 10, 2018
https://www.hackerrank.com/challenges/sherlock-and-cost/problem
'''

# Array A contains the elements, A1,A2...AN. And array B contains the elements, B1,B2...BN. There is a relationship between Ai and Bi, ∀ 1 ≤ i ≤ N, i.e., 
# any element Ai lies between 1 and Bi.

# Let the cost S of an array A be defined as: s = sum_(i=2~N)|Ai - A(i-1)| 
# You have to print the largest possible value of S.

import sys

def cost(arr):
    # Complete this function
    f = {(0,0):0, (0,1):0}
    n = len(arr)
    for i in range(1,n):
#        f[i,0] = max(f[i-1,1]+abs(1-arr[i-1]), f[i-1,0])
#        f[i,1] = max(f[i-1,1]+abs(arr[i]-arr[i-1]), f[i-1,0]+abs(arr[i]-1))
        a, b = f[i-1,1]+abs(1-arr[i-1]), f[i-1,0]
        f[i,0] = max(a,b)
        a, b = f[i-1,1]+abs(arr[i]-arr[i-1]), f[i-1,0]+abs(arr[i]-1)
        f[i,1] = max(a,b)
    return max(f[n-1,0], f[n-1,1])
        
if __name__ == "__main__":
    t = int(input().strip())
    for a0 in range(t):
        n = int(input().strip())
        arr = list(map(int, input().strip().split(' ')))
        result = cost(arr)
        print(result)

