//462_Minimum_Moves_to_Equal_Array_Elements_II.h
//16ms	96.26%

/*
Total Accepted: 12953
Total Submissions: 25292
Instruction: LeetCode 462 - Minimum Moves to Equal Array Elements II - [E]
Developer: lrushx
Process Time: May 03, 2017
*/

/*
Given a non-empty integer array, find the minimum number of moves required to make all array elements equal, where a move is incrementing a selected element by 1 or decrementing a selected element by 1.
You may assume the array's length is at most 10,000.
Input:
[1,2,3]
Output:
2
Explanation:
Only two moves are needed (remember each move increments or decrements one element):
[1,2,3]  =>  [2,2,3]  =>  [2,2,2]
*/


//给一个数组，每次操作给其中一个数+1或-1，求需要多少次操作使得所有元素相等
//通过数学分析，和平均数无关，只需要中位数，因为此时<=median和>median的数相等，中位数+1或者-1会使得两边数量不等从而总次数更多
//这里的中位数，直接a[n/2]即可，无需判断奇偶，很神奇


    int minMoves2(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) return 0;
        sort(nums.begin(),nums.end());
        int i,ans=0,median = nums[len/2];
        
        for (i=0;i<len;i++) ans += abs(nums[i] - median);
        return ans;
    }
