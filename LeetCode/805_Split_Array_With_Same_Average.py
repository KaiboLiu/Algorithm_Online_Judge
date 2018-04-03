## 805_Split_Array_With_Same_Average.py
## 68ms   %

'''
Total Accepted: 2.2K
Total Submissions: 11.2K
Instruction: LeetCode 805 - Split Array With Same Average [H]
Developer: lrushx
Process Time: Apr 02, 2018
'''

'''
In a given integer array A, we must move every element of A to either list B or list C. (B and C initially start empty.)

Return true if and only if after such a move, it is possible that the average value of B is equal to the average value of C, and B and C are both non-empty.

Example :
Input: 
[1,2,3,4,5,6,7,8]
Output: true
Explanation: We can split the array into [1,4,5,8] and [2,3,6,7], and both of them have the average of 4.5.
Note:

The length of A will be in the range [1, 30].
A[i] will be in the range of [0, 10000].
给一个数组，判断是否可以分成2个非空数组，其平均数相等
'''

## 总ave=Aave=Bave，遍历A大小后剪枝搜索。
## 用(rem_sum, count, idx, prev_chosen)作为参数，rem_sum为剩余需要的和，count为剩余需要取数个数，两个分支为“取当前idx减去”和“不取当前idx减去”。
## prev_chosen用于判断当前idx和前一个数相等且前一个数没取时，只搜索“取当前数”的情况，否则就搜索“取当前数”or“不取当前数”
## 剪枝很重要: 0.对A排序
## 1.ave*lenA若不是int则此lenA无用
## 2.count+idx>len时不必要再搜索
## 3.rem_sum/count < A[idx]时不必要再搜索，因为剩余的数都更大，而目标ave小
## 4.数组包含形如[5,5,5,5]时，为了避免取数[TF...]和[FT...]的重复，要求前一个不取(F)时后一个也不能取(i.e. 重复数T可以扩展出TF,TT，而F只能扩展出FF


class Solution:
    def splitArraySameAverage(self, A):
        """
        :type A: List[int]
        :rtype: bool
        """
        def exist(total, count, i, chosen):
            if count == 0:
                return False if total else True # iff total==0 make 'total' False
            if count+i > l: return False
            if total/count < A[i]: return False
            if i > 0 and A[i]==A[i-1] and not chosen:
                return exist(total,count,i+1,False)
            else:
                return exist(total-A[i],count-1,i+1,True) or exist(total,count,i+1,False)
            
        l,s = len(A), sum(A)
        if l == 1: return False
        ave = s/l
        
        #p, p1 = bisect.bisect_left(A,ave), bisect.bisect(A,ave)
        #if p < p1: return True
        if ave in A: return True
        A.sort()
        for lenA in range(2, l//2+1):
            if s*lenA % l == 0:
                if exist(int(lenA*ave), lenA, 0, True): return True
                
