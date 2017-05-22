//594_Longest_Harmonious_Subsequence.h
//89ms
//LeetCode Contest 33


/*
Total Accepted: 1586
Total Submissions: 4662
Instruction: LeetCode 594 - Longest Harmonious Subsequence - [E]
Developer: lrushx
Process Time: May 20, 2017
*/


/*
We define a harmonious array is an array where the difference between its maximum value and its minimum value is exactly 1.

Now, given an integer array, you need to find the length of its longest harmonious subsequence among all its possible subsequences.

Example 1:
Input: [1,3,2,2,5,2,3,7]
Output: 5
Explanation: The longest harmonious subsequence is [3,2,2,2,3].
Note: The length of the input array will not exceed 20,000.
*/


//给一个数列，求其中最大最小差值正好为1的不连续子序列最大长度
//用unordered_map做hash table，给每个数列元素计数，然后遍历元素k，若k+1也存在，返回max(m[k]+m[k+1])
//注意题目设置，是最大最小插值正好为1而不是<=1，另外用m[k+1]如果k+1不是map的key会出问题，要用m.find(k)!=m.end()或者m.count(k+1)来判断
//遍历map可以用for (auto &x: m){} m.first来做

    int findLHS(vector<int>& nums) {
        unordered_map<int,int> m;
        int len = nums.size(),i,res=0,tmp;
        for (i = 0; i < len; i++){
            m[nums[i]]++;
	    }
	    unordered_map<int,int>::iterator it;
	    //cout<<m[1]<<m[2]<<endl;
	    for (it = m.begin();it!= m.end();it++){
	        if (m.find(it->first+1)!=m.end()){
	            tmp = m[it->first+1] + it->second;
	            //cout<<it->first<<" "<<(it->first)+1<<" "<<" "<<it->second<<" "<<tmp<<endl;
	            if (tmp > res) res = tmp;
	        }
	    }
	    return res;
        
    }
