#!/bin/python3
'''
Instruction: HackerRank - Insertion Sort Part1 - [E]
Success Rate: %
Max Score: 30
Difficulty: Easy 
Submitted 104620 times
Developer: lrushx
Process Time: Mar 28, 2018
https://www.hackerrank.com/challenges/insertionsort1/problem
'''



import sys

def insertionSort1(n, arr):
    # Complete this function
    tmp = arr[-1]
    for i in range(n-2,-1,-1):
        if arr[i] > tmp: 
            arr[i+1] = arr[i]
            print(' '.join(map(str,arr)))
        else: 
            arr[i+1] = tmp
            break
    if arr[0] > tmp: arr[0] = tmp
    print(' '.join(map(str,arr)))
    
if __name__ == "__main__":
    n = int(input().strip())
    arr = list(map(int, input().strip().split(' ')))
    insertionSort1(n, arr)

