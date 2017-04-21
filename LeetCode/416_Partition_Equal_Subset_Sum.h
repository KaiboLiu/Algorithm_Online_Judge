//416_Partition_Equal_Subset_Sum.h
//22ms  82.74%

/*
Total Accepted: 18252
Total Submissions: 47362
Instruction: LeetCode 416 - Partition Equal Subset Sum - [M]
Developer: lrushx
Process Time: Apr 20, 2017
*/


/*
Given a non-empty array containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

Note:
Each of the array element will not exceed 100.
The array size will not exceed 200.
Example 1:

Input: [1, 5, 11, 5]

Output: true

Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:

Input: [1, 2, 3, 5]

Output: false

Explanation: The array cannot be partitioned into equal sum subsets.
*/

//给一组正数，判断是否可以分成2组，各组的和相等。
//等价于判断数列中不重复取若干数，和是否可以为sum/2，方法同494，只是从计数简化为bool。
//外循环是和m（一定要从大到小，否则同一轮内更新的结果会参与计算），内循环是i
//dp[m] = dp[m] || dp[m-nums[i]];


    bool canPartition(vector<int>& nums) {
        int sums = 0;
        int n = nums.size();
        if (n == 1) return false;
        
        for (int i=0;i<n;i++)
            sums += nums[i];
        if ((sums & 1) == 1) return false;
        
        sums = sums / 2;
        bool dp[sums+1] = {1};
        for (int i=0;i<n;i++)
            for (int m=sums;m>=nums[i];m--)
                dp[m] = dp[m] || dp[m-nums[i]];
        return dp[sums];
    }
