#!/bin/python3
'''
Instruction: HackerRank - Counting Sort 1 - [E]
Success Rate: %
Max Score: 30
Difficulty: Easy 
Submitted 38965 times
Developer: lrushx
Process Time: Mar 29, 2018
https://www.hackerrank.com/challenges/countingsort1/problem
'''

## Alternative Sorting 
## However, for certain types of input, it is more efficient to use a non-comparison sorting algorithm. This will make it possible to sort lists even in linear time. These challenges will cover Counting Sort, a fast way to sort lists where the elements have a small number of possible values, such as integers within a certain range. We will start with an easy task - counting.
## 
## Given a list of integers, can you count and output the number of times each value appears?
## 
## Hint: There is no need to sort the data, you just need to count it.



import sys

def countingSort(arr):
    # Complete this function
    res = [0] * 100
    for x in arr: res[x] += 1
    return res

if __name__ == "__main__":
    n = int(input().strip())
    arr = list(map(int, input().strip().split(' ')))
    result = countingSort(arr)
    print (" ".join(map(str, result)))


