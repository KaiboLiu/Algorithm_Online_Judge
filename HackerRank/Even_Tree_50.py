#!/bin/python3
'''
Instruction: HackerRank - Even Tree [M]
Success Rate: 
Max Score: 50
Difficulty: Medium
Submitted 26175  times
Developer: lrushx
Process Time: Apr 15, 2018
https://www.hackerrank.com/challenges/even-tree/problem
'''

'''
You are given a tree (a simple connected graph with no cycles).

Find the maximum number of edges you can remove from the tree to get a forest such that each connected component of the forest contains an even number of nodes.

Input Format

The first line of input contains two integers  and , the number of nodes and edges. 
The next  lines contain two integers  and  which specify nodes connected by an edge of the tree. The root of the tree is node .
'''


import os
import sys
from collections import defaultdict

def EvenTree(V,E,edges):
    def count(u):   # return n_node, n_remove
        N, R = 1, 0
        father.add(u)
        for v in edges[u]:
            if v not in father:
                n, r = count(v)
                N += n
                R += r
        if N & 1 == 0: R += 1
        return N, R
    father = set({1})
    return sum(count(v)[1] for v in edges[1])

if __name__ == '__main__':
    tree_nodes, tree_edges = map(int, input().split())

    edges = defaultdict(set)
    for tree_itr in range(tree_edges):
        u,v = map(int, input().split())
        edges[u].add(v)
        edges[v].add(u)
    
    print(EvenTree(tree_nodes, tree_edges, edges))
    

