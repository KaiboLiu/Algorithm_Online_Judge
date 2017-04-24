//376_Wiggle_Subsequence.h
//0ms 100%

/*
Total Accepted: 20883
Total Submissions: 59467
Instruction: LeetCode 376 - Wiggle Subsequence - [M]
Developer: lrushx
Process Time: Apr 23, 2017
*/


/*
A sequence of numbers is called a wiggle sequence if the differences between successive numbers strictly alternate between positive and negative. The first difference (if one exists) may be either positive or negative. A sequence with fewer than two elements is trivially a wiggle sequence.
For example, [1,7,4,9,2,5] is a wiggle sequence because the differences (6,-3,5,-7,3) are alternately positive and negative. In contrast, [1,4,7,2,5] and [1,7,4,5,5] are not wiggle sequences, the first because its first two differences are positive and the second because its last difference is zero.
Given a sequence of integers, return the length of the longest subsequence that is a wiggle sequence. A subsequence is obtained by deleting some number of elements (eventually, also zero) from the original sequence, leaving the remaining elements in their original order.

Examples:
Input: [1,7,4,9,2,5]
Output: 6
The entire sequence is a wiggle sequence.

Input: [1,17,5,10,13,15,10,5,16,8]
Output: 7
There are several subsequences that achieve this length. One is [1,17,10,13,10,16,8].

Input: [1,2,3,4,5,6,7,8,9]
Output: 2
*/


//给一个数组，求其中大小交错的子串(可以不相邻)的最大长度	
//DP，复杂度O(n^2)或者贪心O(n)

    int wiggleMaxLength(vector<int>& nums) {
        int l = nums.size();
        if (l < 1) return 0;
        int rise=1,drop=1,i;
        for (i = 1;i<l;i++)
            if (nums[i] > nums[i-1]) rise =  drop + 1;
            else if (nums[i] < nums[i-1]) drop = rise + 1;
        return max(rise,drop);
    }
