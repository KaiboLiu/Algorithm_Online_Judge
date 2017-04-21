//377_Combination_Sum_IV.h
//0ms     100%

/*
Instruction: LeetCode 377 - Combination Sum IV - [M]
Developer: lrushx
Process Time: Apr 20, 2017
*/


/*
Given an integer array with all positive numbers and no duplicates, find the number of possible combinations that add up to a positive integer target.

Example:

nums = [1, 2, 3]
target = 4

The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)

Note that different sequences are counted as different combinations.

Therefore the output is 7.
*/

//给n个不重复数字，可重复地取出若干个，返回和为target的方案数（不同排列算不同方案）
//m循环内遍历i，dp[m]=sum{dp[m-a[i]]}
//和494很像，只是494是每个元素最多用一次，故而外循环是遍历数列内循环遍历和；此题因为元素可以重复使用，所以把便利数列元素放到内循环，而外循环是遍历和；
//注意每次循环的大小顺序，不要在同一轮内用更新的结果参与计算


    int combinationSum4(vector<int>& nums, int target) {
        if (nums.size() < 1) return 0;
        int dp[target+1] = {1}; //dp[0]=1, rest=0
        int minN = nums[0];
        for (int i=1;i<nums.size();i++)
            if (nums[i] < minN) minN = nums[i];
        for (int m=minN;m<=target;m++)
            for (int i=0;i<nums.size();i++)
            {
                if (m >= nums[i]) {
                    dp[m] += dp[m-nums[i]];
                }
            }
        return dp[target];
            
    }
