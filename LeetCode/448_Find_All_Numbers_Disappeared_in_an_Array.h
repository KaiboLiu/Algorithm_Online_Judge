//448_Find_All_Numbers_Disappeared_in_an_Array.h
//135ms	78.74%

/*
Total Accepted: 39312
Total Submissions: 74944
Instruction: LeetCode 448 - Find All Numbers Disappeared in an Array - [E]
Developer: lrushx
Process Time: Apr 28, 2017
*/


/*
Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.
Find all the elements of [1, n] inclusive that do not appear in this array.
Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

Input:[4,3,2,7,8,2,3,1]
Output:[5,6]
*/

//给一个长度为n的数列，元素范围[1,n]，有重复的和出现单次的，用O(1)空间和O(n)时间找出所有缺失的数
//a[i]-1介于原数下标组范围内，则可递增i，在不相等时交换a[i]和a[a[i]-1]，相等时i++。最后再遍历一次，a[i-1]!=i的i加入答案


    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int len = nums.size();
        vector<int> ans;
        int i=0;
        if (len < 2) return ans;
        while (i < len){
            if (nums[i] != nums[nums[i]-1])
                swap(nums[i],nums[nums[i]-1]);
            else i++;
        }
        for (i=1;i<=len;i++)
            if (nums[i-1] != i) ans.push_back(i);
        return ans;
    }