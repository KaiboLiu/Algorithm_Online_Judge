# 295_Find_Median_from_Data_Stream.py
# 152ms	91.01%

'''
Total Accepted: 38960
Total Submissions: 154956
Instruction: LeetCode 295 - Find Median from Data Stream - [H]
Developer: lrushx
Process Time: Apr 10, 2018
'''


'''
Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.
[2,3,4] , the median is 3
[2,3], the median is (2 + 3) / 2 = 2.5

Design a data structure that supports the following two operations:
void addNum(int num) - Add a integer number from the data stream to the data structure.
double findMedian() - Return the median of all elements so far.
For example:

addNum(1)
addNum(2)
findMedian() -> 1.5
addNum(3) 
findMedian() -> 2
'''


# 写一个数据结构，支持添加数据元素和查找median
# 基本存储类型用vector，添加时用二分查找后插入，求median就可以直接出结果了
# 二分要记住，不要每次举例子来验证 while条件是<=，a[mid]<num时l=mid+1否则r=mid-1，返回的是l
# 通过率25.1%的H

# solution2:
# 与c++不同的方法：用small half和large half存数，前者用最大堆(负值heapq)找到最大值，后者用最小堆(heapq)找最小值，对应的就是当前数组的中间2个数
# 插入第奇数个num时，原则上直接插到small half中，但若num比large half的最小值大，则需要插入到large half中，并且把large half的最小值转到small half中。
# 插入第偶数个num时，原则上直接插到large half中，但若num比small half的最大值小，则需要插入到small half中，并且把small half的最大值转到large half中。
# 直接100%

class MedianFinder:

    def __init__(self):
        self.maxHeap = []    # small half, negative element
        self.minHeap = []    # large half
        self.n = 0
        

    def addNum(self, num):
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
        

    def findMedian(self):
        if self.n & 1:
            return -self.maxHeap[0]*1.0
        else:
            return (self.minHeap[0]-self.maxHeap[0])/2
        


# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()
