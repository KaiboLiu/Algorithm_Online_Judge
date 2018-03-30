#!/bin/python3
'''
Instruction: HackerRank - Insertion Sort Part2 - [E]
Success Rate: %
Max Score: 30
Difficulty: Easy 
Submitted 76121 times
Developer: lrushx
Process Time: Mar 28, 2018
https://www.hackerrank.com/challenges/insertionsort2/problem
'''

import sys

def insertionSort2(n, arr):
    # Complete this function
    for i in range(1,n):
        for j in range(i):
            if arr[i] < arr[j]:
                arr[i], arr[j] = arr[j], arr[i]
        print(' '.join(map(str,arr)))
        
        
if __name__ == "__main__":
    n = int(input().strip())
    arr = list(map(int, input().strip().split(' ')))
    insertionSort2(n, arr)
