#!/bin/python3
'''
Instruction: HackerRank - Big Sorting - [E]
Success Rate: 63.94%
Max Score: 20
Difficulty: Easy 
Submitted 35849 times
Developer: lrushx
Process Time: Mar 29, 2018
https://www.hackerrank.com/challenges/big-sorting/problem
'''

## Sort a list of numbers, whose number of digits can be as large as 10^6
## just need to construct a tuple (len,s) to sort


import sys


if __name__ == "__main__":
    n = int(input().strip())
    arr = []
    arr_i = 0
    for arr_i in range(n):
        arr_t = str(input().strip())
        arr.append((len(arr_t),arr_t))
    res = sorted(arr)
    result = [s for _,s in res]
    print ("\n".join(map(str, result)))



