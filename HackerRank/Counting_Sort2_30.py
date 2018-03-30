#!/bin/python3
'''
Instruction: HackerRank - Counting Sort 2 - [E]
Success Rate: %
Max Score: 30
Difficulty: Easy 
Submitted 35227 times
Developer: lrushx
Process Time: Mar 29, 2018
https://www.hackerrank.com/challenges/countingsort2/problem
'''

## Given an unsorted list of integers, output the integers in order.
## If the range of numbers is _limited_
## Hint: You can use your previous code that counted the items to print out the actual values in order.


import sys

def countingSort(arr):
    # Complete this function
    R = 100
    counting = [0] * R
    for x in arr:
        counting[x] += 1
    res = []
    for x in range(R):
        for _ in range(counting[x]):
            res.append(x)
            
    return res

if __name__ == "__main__":
    n = int(input().strip())
    arr = list(map(int, input().strip().split(' ')))
    result = countingSort(arr)
    print (" ".join(map(str, result)))



