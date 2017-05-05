//455_Assign_Cookies.h
//43ms	79.15%

/*
Total Accepted: 22444
Total Submissions: 47570
Instruction: LeetCode 455 - Assign Cookies - [E]
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

//给一组g[i]和s[i]，返回最大的g[i]数量满足配对s[j]>=g[i](s[j]只能用一次)
//排序后贪心即可

    int findContentChildren(vector<int>& g, vector<int>& s) {
        int ng = g.size(),ns = s.size(),i,j=0,res=0;
        if (ng == 0 || ns == 0) return 0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        
        for (i=0;i<ng;i++){
            while (j < ns && s[j] < g[i]) j++;
            if (j < ns) res++;
            else break;
            j++;
        }
        return res;
        
    }