'''
Instruction: HackerRank - Almost Sorted - [M]
Success Rate: 70.82%
Max Score: 50
Difficulty: Medium
Submitted 14993 times
Developer: lrushx
Process Time: Mar 05, 2018
'''

#Given an array with  elements, can you sort this array in ascending order using only one of the following operations?
#Swap two elements.
#Reverse one sub-segment.
#Input Format 
#The first line contains a single integer, , which indicates the size of the array. 
#The next line contains  integers separated by spaces.


#!/bin/python3

import sys


def almostSorted(arr):
    # Complete this function
    
    def within(i,j):
        if (j == 0 and arr[i] < arr[j+1]) or (arr[j-1] < arr[i] < arr[j+1]):
            return True
        else: return False
            
    l,r = [],[]
    arr.append(1<<32)
    i,n = 1, len(arr)
    while i < n:
        while i < n and arr[i] > arr[i-1]: i += 1
        if i == n: 
            #print('yes')
            break
        l.append(i-1)
        while i < n and arr[i] < arr[i-1]: i += 1
        r.append(i-1)
    if len(l) == 0:
        print('yes')
        return
    if len(l) == 1:
        if arr[l[0]] < arr[r[0]+1] and (l[0] == 0 or arr[l[0]-1] < arr[r[0]]):
            print('yes')
            if r[0]-l[0] == 1:
                print('swap {} {}'.format(l[0]+1,r[0]+1))
            else:
                print('reverse {} {}'.format(l[0]+1,r[0]+1))
            return
        else: 
            print('no')
            return
    if len(l) == 2 and r[0]-l[0] == 1 and r[1]-l[1] == 1:
        if within(l[0],r[1]) and within(r[1],l[0]):
            print('yes')
            print('swap {} {}'.format(l[0]+1,r[1]+1))
            return
    print('no')
    return
        

if __name__ == "__main__":
    n = int(input().strip())
    arr = list(map(int, input().strip().split(' ')))
    almostSorted(arr)
