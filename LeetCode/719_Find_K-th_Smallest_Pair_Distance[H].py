## 719_Find_K-th_Smallest_Pair_Distance[H].py
## 96ms  100%

'''
Total Accepted: 7.8K
Total Submissions: 28.6K
Developer: lrushx
Process Time: May 14, 2018
https://leetcode.com/problems/find-k-th-smallest-pair-distance/description/
'''

'''
Given an integer array, return the k-th smallest distance among all the pairs. The distance of a pair (A, B) is defined as the absolute difference between A and B.

Example 1:
Input:
nums = [1,3,1]
k = 1
Output: 0 
Explanation:
Here are all the pairs:
(1,3) -> 2
(1,1) -> 0
(3,1) -> 2
Then the 1st smallest distance pair is (1,1), and its distance is 0.
Note:
2 <= len(nums) <= 10000.
0 <= nums[i] < 1000000.
1 <= k <= len(nums) * (len(nums) - 1) / 2.
'''

## 给一个数列，求两两组合(不交换)后差值绝对值中的第k大
## 类似668/786/378，把A[i],A[j]分别当成行元素和列元素，构成的矩阵为A[j]-A[i]，上三角不含对角线即为题目所需所有元素。
## 可以发现同行递增且同列递减，最大的在最右上角
## 因为矩阵元素介于(0,A[-1]-A[0])之间，二分查找一个m，从l=0,r=最大,开始，统计矩阵中元素<=mmid的(i,j)对数count，若count==K则说明正好K个元素<=m.
## 若count<K说明m设的太小，比其小的元素个数count太少，应该增加m, l=m+1，否则就r=m
## 设完m后开始计数时，按行数，增加j，当A[j]-A[i]开始<=m就可以停了，这个j之后的(i,j)都满足, 然后下一行继续从这个j开始，每行中的j可以继承上一行，因为i增加j不变的元素肯定更小，更加符合<=mid的条件。
## while条件是l<r，最后返回l即可
## 
## 优化提升:
## 第一行j的位置可以用二分，相比线性找可以提升152ms/40.7% -> 96ms/100%
## 若找到j是最右，说明下方所有元素都更小，都满足<=mid，就不用再遍历i了，直接计算三角形大小加到count中再break，可以提升104ms/80.23% -> 96ms/100%
## 每个i开始时，没必要保证j>i，因为如果j太小，会自动往上加，若加这个冗余判断，时间降低96ms/100% -> 124ms/54.65%


class Solution:
    def smallestDistancePair(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        nums.sort()
        #print(nums)
        n = len(nums)
        l, r = 0, nums[-1]-nums[0]
        while l < r:
            mid = (l+r)//2
            count = 0
            j = bisect.bisect(nums, nums[0]+mid)   #this binary search helps time from 152ms/40.7% to 96ms/100%
            if j == n: j -= 1
            count = j-1
            for i in range(1, n-1):
                #j = max(j, i+1)    # this will make time drop from 96ms/100% to 124ms/54.65%
                while j < n and nums[j]-nums[i] <= mid: j += 1
                if j == n:  # 3 lines starting from this, helps time from 104ms/80.23% to 96ms/100%
                    count += (j-i-1)*(j-i)>>1
                    break
                count += j-i-1
            if count < k: l = mid+1
            else: r = mid
        return l

class Solution:
    def findKthNumber(self, m, n, k):
        """
        :type m: int
        :type n: int
        :type k: int
        :rtype: int
        """
        l, r = 1, k# m*n
        if m > n: m, n = n, m
        while l < r:
            mid = (r-l)//2+l
            count = 0
            x = min(m, mid)
            for i in range(1, x+1):
                if i * n <= mid:
                    count += n
                else:
                    count += mid // i
            if count < k: l = mid+1
            else: r = mid
        return l
