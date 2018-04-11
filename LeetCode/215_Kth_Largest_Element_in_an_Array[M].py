# 215_Kth_Largest_Element_in_an_Array.py
## 48ms   100%

'''
Total Accepted:191.4K
Total Submissions:473.8K
Instruction: LeetCode 215 - Kth Largest Element in an Array [M]
Developer: lrushx
Process Time: Feb 23, 2018
'''

'''
Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.
For example,
Given [3,2,1,5,6,4] and k = 2, return 5.
'''


class Solution:
    def findKthLargest(self,num,k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        from random import randint
        def qselect(a, k):
            if a==[] or k > len(a): return None 
            idx = randint(0,len(a)-1)
            a[0], a[idx] = a[idx], a[0]
            left  = [x for x in a[1:] if x >= a[0]]
            l = len(left)
            if k == l+1: return a[0]
            if k <= l: return qselect(left,k)
            
            right = [x for x in a if x < a[0]]
            return qselect(right,k-l-1)
        return qselect(num,k)


if __name__ == "__main__":
    c = Solution()
    
    print(c.findKthLargest([1, 1, 2],2))
    print(c.findKthLargest([10, 10, 10],1))
    print(c.findKthLargest([3,2,1,5,6,4],2))
