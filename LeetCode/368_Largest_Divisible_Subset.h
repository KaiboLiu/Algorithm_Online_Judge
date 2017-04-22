//368_Largest_Divisible_Subset.h
//26ms  99.12%


/*
Total Accepted: 21866
Total Submissions: 65181
Instruction: LeetCode 368 - Largest Divisible Subset - [M]
Developer: lrushx
Process Time: Apr 21, 2017
*/


/*
Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies: Si % Sj = 0 or Sj % Si = 0.
If there are multiple solutions, return any subset is fine.

Example 1:
nums: [1,2,3]
Result: [1,2] (of course, [1,3] will also be ok)
Example 2:
nums: [1,2,4,8]
Result: [1,2,4,8]
*/

//给一组不重复的数，求最长子序列的任意方案，使得其中任意2个都可以整除。
//因为不重复，于是可以先排序；且两两都为倍数，则选出来的序列中，若i<j<k，则必定有j%i==0,k%j==0且k%i==0，所以不必考虑i，k之间的关系，只需判断选出来的相邻元素之间是否有倍数关系即可。
//dp[k] = dp[i] + 1, if (nums[k] % nums[i] == 0 && (dp[i]+1) > dp[k]), 同时记录prev[k]=i作为k若被选出来的前一个元素，便于输出详细方案；
//剪枝是，在k循环中遍历i时，若nums[i]>nums[k]/2则停止遍历，因为(a/2,a)之间不可能有a的因子。此剪枝从49ms到26ms，百分比从21.57%提升到99.12%。



    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int l = nums.size();
        vector<int> ans;
        if (l == 0) return ans;
        sort(nums.begin(),nums.end());
        
        int dp[l] = {0};
        int prev[l] = {0};
        
        for (int i=0;i<l;i++){
            dp[i] = 1;
            prev[i] = -1;            
        }
        for (int k=0;k<l;k++)
            for (int i=0;i<k;i++){
                if (nums[k] < nums[i]*2) break;
                if (nums[k] % nums[i] == 0 && (dp[i]+1) > dp[k]){
                    dp[k] = dp[i] + 1;
                    prev[k] = i;
                }
            }
        
        int k=0;
        for (int i=1;i<l;i++)
            if (dp[i] > dp[k]) k = i;
        ans.push_back(nums[k]);
        while (prev[k]>=0){
            ans.insert(ans.begin(),nums[prev[k]]);
            k = prev[k];
        }
        return ans;
    }
