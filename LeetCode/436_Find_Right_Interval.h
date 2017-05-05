//436_Find_Right_Interval.h
//89ms	82.56%

/*
Total Accepted: 9847
Total Submissions: 23891
Instruction: LeetCode 436 - Find Right Interval - [M]
Developer: lrushx
Process Time: May 04, 2017
*/


/*
iven a set of intervals, for each of the interval i, check if there exists an interval j whose start point is bigger than or equal to the end point of the interval i, which can be called that j is on the "right" of i.
For any interval i, you need to store the minimum interval j's index, which means that the interval j has the minimum start point to build the "right" relationship for interval i. If the interval j doesn't exist, store -1 for the interval i. Finally, you need output the stored value of each interval as an array.

Note:
You may assume the interval's end point is always bigger than its start point.
You may assume none of these intervals have the same start point.
Input: [ [3,4], [2,3], [1,2] ]
Output: [-1, 0, 1]
*/

//给若干区间，按原顺序返回每个区间右边最近的不相交区间的左边界
//方法一：按照左区间排序后每个右区间Interval[i].right用二分法查找其他右区间找到满足Interval[k].left>=Interval[i].right的最小k
//可是重构cmp函数出现问题，研究后终于解决
//方法二：map.lower_bound(a)返回的是满足k>=a的最小map索引k(而不是值)，把left作为map的key，原来位置作为map的值，这样就能得到想要的最小key了

//map.lower_bound(a) 学了新用法
//终于弄清楚了自定义cmp的写法，记得用const



//solution1: customized sort + binary search, 92ms
    struct myclass {
        bool operator() (const Interval& i,const Interval& j) { return (i.start < j.start);}
    } mycmp;
    
    vector<int> findRightInterval(vector<Interval>& intervals) {

        int i,l,r,mid,len=intervals.size();
        unordered_map<int,int> m;
        for (i=0;i<len;i++) m[intervals[i].start] = i;
        
        vector<int> res(len,-1);
        sort(intervals.begin(),intervals.end(),mycmp);
        
        //for (auto c:intervals) cout<<"["<<c.start<<","<<c.end<<"]"; cout<<endl;
        
        for (i=0;i<len-1;i++){
            l = i+1;
            r = len-1;
            while (l <= r){
                mid = (r-l)/2+l;
                if (intervals[mid].start < intervals[i].end) l = mid+1;
                else r = mid-1;
            }
            if (l == len) continue;
            res[m[intervals[i].start]] = m[intervals[l].start];
        }
        return res;
    }
    
    
    

//solution2: map.lower_bound(v) returns the minimum key that >= v, 89ms

    vector<int> findRightInterval(vector<Interval>& intervals) {

        int i,l,r,mid,len=intervals.size();
        map<int,int> map;
        for (i=0;i<len;i++) map[intervals[i].start] = i;
        
        vector<int> res(len,-1);
        for (i=0;i<len;i++){
            auto it = map.lower_bound(intervals[i].end);
            if (it == map.end()) continue;
            res[i] = it->second;
        }
        return res;
    }