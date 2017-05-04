//453_Minimum_Moves_to_Equal_Array_Elements.h
//49ms	99.66%

/*
Total Accepted: 22722
Total Submissions: 4853
Instruction: LeetCode 453 - Minimum Moves to Equal Array Elements - [E]
Developer: lrushx
Process Time: May 03, 2017
*/


/*
Given a non-empty integer array of size n, find the minimum number of moves required to make all array elements equal, where a move is incrementing n - 1 elements by 1.
Input:
[1,2,3]
Output:
3

[1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]
*/


//给一个数组个数为n，每次操作给n-1个数+1，求需要多少次操作使得所有元素相等
//假设答案为k，则k次都需要给最小数+1，得min+k==[(n-1)k+sum] / n，最后k=sum-n*min


    int minMoves(vector<int>& nums) {
        int len = nums.size();
        if (len < 2) return 0;
        int i,sum=0,Min=nums[0];
        
        for (i=0;i<len;i++){
            sum += nums[i];
            if (nums[i] < Min) Min = nums[i];
        }
        return sum-len*Min;
        
    }