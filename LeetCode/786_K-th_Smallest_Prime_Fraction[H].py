## 786_K-th_Smallest_Prime_Fraction\[H\].py
## 172ms  98.73%

'''
Total Accepted: 51.8K
Total Submissions: 138.3K
Developer: lrushx
Process Time: Apr 16, 2018
https://leetcode.com/problems/k-th-smallest-prime-fraction/description/
'''

'''
A sorted list A contains 1, plus some number of primes.  Then, for every p < q in the list, we consider the fraction p/q.

What is the K-th smallest fraction considered?  Return your answer as an array of ints, where answer[0] = p and answer[1] = q.

Examples:
Input: A = [1, 2, 3, 5], K = 3
Output: [2, 5]
Explanation:
The fractions to be considered in sorted order are:
1/5, 1/3, 2/5, 1/2, 3/5, 2/3.
The third fraction is 2/5.

Input: A = [1, 7], K = 1
Output: [1, 7]
Note:

A will have length between 2 and 2000.
Each A[i] will be between 1 and 30000.
K will be between 1 and A.length * (A.length - 1) / 2.
'''

## 给一个递增数组和K，求两两组成的小于1的分数A[i]/A[j]中第K大的
## 把A[i],A[j]分别当成行元素和列元素，构成的矩阵为A[i]/A[j]，可以发现按行递减且按列递减，最小的在最右上角，类似378
## 因为矩阵元素介于(0,1)之间，二分查找一个m，从l=0,r=1开始，统计矩阵中元素<=m的(i,j)对数count，若count==K则说明正好K个元素<=m，输出最大的即可(中间记录)
## 若count<K说明m设的太小，比其小的元素个数count太少，应该增加m, l=m，否则就r=m
## 设完m计数时，按行数，每行中的j可以继承上一行，增加j，当A[i]/A[j]开始<=m就可以停了，这个j之后的(i,j)都满足, 然后下一行继续从这个j开始
## 看的是花花的讲解，挺巧妙的。
## n^2构造后qselect也能过 不过要8.8s





class Solution:
    def kthSmallestPrimeFraction(self, A, K):
        l, r = 0, 1.0
        N = len(A)
        p = q = 0   # to store the optimal pair (p,q)
        while l < r:
            m = (l+r)/2
            f_max = 0.0
            count = 0   # count the number of (i,j) pairs that A[i]/A[j] <= m, all of them are at top right
                        # larger m means larger count
                        # if count == m, then the largest of them is the answer
            j = 1
            for i in range(N-1):
                while j < N and A[i] > m * A[j]: j += 1
                if j == N: break
                count += N-j    # add the number of elements starting from j to right
                f = A[i]/A[j]
                if f > f_max:
                    p, q, f_max = i, j, f
            if count == K: return [A[p],A[q]]
            elif count < K: l = m   # m too small, count of top right is not enough
            else: r = m
        return []
