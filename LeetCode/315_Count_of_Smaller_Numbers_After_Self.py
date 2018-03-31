## 315_Count_of_Smaller_Numbers_After_Self.py
## 212ms   62.74%

'''
Total Accepted: 45.7K
Total Submissions: 130.6K
Instruction: LeetCode 315 - Count of Smaller Numbers After Self [H]
Developer: lrushx
Process Time: Mar 30, 2018
'''

'''
You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].

Example:

Given nums = [5, 2, 6, 1]

To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.
Return the array [2, 1, 1, 0].
'''


class Solution:
    def countSmaller(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
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
