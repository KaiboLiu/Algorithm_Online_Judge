## 801_Minimum_Swaps_To_Make_Sequences_Increasing[M].py
## 52ms  98.71%

'''
Total Accepted: 3K
Total Submissions: 12.1K
Developer: lrushx
Process Time: Apr 22, 2018
https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing/description/
'''

'''
We have two integer sequences A and B of the same non-zero length.

We are allowed to swap elements A[i] and B[i].  Note that both elements are in the same index position in their respective sequences.

At the end of some number of swaps, A and B are both strictly increasing.  (A sequence is strictly increasing if and only if A[0] < A[1] < A[2] < ... < A[A.length - 1].)

Given A and B, return the minimum number of swaps to make both sequences strictly increasing.  It is guaranteed that the given input always makes it possible.
'''

## 给2个等长数列A和B，可以交换任意对等位置的A[i]和B[i]，使得A和B严格递增，保证有解，求最小的交换次数
## DP, f[i]=(n_swap,x,y)表示第i个位置最少的交换次数、A中放置的数、B中放置的数
## 设置一个cut位置，1.当A[i-1],B[i-1]的最大值<A[i],B[i]的最小值时，更新cut为i，best加上当前的交换次数f[i-1][0]，意思是：即使在i后面的某位置j，我发现更优解需要翻转之前赋值时，只需要翻转cut~j-1而不是0~j-1
## 有了第二行设定后，可以知道f[i-1]中包含了i的前一位的最优配置x,y，于是有了递推式：
## 2.若x<A[i]且y<B[i]时，则i位置不用翻转,f[i]=(f[i-1][0],A[i],B[i])
## 3.若x<B[i]且y<A[i]时，则需要翻转i位置，结果为(f[i-1][0]+1,B[i],A[i])；而另外有种选择是保留i位置，而是翻转cut~i-1的所有赋值，则结果为(i-cut-f[i-1][0],A[i],B[i])，取这两者中的较小值即可，tuple会直接从第一个分量开始比较
## 答案为best+f[n-1][0]


class Solution:
    def minSwap(self, A, B):
        """
        :type A: List[int]
        :type B: List[int]
        :rtype: int
        """

        n = len(A)
        if n == 0: return 0
        f = {-1: (0, -1, -1)}   # i: (n_swap,xi,yi)
        cut = 0
        best = 0
        for i,(a,b) in enumerate(zip(A,B)):
            n_swap, x, y = f[i-1]
            if max(x,y) < min(a,b):
                cut = i
                best += n_swap
                f[i] = (0, a, b)
            elif x < a and y < b:   # x(i-1) < A[i] and y(i-1) < B[i]
                f[i] = (n_swap, a, b)
            else:   # a(i-1) < B[i] and b(i-1) < A[i], the else is guaranteed, no need for elif
                f[i] = min((n_swap+1, b, a), (i-cut-n_swap, a, b))    # swap A[i], B[i], or flip the decision on cut~i-1
        return best + f[n-1][0]
