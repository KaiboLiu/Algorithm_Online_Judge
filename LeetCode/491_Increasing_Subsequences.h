//491_Increasing_Subsequences.h
//222ms	93.45%

/*
Total Accepted: 7241
Total Submissions: 18782
Instruction: LeetCode 491 - Increasing Subsequences - [M]
Developer: lrushx
Process Time: May 10, 2017
*/


/*
Given an integer array, your task is to find all the different possible increasing subsequences of the given array, and the length of an increasing subsequence should be at least 2 .

Example:
Input: [4, 6, 7, 7]
Output: [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7], [4,7,7]]
Note:
The length of the given array will not exceed 15.
The range of integer in the given array is [-100,100].
The given array may contain duplicates, and two equal integers should also be considered as a special case of increasing sequence.
*/


//给一个数组，输出所有长度>=2的非降子序列(可以不连续)
//DFS，并且用map来避免同一位置重复取数


    vector<vector<int>> res;
    void deeper(vector<int>& nums,vector<int>& seq,int pos,int n0,int n1){
        if (pos >= n0) return;
        int i;
        unordered_map<int,bool> m;
        for (i=pos;i<n0;i++){
            if (nums[i] >= seq[n1-1] && m[nums[i]] == false){
                m[nums[i]] = true;
                seq.push_back(nums[i]);
                res.push_back(seq);
                deeper(nums,seq,i+1,n0,n1+1);
                seq.pop_back();
            }
        }
        return;
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        int n0 = nums.size();
        if (n0 < 2) return res;
        int i,j;
        unordered_map <int,bool> m;
        for (i=0;i<n0-1;i++){
            if (m[nums[i]]) continue;
            m[nums[i]] = true;
            vector<int> seq(1,0);
            seq[0] = nums[i];
            deeper(nums,seq,i+1,n0,1);
        }
        return res;
    }