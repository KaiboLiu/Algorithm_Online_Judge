//447_Number_of_Boomerangs.h
//159ms	98.74%

/*
Total Accepted: 19043
Total Submissions: 43135
Instruction: LeetCode 445 - Add Two Numbers II - [E]
Developer: lrushx
Process Time: May 08, 2017
*/


/*
Given n points in the plane that are all pairwise distinct, a "boomerang" is a tuple of points (i, j, k) such that the distance between i and j equals the distance between i and k (the order of the tuple matters).
Find the number of boomerangs. You may assume that n will be at most 500 and coordinates of points are all in the range [-10000, 10000] (inclusive).

Example:
Input:
[[0,0],[1,0],[2,0]]
Output:
2
Explanation:
The two boomerangs are [[1,0],[0,0],[2,0]] and [[1,0],[2,0],[0,0]]
*/


//给n个坐标，找到(i,j,k)使得ij和ik距离相等，交换jk又算另一个方案，求总方案
//遍历i，然后遍历j，每次将ij距离放入hash table中计数，此轮i中计数k>2的，则答案+k(k-1)
//map.clear()比新建快很多；这个单词叫回形镳

    int dist(pair<int, int> a, pair<int, int> b){
        int i=a.first-b.first,j=a.second-b.second;
        return i*i+j*j;
    }
    
    
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int len = points.size();
        if (len < 3) return 0;
        int i,j,res=0;
        unordered_map <int,int> m;
        unordered_map <int,int>::iterator it;
        for (i=0;i<len;i++){
            m.clear();
            for (j=0;j<len;j++)
                m[dist(points[i],points[j])]++;
            for (it=m.begin();it!=m.end();it++)
                if (it->second > 1) 
                    res += it->second * (it->second - 1);
        }
        return res;
    }
