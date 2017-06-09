//330_Patching_Array.h
//6ms	100.00%

/*
Total Accepted: 21169
Total Submissions: 66604
Instruction: LeetCode 330 - Patching Array - [H]
Developer: lrushx
Process Time: June 08, 2017
*/

/*
Given a sorted positive integer array nums and an integer n, add/patch elements to the array such that any number in range [1, n] inclusive can be formed by the sum of some elements in the array. Return the minimum number of patches required.

Example 1:
nums = [1, 3], n = 6
Return 1.

Combinations of nums are [1], [3], [1,3], which form possible sums of: 1, 3, 4.
Now if we add/patch 2 to nums, the combinations are: [1], [2], [3], [1,3], [2,3], [1,2,3].
Possible sums are 1, 2, 3, 4, 5, 6, which now covers the range [1, 6].
So we only need 1 patch.

Example 2:
nums = [1, 5, 10], n = 20
Return 2.
The two patches can be [2, 4].

Example 3:
nums = [1, 2, 2], n = 5
Return 0.
*/

//给一组排序数组num和数字n，求需要加几个数到数组中，可以使1..n均能被数组中元素求和表示
//假设现在已经可以表示[1,miss)，用到num[i]，若num[i]<=miss则加上num[i]可以表示到[1,num[i]+miss)，否则num[i]没用，必须要添一个miss，使得答案数+1
//非常巧妙的方法，一开始用dict会超时

    int minPatches(vector<int>& nums, int n) {
        int len = nums.size(),count = 0;
        long miss = 1,i = 0;
        while (miss <=n){
            if (i < len && nums[i] <= miss)
                miss += nums[i++];
            else{
                count++;
                miss += miss;
            }
        }
        return count;
    }
