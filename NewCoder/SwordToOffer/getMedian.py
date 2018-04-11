# -*- coding:utf-8 -*-
'''
Challenge: getMedian.py
Total Acceptence:
Developer: lrushx
Process Time: Apr 10, 2018
https://www.nowcoder.com/practice/9be0172896bd43948f8a32fb954e1be1?tpId=13&tqId=11216&tPage=4&rp=3&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking
'''

# -*- coding:utf-8 -*-
import heapq 
class Solution:
    def __init__(self):
        self.maxHeap = []    # small half, negative element
        self.minHeap = []    # large half
        self.n = 0
        
    def Insert(self, num):
        self.n += 1
        # odd n:  enlarge maxHeap(small half)
        # even n: enlarge minHeap(large half)
        if self.n == 1: 
            self.maxHeap.append(-num)
            return
        # this is an odd insertion, push num into maxHeap(small half), if num<=top of minHeap (min of the large half)
        # if num is large enough to be put in minHeap, then insert num to minHeap and insert the top of minHeap(large half) to maxHeap(small half)
        if self.n & 1: 
            if num <= self.minHeap[0]:
                heapq.heappush(self.maxHeap, -num)
            else:
                heapq.heappush(self.maxHeap, -self.minHeap[0])
                heapq.heapreplace(self.minHeap, num)
        else:
            if num + self.maxHeap[0] >= 0:
                heapq.heappush(self.minHeap, num)
            else:
                heapq.heappush(self.minHeap, -self.maxHeap[0])
                heapq.heapreplace(self.maxHeap, -num)
                
    def GetMedian(self):
        if self.n & 1:
            return -self.maxHeap[0]*1.0
        else: 
            return (self.minHeap[0]-self.maxHeap[0])/2.0

s = Solution()
a = [5,2,3,4,1,6,7,0,8]
for x in a:
    s.Insert(x)
    print(s.GetMedian())
