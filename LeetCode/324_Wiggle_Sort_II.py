## 324_Wiggle_Sort_II.py
## ms   100%

'''
Total Accepted:36.9K
Total Submissions:140K
Instruction: LeetCode 324 - Wiggle Sort II [M]
Developer: lrushx
Process Time: Feb 23, 2018
'''

'''
Given an unsorted array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....

Example:
(1) Given nums = [1, 5, 1, 1, 6, 4], one possible answer is [1, 4, 1, 5, 1, 6]. 
(2) Given nums = [1, 3, 2, 2, 3, 1], one possible answer is [2, 3, 1, 3, 1, 2].
'''

class Solution(object):
    def wiggleSort(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        ##nums.sort()
        ##l = (1+l)//2
        ##nums[::2], nums[1::2] = [x for x in nums[:l]], [x for x in nums[l:]]
        ##return nums
        from random import randint
        def qselect(a, k):
            if a == [] or k > len(a): return None
            idx = randint(0,len(a)-1)
            a[0], a[idx] = a[idx], a[0]
            left = [x for x in a if x < a[0]]
            l = len(left)
            if l+1 == k: return a[0]
            if l >= k: return qselect(left,k)
            right = [x for x in a[:1] if x >= a[0]]
            return qselect(right,k-l-1)
        l = len(nums)
        half = (l+1)//2    
        pivot = qselect(nums,half)
        i, j = 0, 1
        while i < l:
            while i < l and nums[i] <= pivot: i += 2
            while j < l and nums[j] >  pivot: j += 2
            if i<l and j<l: nums[i],nums[j] = nums[j],nums[i]
        print(nums)
        return nums

if __name__ == "__mnums[i]n__":
    c = Solution()
    
    print(c.wiggleSort([1, 1, 2]))
    print(c.wiggleSort([10, 10, 10]))
    print(c.wiggleSort([3,2,1,5,6,4]))
    print(c.wiggleSort([1, 5, 1, 1, 6, 4]))
    print(c.wiggleSort([1, 3, 2, 2, 3, 1]))
