//452_Minimum_Number_of_Arrows_to_Burst_Balloons.h
//92ms	77.51%

/*
Total Accepted: 10739
Total Submissions: 24717
Instruction: LeetCode 452 - Minimum Number of Arrows to Burst Balloons - [M]
Developer: lrushx
Process Time: May 16, 2017
*/


/*
There are a number of spherical balloons spread in two-dimensional space. For each balloon, provided input is the start and end coordinates of the horizontal diameter. Since it's horizontal, y-coordinates don't matter and hence the x-coordinates of start and end of the diameter suffice. Start is always smaller than end. There will be at most 104 balloons.
An arrow can be shot up exactly vertically from different points along the x-axis. A balloon with xstart and xend bursts by an arrow shot at x if xstart ≤ x ≤ xend. There is no limit to the number of arrows that can be shot. An arrow once shot keeps travelling up infinitely. The problem is to find the minimum number of arrows that must be shot to burst all balloons.
Example:
Input:
[[10,16], [2,8], [1,6], [7,12]]
Output:2
Explanation:
One way is to shoot one arrow for example at x = 6 (bursting the balloons [2,8] and [1,6]) and another arrow at x = 11 (bursting the other two balloons).
*/


//给若干个区间，求多少个坐标点可以碰到所有区间
//贪心，先按尾坐标排序，相等时按头坐标排
//每次的坐标点按照尾坐标设置，若当前区间的头坐标>现有坐标点，则坐标点更新为新的尾，并且答案++

/*再次总结cmp:
1、static bool mysort(pair<int, int>& a, pair<int, int>& b){ return a.second<b.second;   }
2、struct myclass {   
    bool operator() (const pair<int, int>& i,const pair<int, int>& j) { 
        return i.second < j.second; }  
    } mycmp;
工作安排之类的包含起止位置的区间排序：先按尾排序，相等时按头排
*/



    struct myclass {
        bool operator() (const pair<int, int>& i,const pair<int, int>& j) { 
            return (i.second == j.second ? i.first < j.first : i.second < j.second);
        }
    } mycmp;
    
    
    int findMinArrowShots(vector<pair<int, int>>& points) {
        int len = points.size();
        //if (len < 2) return len;
        int i=0,res=0,arrow=INT_MIN;
        sort(points.begin(),points.end(),mycmp);
        //for (int k=0;k<len;k++) cout<<"["<<points[k].first<<","<<points[k].second<<"] "; cout<<endl;
        for (i=0; i<len; i++){
            if (arrow != INT_MIN && points[i].first <= arrow) continue;     // former arrow shot points[i] 
            arrow = points[i].second;           // new arrow shot the end of points[i]
            res++;
        }
        return res;
        
        
    }