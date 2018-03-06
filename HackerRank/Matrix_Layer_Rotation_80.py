#!/bin/python3
'''
Instruction: HackerRank - Matrix Layer Rotation - [H]
Success Rate: 75.47%
Max Score: 80
Difficulty: Hard
Submitted 19715 times
Developer: lrushx
Process Time: Mar 06, 2018
https://www.hackerrank.com/challenges/matrix-rotation-algo/problem
'''
#You are given a 2D matrix, a, of dimension MxN and a positive integer R. You have to rotate the matrix R times and print the resultant matrix. Rotation should be in anti-clockwise direction.
#Rotation of a 4x5 matrix is represented by the following figure. Note that in one rotation, you have to shift elements by one step only (refer sample tests for more clarity).

import sys


def matrixRotation(matrix, r):
    # Complete this function
    def nextidx(i,j,i1,i2,j1,j2):
        di, dj = {j:0}, {i:0}
        di[j1], di[j2] = 1, -1
        dj[i1], dj[i2] = -1, 1
        #di = {j1:1 , j2:-1}
        #dj = {i1:-1, i2:1}
        i, j = i+di[j], j+dj[i]
        i = i1 if i < i1 else i2 if i > i2 else i
        j = j1 if j < j1 else j2 if j > j2 else j
        return i, j
        
    def idxSeq(i,j,newi,newj,i1,i2,j1,j2,n):
        originIdx = []
        updateIdx, seq = [], []
        for _ in range(n):
            #originIdx.append((i, j))
            updateIdx.append((newi, newj))
            seq.append(matrix[i][j])
            i, j = nextidx(i,j,i1,i2,j1,j2)
            newi, newj = nextidx(newi,newj,i1,i2,j1,j2)
        #return originIdx, updateIdx, seq
        return updateIdx, seq
        
    def frameRotation(i1,i2,j1,j2):
        n = (i2-i1+j2-j1) << 1
        r1 = r % n
        newi, newj = i1, j1     # rotate top left [i1,j1] to [newi, newj]
        for _ in range(r1): newi,newj = nextidx(newi, newj, i1, i2, j1, j2)
        updateIdx, seq = idxSeq(i1,j1,newi,newj,i1,i2,j1,j2,n)
        for i in range(n):
            matrix[updateIdx[i][0]][updateIdx[i][1]] = seq[i]
            
    m, n = len(matrix), len(matrix[0])
    Round = min(m,n) >> 1
    for d in range(Round):
        frameRotation(d,m-1-d,d,n-1-d)
    for i in range(m): print(' '.join(map(str,matrix[i])))
    return
        
if __name__ == "__main__":
    m, n, r = input().strip().split(' ')
    m, n, r = [int(m), int(n), int(r)]
    matrix = []
    for matrix_i in range(m):
       matrix_t = [int(matrix_temp) for matrix_temp in input().strip().split(' ')]
       matrix.append(matrix_t)
    matrixRotation(matrix, r)

