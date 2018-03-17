#!/bin/python3
'''
Instruction: HackerRank - The Maximum Subarray - [M]
Success Rate: 74.65%
Max Score: 50
Difficulty: Medium
Submitted 52320 times
Developer: lrushx
Process Time: Mar 16, 2018
https://www.hackerrank.com/challenges/maxsubarray/problem
'''
# We define subsequence as any subset of an array. We define a subarray as a contiguous subsequence in an array.
# Given an array, find the maximum possible sum among:
# all nonempty subarrays.
# all nonempty subsequences.

import sys

def maxSubarray(arr):
    # Complete this function
    arr.append(-(1<<30))
    res_subarr, res_subseq = arr[0], 0
    s= {-1:0}
    low = high = -1
    Max = arr[0]
    for i,x in enumerate(arr):
        if x > 0: res_subseq += x
        if x > Max: Max = x
        s[i] = s[i-1] + x
        if x >= 0: 
            high = i
        else: 
            res_subarr = max(res_subarr, s[high]-s[low]) if high != low else max(res_subarr, x)
            low, high = low if s[low]<s[i] else i, i
    if res_subseq == 0: res_subseq = Max
    return res_subarr, res_subseq
    
if __name__ == "__main__":
    t = int(input().strip())
    for a0 in range(t):
        n = int(input().strip())
        arr = list(map(int, input().strip().split(' ')))
        result = maxSubarray(arr)
        print (" ".join(map(str, result)))



