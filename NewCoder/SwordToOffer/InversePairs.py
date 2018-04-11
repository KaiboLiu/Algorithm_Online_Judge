# -*- coding:utf-8 -*-
'''
Challenge: InversePairs.py
Total Acceptence: 14.66%
Developer: lrushx
Process Time: Apr 10, 2018
https://www.nowcoder.com/practice/96bd6684e04a44eb80e6a68efc0ec6c5?tpId=13&tqId=11188&tPage=2&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
'''

class Solution:
    def InversePairs(self, data):
        def mergesort_inv(a):
            if len(a) <= 1: return a
            mid   = int(len(a)/2)
            left  = mergesort_inv(a[:mid])
            right = mergesort_inv(a[mid:])
            return merge_inv(left,right)

        def merge_inv(a,b):
            i, j, c = 0, 0, []
            lenA = len(a)
            while i < lenA and j < len(b):
                if a[i] <= b[j]:
                    c.append(a[i])
                    i += 1
                else: 
                    c.append(b[j])
                    j += 1
                    res[0] = (res[0]+ lenA - i) % MOD
            #c[len(c):len(c)] = a[i:] if i < len(a) else b[j:]
            if i < len(a): return  c+a[i:]
            else: return c+b[j:]

        res = [0]
        MOD = 1000000007
        mergesort_inv(data)
        return res[0]

a = [1,2,3,4,5,6,7,0]
s=Solution()
print(s.InversePairs(a))
a = [364,637,341,406,747,995,234,971,571,219,993,407,416,366,315,301,601,650,418,355,460,505,360,965,516,648,727,667,465,849,455,181,486,149,588,233,144,174,557,67,746,550,474,162,268,142,463,221,882,576,604,739,288,569,256,936,275,401,497,82,935,983,583,523,697,478,147,795,380,973,958,115,773,870,259,655,446,863,735,784,3,671,433,630,425,930,64,266,235,187,284,665,874,80,45,848,38,811,267,575]
print(s.InversePairs(a))
N = 200000
import random
a = [random.randint(0,10000) for _ in range(N)]
import time
t0 = time.time()
print(s.InversePairs(a))
print(time.time()-t0)
