## 307_Range_Sum_Query-Mutable\[M\].py
## 104ms   94.85%

'''
Total Accepted: 43.4K
Total Submissions: 193.2K
Developer: lrushx
Process Time: Apr 03, 2018
https://leetcode.com/problems/range-sum-query-mutable/description/
'''

'''
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

The update(i, val) function modifies nums by updating the element at index i to val.
Example:
Given nums = [1, 3, 5]

sumRange(0, 2) -> 9
update(1, 2)
sumRange(0, 2) -> 8
Note:
The array is only modifiable by the update function.
You may assume the number of calls to update and sumRange function is distributed evenly.
'''

## 给一个数组，有两种操作：求i..j的和，以及更新某个数字
## 用前缀和数组的话两种操作是O(1)和O(n)；
## 用原数组的话两种操作是O(n)和O(1)；
## 用BIT/二叉索引树/树状数组则都是O(logn)，用lowbit

## 扎扎实实学了树状数组BIT。a下标以1开始
## ci=sum(a[i-lowbit(i)+1],..,a[i]), 则sum(1..i)=ci+ci左上+.. (i左上=i-lowbit(i))
## 更新ai时，算出增量dx，ci及其所有右上父节点都加dx(i右上=i+lowbit(i))


class NumArray:

    def __init__(self, nums):
        """
        :type nums: List[int]
        """
        self.n    = len(nums)   # 1..n instead of 0..0-1
        self.nums = [0] * self.n
        self.c    = [0] * (self.n+1)
        for i,x in enumerate(nums):
            self.update(i,x)

    def update(self, i, val):
        """
        :type i: int
        :type val: int
        :rtype: void
        """
        dx, self.nums[i] = val-self.nums[i], val
        i += 1
        while i <= self.n:
            self.c[i] += dx
            i += i & (-i)
        
    def sumRange(self, i, j):
        """
        :type i: int
        :type j: int
        :rtype: int
        """
        def getSum(a):
            Sum = 0
            while a > 0:
                Sum += self.c[a]
                a -= a & (-a)
            return Sum
        return getSum(j+1) - getSum(i)
        


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# obj.update(i,val)
# param_2 = obj.sumRange(i,j)
