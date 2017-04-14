//LeetCode - 152_Maximum_Product_Subarray.h
//4ms	100%

/**
 * Instruction：LeetCode 152 - Maximum Product Subarray - [M]
 * Developer：lrushx
 * Process Time：Sep 08, 2015
 */
 
/*
Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.
*/


//求数组中连续子串的积的最大值
//DP，用currMin和currMax储存当前最大值最小值，每次乘以当前元素，和本元素比较后更新这两个数，再更新答案
//比较巧妙的DP，不需要数组来暂存



class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int len = nums.size(),ans;
        if (len == 1) return nums[0];
        int currmax,currmin,tmp1,tmp2;
        
        ans = currmin = currmax = nums[0];

        for (int i=1;i<len;i++){
            tmp1 = currmin * nums[i];
            tmp2 = currmax * nums[i];
            
            if (tmp1 > tmp2) swap(tmp1,tmp2);

            currmin = min(nums[i],tmp1);
            currmax = max(nums[i],tmp2);
            
            ans = max(ans,currmax);
        }
    
        return ans;
        
    }
};
