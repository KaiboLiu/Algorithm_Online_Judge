## 315_Count_of_Smaller_Numbers_After_Self[H].py
## 120ms   99.02%

'''
Total Accepted: 45.7K
Total Submissions: 130.6K
Developer: lrushx
Process Time: Mar 30, 2018
https://leetcode.com/problems/count-of-smaller-numbers-after-self/
'''

'''
You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].

Given nums = [5, 2, 6, 1]
To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.
Return the array [2, 1, 1, 0].
'''
## 给一个数组a，统计每个元素右边有多少个比其小的数，等价于inversion，对于每个i，求所有i<j且a[i]>a[j]的j的个数
## Sol2. CS519给出mergesort中计数的方法，在merge时a,b两个数组中如果a[i]>b[j]要合并b[j]，则a[i]及其往后都和b[j]满足条件，在答案中加上lenA-i即可
## Sol1. 另一种巧妙的方法，从右往左把a中数字插入一个数组b中并保持排序，则新数可以二分查找bisect_left确定位置pos再insert到b，该数的inversion数即为pos

import bisect
class Solution:
    ## Solution1: construct and count with binary search(bisect)
    ## 120ms   99.02%
    def countSmaller(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        res, arr = [],[]
        for x in reversed(nums):
            idx = bisect.bisect_left(arr,x)
            arr.insert(idx, x)
            res.append(idx)
        return list(reversed(res))
    
    ## Solution2: count within mergesort
    ## 220ms   60.78%
    def countSmaller2(self, nums):
        def mergesort_inv(a):
            if len(a) < 2: return a
            mid   = len(a) // 2
            left  = mergesort_inv(a[:mid])
            right = mergesort_inv(a[mid:])
            return merge_inv(left, right)

        def merge_inv(a,b):
            i,j,c = 0,0,[]
            lenA = len(a)
            while i < len(a) and j < len(b):
                if a[i] <= b[j]:
                    c.append(a[i])
                    res[a[i][1]] += j
                    i += 1
                else:
                    c.append(b[j])
                    j += 1
                    
            c[len(c):len(c)] = a[i:] if i<len(a) else b[j:]
            for ii in range(i,lenA): res[a[ii][1]] += j
            return c
        arr = []
        res = [0] * len(nums)
        for i,x in enumerate(nums):
            arr.append((x,i))
        print(arr)
        mergesort_inv(arr)
        return res
