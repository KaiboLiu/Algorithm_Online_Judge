//347_Top_K_Frequent_Elements.h
//19ms	99.64%

/*
Total Accepted: 58454
Total Submissions: 123574
Instruction: LeetCode 347 - Top K Frequent Elements - [M]
Developer: lrushx
Process Time: May 04, 2017
*/


/*
Given a non-empty array of integers, return the k most frequent elements.
For example,
Given [1,1,1,2,2,3] and k = 2, return [1,2].

Note: 
You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
*/

//给一个数组，输出出现次数前k次的元素
//用map构建hash table映射数->频次，然后用priority_queue依次压入(频次,数)，然后取出k个second就好
//priority_queue可以常数时间返回最大值，对数时间插入，类似295



    vector<int> topKFrequent(vector<int>& nums, int k) {
        //int len = nums.size();
        vector<int> ans(k,0);
        //if (len == 0) return ans;
        int i,c=0;
        unordered_map <int,int> m;
        for (auto k:nums) m[k]++;
        
        priority_queue<pair<int,int>> pq;
        i = m.size() - k;
        
        for (auto it=m.begin();it!=m.end();it++)
            pq.push(make_pair(it->second,it->first));
        while (pq.size() > i){
            ans[c++] = pq.top().second;
            pq.pop();
        }
        
        return ans;
        
    }