//539_Minimum_Time_Difference.h
//16ms	93.71%

/*
Total Accepted: 5601
Total Submissions: 12309
Instruction: LeetCode 539 - Minimum Time Difference - [M]
Developer: lrushx
Process Time: May 09, 2017
*/


/*
Given a list of 24-hour clock time points in "Hour:Minutes" format, find the minimum minutes difference between any two time points in the list.

Example 1:
Input: ["23:59","00:00"]
Output: 1
Note:
The number of time points in the given list is at least 2 and won't exceed 20000.
The input time is legal and ranges from 00:00 to 23:59.
*/

//给一些24小时制的时间表示字符串，找出最小分钟数差
//每个时间转成分钟，存入hash table中，然后从小到大遍历计算相邻差，最后比较下头尾差，更新结果


    int findMinDifference(vector<string>& timePoints) {
        int len = timePoints.size();
        std::map <int,int> m1;
        int i,h,m,res=720;
        for (i=0;i<len;i++){
            h = (timePoints[i][0]-'0')*10+timePoints[i][1]-'0';
            m = (timePoints[i][3]-'0')*10+timePoints[i][4]-'0';
            h = h*60+m;
            m1[h]++;
            if (m1[h] > 1) return 0;
        }
        
        std::map <int,int>::iterator it;
        it = m1.begin();
        i = it->first;
        it++;
        for (;it!=m1.end();it++){
            if (it->first - i < res) 
                res = it->first - i;
            i = it->first;
        }
        if (m1.begin()->first - m1.rbegin()->first < res - 1440)
            res = m1.begin()->first - m1.rbegin()->first + 1440;
        return res;
    }