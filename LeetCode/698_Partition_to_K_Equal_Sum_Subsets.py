## 698_Partition_to_K_Equal_Sum_Subsets.py
## 69ms   94.74%

'''
Total Accepted:10.6K
Total Submissions:28.1K
Instruction: LeetCode 698 - Partition to K Equal Sum Subsets - [M]
Developer: lrushx
Process Time: Feb 11, 2018
'''

'''
Given an array of integers nums and a positive integer k, find whether it's possible to divide this array into k non-empty subsets whose sums are all equal.
Sort the nums reversely, find a set to meet the ave, then remove them from source
1 <= k <= len(nums) <= 16.
0 < nums[i] < 10000.
'''

# DP is slower than DFS because len(nums) <= 16 and 0 < nums[i] < 10000.


class Solution:
    '''
    def canPartitionKSubsets(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        from functools import reduce
        from copy import deepcopy

        nums = self.resize(nums)
        nums.sort(reverse=True)
        sums = sum(nums)
        #sums = [0] * len(nums)
        #sums[0] = nums[0]
        #for i in range(1,len(nums)): sums[i] = sums[i-1]+nums[i]
        ave = sums // k
        if sums % k != 0: return False
        if not all([x<=ave for x in nums]): return False
        for r in range(k):
            f, l = [False]*(ave+1), [[] for _ in range(ave+1)]
            f[0] = True
            #for i,x in enumerate(nums):
            for x in nums:
                for v in range(ave,x-1,-1):
                    if not f[v] and f[v-x]:
                        l[v] = deepcopy(l[v-x])
                        l[v].append(x)
                        f[v] = True
                    
            if not f[ave]: return False
            for x in l[ave]: nums.remove(x)
        return True


    # Pruning 1: Resize the sums/value, divided by gcd
    # use gcd(Greatest Common Divisor) in value to trim the size of sums to sums/gcd
    def resize(self, a):
        from fractions import gcd
        from functools import reduce
        fac = reduce(gcd,[x for x in a])
        if fac > 1:
            b = [x//fac for x in a]
            return b
        else: return a
    '''

    def canPartitionKSubsets(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """ 
        if k == 1: return True
        nums.sort(reverse=True)
        sums = sum(nums)

        if sums % k or k > len(nums): return False
        ave = sums // k
        if nums[0] > ave: return False
        v = [False] * (len(nums)+1)

        def DFS(nums, k, v, left, start):
            if k == 1: return True

            if left == 0:
                return DFS(nums, k-1, v, ave, 0)

            #for i, x in enumerate(nums):
            for i in range(start,len(nums)):
                if nums[i] <= left and not v[i]:
                    v[i] = True
                    if DFS(nums, k, v, left-nums[i], i+1): return True
                    v[i] = False

            return False

        return DFS(nums, k, v, ave,0)


if __name__ == "__main__":
    c = Solution()
    
    print(c.canPartitionKSubsets([4, 3, 2, 3, 5, 2, 1],4))
    print(c.canPartitionKSubsets([2,2,2,2,3,4,5],4))
    print(c.canPartitionKSubsets([4,4,6,2,3,8,10,2,10,7],4))
    print(c.canPartitionKSubsets([85,35,40,64,86,45,63,16,5364,110,5653,97,95],7))

