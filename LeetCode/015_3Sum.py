# -*- coding: utf-8 -*-

#LeetCode - 015_3Sum.py
#198ms	72.60%

'''
Instruction: LeetCode 015 - 3Sum - [M]
Developer: lrushx
Process Time: Nov 18, 2016
'''
 
'''
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note: The solution set must not contain duplicate triplets.

For example, given array S = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
'''

#给一个数组，求出3元集合，使得和为0，答案不能重复
#排序后搜索，遍历第一个i，然后用2个指针从i+1和n-1往中间搜索，如果符合就输出，然后继续往中间


class Solution(object):

    def threeSum(self, nums):

        """

        :type nums: List[int]

        :rtype: List[List[int]]

        """

        nums = sorted(nums)

        n = len(nums)

        print nums,n, range(2,n-1)

        ans = []

        for i in range(n-2):

            if (nums[i] > 0):

                break

            if ((i > 0) and (nums[i] == nums[i-1])):

                continue

            j,k = i+1,n-1

            while j < k:

                if nums[i]+nums[j]+nums[k] > 0:

                    k -= 1

                elif nums[i]+nums[j]+nums[k] < 0:

                    j += 1

                else:

                    ans.append([nums[i], nums[j], nums[k]])

                    j,k = j+1,k-1

                    while j < k and nums[j] == nums[j-1]:

                        j += 1

                    while j < k and nums[k] == nums[k+1]:

                        k -= 1

        return ans
