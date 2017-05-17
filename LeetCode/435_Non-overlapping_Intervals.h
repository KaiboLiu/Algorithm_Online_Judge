//435_Non-overlapping_Intervals.h
//9ms	95.51%

/*
Total Accepted: 10889
Total Submissions: 26964
Instruction: LeetCode 435 - Non-overlapping Intervals - [M]
Developer: lrushx
Process Time: May 16, 2017
*/


/*
Given a collection of intervals, find the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.
Note:You may assume the interval's end point is always bigger than its start point.
Intervals like [1,2] and [2,3] have borders "touching" but they don't overlap each other.
Example 1:
Input: [ [1,2], [2,3], [3,4], [1,3] ]
Output: 1
Explanation: [1,3] can be removed and the rest of intervals are non-overlapping.
Example 2:
Input: [ [1,2], [1,2], [1,2] ]
Output: 2
Explanation: You need to remove two [1,2] to make the rest of intervals non-overlapping.
Example 3:
Input: [ [1,2], [2,3] ]
Output: 0
Explanation: You don't need to remove any of the intervals since they're already non-overlapping.
*/




//给若干个区间，求至少删除多少个区间可以使剩下的都不重叠(可以相邻)
//贪心，先按首坐标排序，设pre为0，然后i从1往后，若i的首坐标<pre的尾坐标，则有重叠，答案++，然后把尾坐标小的更新给pre；
//若i的首坐标>=pre的尾坐标，则直接更新pre为i即可	贪心/Greedy	
//比452简单些，只用按照一侧排序，然后删除重叠并且尾坐标大的



/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        auto comp = [](const Interval& i1, const Interval& i2){ return i1.start < i2.start; };
        sort(intervals.begin(),intervals.end(),comp);
        
        int pre=0,i,res=0,len=intervals.size();
        for (i=1;i<len;i++)
            if (intervals[i].start < intervals[pre].end){
                res++;
                if (intervals[i].end < intervals[pre].end) pre = i;
            } else pre = i;
        return res;
    }