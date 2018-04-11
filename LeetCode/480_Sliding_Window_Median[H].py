## 480_Sliding_Window_Median[H].py
## 100ms   100%

'''
Total Accepted: 13.3K
Total Submissions: 43.2K
Developer: lrushx
Process Time: Apr 10, 2018
https://leetcode.com/problems/sliding-window-median/description/
'''

'''
Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.

Examples: 
[2,3,4] , the median is 3
[2,3], the median is (2 + 3) / 2 = 2.5
Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position. Your job is to output the median array for each window in the original array.
For example,
Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.

Window position                Median
---------------               -----
[1  3  -1] -3  5  3  6  7       1
 1 [3  -1  -3] 5  3  6  7       -1
 1  3 [-1  -3  5] 3  6  7       -1
 1  3  -1 [-3  5  3] 6  7       3
 1  3  -1  -3 [5  3  6] 7       5
 1  3  -1  -3  5 [3  6  7]      6
Therefore, return the median sliding window as [1,-1,-1,3,5,6].
'''

## 滑动窗口排序，每次删除窗口最左数，再插入最右数
## for a,b in zip(nums, nums[k:]): #a,b为当前窗口在原数组中的首位和窗口外下一位
## 删除用window.pop(bisect.bisect_left(window, a))
## 插入用bisect.insort(window, b)
## size为k的排序数组的中位数：
## (window[k//2]+window[~(k//2)])/2, 其中~k//2=-k//2-1
## 若k为奇数，则从左往右第k//2正好是从右往左k//2+1个
## 若k为偶数，则从左往右第k//2是中间偏右，而从右往左k//2+1是中间偏左


class Solution:
    def medianSlidingWindow(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[float]
        """
        #python3
        window = sorted(nums[:k])

        res = []
        for a,b in zip(nums,nums[k:]+[0]):
            res.append((window[k//2]+window[~(k//2)])/2)
            #window.remove(a)
            window.pop(bisect.bisect_left(window,a))
            bisect.insort(window,b)
        '''
        res = [(window[k//2]+window[~(k//2)])/2]
        for x in range(len(nums)-k):
            window.remove(nums[x])
            bisect.insort(window, nums[x+k])
            res.append((window[k//2]+window[~(k//2)])/2)
        '''
        return res
        
