#!/bin/python3
'''
Instruction: HackerRank - The Full Counting Sort - [M]
Success Rate: 83.41%
Max Score: 40
Difficulty: Medium 
Submitted 20512 times
Developer: lrushx
Process Time: Mar 29, 2018
https://www.hackerrank.com/challenges/countingsort4/problem
'''


import sys
from collections import defaultdict
def countingsort(arr):
    dic = defaultdict(list)
    half = (len(arr)-1) // 2
    for i,(n,s) in enumerate(arr):
        if i <= half:
            dic[n].append((s,-1))
        else: 
            dic[n].append((s,1))
    res = []
    for n in range(100):
        for s,flag in dic[n]:
            if flag > 0: res.append(s)
            else: res.append('-')
    return ' '.join(res)
    
if __name__ == "__main__":
    n = int(input().strip())
    arr = []
    for a0 in range(n):
        x, s = input().strip().split(' ')
        x, s = [int(x), str(s)]
        arr.append((x,s))
    res = countingsort(arr)
    print(res)
