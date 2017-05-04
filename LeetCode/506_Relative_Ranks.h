//506_Relative_Ranks.h
//13ms	85.52%

/*
Total Accepted: 12836
Total Submissions: 27109
Instruction: LeetCode 506 - Relative Ranks - [E]
Developer: lrushx
Process Time: May 03, 2017
*/


/*
Given scores of N athletes, find their relative ranks and the people with the top three highest scores, who will be awarded medals: "Gold Medal", "Silver Medal" and "Bronze Medal".

Example 1:
Input: [5, 4, 3, 2, 1]
Output: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
Explanation: The first three athletes got the top three highest scores, so they got "Gold Medal", "Silver Medal" and "Bronze Medal". 
For the left two athletes, you just need to output their relative ranks according to their scores.
*/

//给一个数组，表示n个队员的分数(都不相同)，返回他们的排名(顺序不变)，并且前三名是特殊输出
//排序，然后用map存数据原来的位置
//用了map，还复制一个新数组用于排序确定排名

    vector<string> findRelativeRanks(vector<int>& nums) {

        int len = nums.size(),i;
        vector<int> ori_num = nums;
        vector<string> ans(len,"");
        sort(nums.begin(),nums.end());
        unordered_map<int,string> m;
        string medal[3] = {"Gold Medal","Silver Medal","Bronze Medal"};
        for (i=0;i<min(3,len);i++) m[nums[len-1-i]] = medal[i];
        for (i=3;i<len;i++) m[nums[len-1-i]] = to_string(i+1);
        
        for (i=0;i<len;i++) ans[i] = m[ori_num[i]];
        return ans;
    }