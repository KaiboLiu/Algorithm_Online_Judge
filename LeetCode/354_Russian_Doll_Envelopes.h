//354_Russian_Doll_Envelopes.h
//346ms	28.12%

/*
Total Accepted: 18648
Total Submissions: 58317
Instruction: LeetCode 354 - Russian Doll Envelopes - [H]
Developer: lrushx
Process Time: May 17, 2017
*/


/*
You have a number of envelopes with widths and heights given as a pair of integers (w, h). One envelope can fit into another if and only if both the width and height of one envelope is greater than the width and height of the other envelope.
What is the maximum number of envelopes can you Russian doll? (put one inside other)
Example:
Given envelopes = [[5,4],[6,4],[6,7],[2,3]], the maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).
*/

//俄罗斯套娃的信封版，给n个信封的长宽，必须长宽都小于才能装入另一个信封，求最多能套多少个
//最初的想法比较简单，用O(n2)的DP，先按照长排序，然后遍历i时，把j从0~i-1遍历，找到宽更小并且DP值最大的j，更新到DP[i]，最后+1.
//成绩分布是2个集中分布，我在慢的一个大区间中，大家用的是O(n2)，另一个块很多的区间应该是O(nlogn)


    static bool mysort(pair<int, int>& a, pair<int, int>& b){ return a.first<b.first;   }
    
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        int len = envelopes.size();
        if (len < 2) return len;
        sort(envelopes.begin(),envelopes.end(),mysort);
        int i,j,f[len] = {1},res=0;
        for (i=1;i<len;i++){
            f[i] = 0;
            for (j=0; j<i; j++)
                if (envelopes[j].first < envelopes[i].first && envelopes[j].second < envelopes[i].second && f[j] > f[i]) f[i] = f[j];
            f[i]++;
            res = res > f[i]? res : f[i];
        }
        return res;
        
    }