//016_3Sum_Closest.h
//9ms	88.83%

/*
Total Accepted: 122206
Total Submissions: 397065
Instruction: LeetCode 016 - 3Sum Closest - [M]
Developer: lrushx
Process Time: Apr 27, 2017
*/


/*
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.
    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

//给一个数组，和一个目标值t，求数组中任取3个数的和，使其最接近t
//O(n^2)，先排序，然后用i遍历数组，确定第1个数，然后第2，3个数用j=i+1,k=last表示，
//用while语句把j和k往中间靠，若i,j,k对应和更优，则更新答案；若和比t大，则k--，否则j++。
//注意数组元素<3的情况，直接加


    int threeSumClosest(vector<int>& nums, int target) {
        int len = nums.size(),i,ans=0;
        if (len < 3) {
            for (i = 0;i < len;i++) ans += nums[i]; 
            return ans;
        }
        sort(nums.begin(),nums.end());
        ans = nums[0]+nums[1]+nums[2];
        int j,k,sum;
        for (i = 0;i<len-2;i++){
            j = i + 1;
            k = len - 1;
            while (j < k){
                sum = nums[i] + nums[j] + nums[k];
                if (abs(target-sum) < abs(target-ans)){
                    ans = sum;
                    if (target == ans) return ans;
                }
                if (sum > target) k--;
                else j++;
            }
        }
        return ans;
    }
