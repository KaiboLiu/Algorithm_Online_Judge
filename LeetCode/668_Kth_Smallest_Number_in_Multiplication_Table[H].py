## 668_Kth_Smallest_Number_in_Multiplication_Table[H].py
## 424ms  100%

'''
Total Accepted: 6.5K
Total Submissions: 16K
Developer: lrushx
Process Time: May 13, 2018
https://leetcode.com/problems/kth-smallest-number-in-multiplication-table/description/
'''

'''
Nearly every one have used the Multiplication Table. But could you find out the k-th smallest number quickly from the multiplication table?

Given the height m and the length n of a m * n Multiplication Table, and a positive integer k, you need to return the k-th smallest number in this table.

Example 1:
Input: m = 3, n = 3, k = 5
Output: 
Explanation: 
The Multiplication Table:
1	2	3
2	4	6
3	6	9

The 5-th smallest number is 3 (1, 2, 2, 3, 3).
Example 2:
Input: m = 2, n = 3, k = 6
Output: 
Explanation: 
The Multiplication Table:
1	2	3
2	4	6

The 6-th smallest number is 6 (1, 2, 2, 3, 4, 6).
Note:
The m and n will be in the range [1, 30000].
The k will be in the range [1, m * n]
'''

## 给行列数m,n，求1..m和1..n中两两相乘结果中第k大的数
## 即m*n维的乘法表中第k大
## 
## 类似786/378，在按行/按列有序的矩阵中找第k大
## 可以用二分法，l=最小，r=最大，while l<r，mid=(l+r)/2，找矩阵中<=mid的个数，若<k则l=mid+1否则r=mid
## 统计个数可以用每行的性质，不必每行重复计算
## 因为按行是逐行计算，但是列元素是跳跃的，所以把行列交换成小、大
## 最后返回l即可
## 因为存在1*n，故第k个数字肯定<=k，所以r最大定位k即可不需mn
## for比while快，
## count += mid//i if i*n>mid else n比count+=min(mid//i,n)快不少
## 按照这套二分，可以规避多个元素=第k个的重复计数需求

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
