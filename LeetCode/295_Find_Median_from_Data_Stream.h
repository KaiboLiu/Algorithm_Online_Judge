//295_Find_Median_from_Data_Stream.h
//152ms	91.01%

/*
Total Accepted: 38960
Total Submissions: 154956
Instruction: LeetCode 295 - Find Median from Data Stream - [H]
Developer: lrushx
Process Time: May 01, 2017
*/


/*
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
*/


//写一个数据结构，支持添加数据元素和查找median
//基本存储类型用vector，添加时用二分查找后插入，求median就可以直接出结果了
//二分要记住，不要每次举例子来验证 while条件是<=，a[mid]<num时l=mid+1否则r=mid-1，返回的是l
//通过率25.1%的H



class MedianFinder {
public:
    vector<int> array;
    /** initialize your data structure here. */
    MedianFinder() {
        //vector<int> a;
        //array = a;
    }
    
    void addNum(int num) {
        int l=0,r=array.size()-1,mid;
        while (l <= r){
            mid = (r-l)/2+l;
            if (num > array[mid]) l = mid + 1;
            else r = mid - 1;
        }
        l;
        array.insert(array.begin()+l,num);
    }
    
    double findMedian() {
        int len = array.size();
        int k = len / 2;
        if (len & 1 == 1) return array[k];
        else return (array[k]+array[k-1])/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */