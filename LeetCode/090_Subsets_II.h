//090_Subsets_II.h
//6ms	100.00%

/*
Total Accepted: 106231
Total Submissions: 301208
Instruction: LeetCode 090 - Subsets II - [M]
Developer: lrushx
Process Time: May 19, 2017
*/


/*
Given a collection of integers that might contain duplicates, nums, return all possible subsets.
Note: The solution set must not contain duplicate subsets.
For example,
If nums = [1,2,2], a solution is:
[  [2],  [1],  [1,2,2],  [2,2],  [1,2],  []   ]
*/


//给一个元素可重复的数组，求所有不重复升序子集
//回溯，子集不能重复。当前DFS中开始下标为i0，子串sub长为pos，从i0到最后遍历i，依次把a[i]加到sub的第pos位中，继续回溯下一轮(sub,i+1)。但是本轮遍历i时，有重复的要跳过。
//修改全局变量比传参数快


    vector<vector<int>> res;
    vector<int> sub;
    
    void DFS(vector<int>& nums, int i0, int len, int pos){
        res.push_back(sub);
        if (i0 >= len) return;
        sub.push_back(0);
        for (int i=i0;i<len;i++){
            while (i > i0 && i < len && nums[i] == nums[i-1]) i++;  if (i == len) break;
            sub[pos] = nums[i];
            DFS(nums,i+1,len,pos+1);
        }
        sub.pop_back();
        return;
    }
    
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int len = nums.size(),i;
        //if (len == 0) {res.push_back(nums) return res;}
        sort(nums.begin(),nums.end());
        //vector<int> sub;
        DFS(nums,0,len,0);
        return res;
    }