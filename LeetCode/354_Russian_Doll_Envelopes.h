//354_Russian_Doll_Envelopes.h
//23ms	96.10%


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
//等价于按照第一个key排序后，求第二个key的最长递增子序列，有O(n2)和O(nlogn)的算法
//solution1, 346ms	28.12%
//最初的想法比较简单，用O(n2)的DP，先按照key1排序，然后遍历i时，把j从0~i-1遍历，找到宽更小并且DP值最大的j，更新到DP[i]，最后+1.
//solution2, 23ms	96.10%
//DP+二分。先根据key1排序，相等时key2降序。使用DP[l]表示满足条件的序列的长度为l时，储存最小key２的信封。
//遍历第i个信封时，在DP中二分查找pos，找到第一个>=a[i].second的pos更新为a[i]的值，若这个pos>l并且这个a[i]满足长宽都>DP最后一个，则DP长度+1

//成绩是2个集中分布，我一开始在慢的一个大区间中，大家用的是O(n2)346ms/28.12%，另一个快很多的区间是O(nlogn)
//第二天琢磨了很久，用了LIS中的二分方法，再综合这道题的很多细节，终于完成O(nlogn)，做到23ms/96.10%
//觉得自己很吊


//solution1, O(n2)DP like LIS
//346ms	28.12%
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
    
//solution2, O(nlogn)DP like LIS
//23ms	96.10%
    static bool mysort(pair<int, int>& a, pair<int, int>& b){ 
        if (a.first == b.first) return a.second>b.second;
        else return a.first<b.first;
    }
    
    int bisearch(pair<int, int>* d,int a,int b,int key){    // find the first element that >= key
        if (d[b].second <= key) return b+1;
        int l=a,r=b,mid;
        while (l <= r){
            mid = (r - l)/2 + l;
            if (d[mid].second < key) l = mid + 1;
            else r = mid - 1;
        }
        return l;    
    }
    
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        int len = envelopes.size();
        if (len < 2) return len;
        sort(envelopes.begin(),envelopes.end(),mysort);
        int i,res=1,pos;
        //cout<<endl<<endl; for (i=0;i<len;i++) cout<<"["<<envelopes[i].first<<","<<envelopes[i].second<<"]"; cout<<endl;
        pair<int, int> f[len];
        f[0] = envelopes[0];
        for (i=1;i<len;i++){
            pos = bisearch(f,0,res-1,envelopes[i].second);
            if (pos == res && envelopes[i].second > f[res-1].second && envelopes[i].first > f[res-1].first) f[res++] = envelopes[i];
            if (pos < res ) f[pos] = envelopes[i];
            //for (int j=0;j<res;j++) cout<<"["<<f[j].first<<","<<f[j].second<<"]"; cout<<endl;
        }
        return res;        
    }