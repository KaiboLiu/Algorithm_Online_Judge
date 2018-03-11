#!/bin/python3
'''
Instruction: HackerRank - Candies - [M]
Success Rate: 67.09%
Max Score: 50
Difficulty: Medium
Submitted 31459 times
Developer: lrushx
Process Time: Mar 10, 2018
https://www.hackerrank.com/challenges/candies/problem
'''

# Alice is a kindergarten teacher. She wants to give some candies to the children in her class.  All the children sit in a line (their positions are fixed), and each  of them has a rating score according to his or her performance in the class.  Alice wants to give at least 1 candy to each child. If two children sit next to each other, then the one with the higher rating must get more candies. Alice wants to save money, so she needs to minimize the total number of candies given to the children.

# Input Format
# The first line of the input is an integer , the number of children in Alice's class. Each of the following  lines contains an integer that indicates the rating of each child.

import sys

def candies(n, arr):
    # Complete this function
    def v_up(i):
        c = res[i] = 1
        a = i
        while a > 0 and arr[a-1] > arr[a]:
            a -= 1
            c += 1
            res[a] = max(res[a],c)
        a, c = i, 1
        while a < n-1 and arr[a+1] > arr[a]:
            a += 1
            c += 1
            res[a] = max(res[a],c)

    if n == 0: return 0
    if n == 1: return 1
    arr.append(1<<30)
    res = [0] * n
    #res = defaultdict(int)
    if arr[0] <= arr[1]: v_up(0)
    for i in range(1,n):
        if arr[i-1] >= arr[i] <= arr[i+1]:
            v_up(i)
    return sum(res)
    #return res
    
    
    
if __name__ == "__main__":
    n = int(input().strip())
    arr = []
    arr_i = 0
    for arr_i in range(n):
       arr_t = int(input().strip())
       arr.append(arr_t)
    result = candies(n, arr)
    print(result)
