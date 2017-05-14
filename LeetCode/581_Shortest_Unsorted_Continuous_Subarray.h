//581_Shortest_Unsorted_Continuous_Subarray.h
//36ms	100.00%
//LeetCode Contest 32

/*
Total Accepted: 1098
Total Submissions: 3989
Instruction: LeetCode 581 - Shortest Unsorted Continuous Subarray - [E]
Developer: lrushx
Process Time: May 13, 2017
*/


/*
Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order, too.
You need to find the shortest such subarray and output its length.

Example 1:
Input: [2, 6, 4, 8, 10, 9, 15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
Note:
Then length of the input array is in range [1, 10,000].
The input array may contain duplicates, so ascending order here means <=.
*/


//给一个数列，求从小到大排序的话需要交换的最小区间长度
//一种是直接排序，从头和尾查找第一个不一样的，就是区间的起止，复杂度O(nlog2n)，48ms
//另一种是从前往后记下max，如果有<max的就在前面用二分查找应该在的位置，更新区间头，最后更新区间尾，复杂度O(n)~O(nlog2n)，36ms


//solution1, O(n)~O(nlog2n)
//36ms

    int bisearch(vector<int>& nums,int a,int b,int k){
        int l=a,r=b,mid;
        while (l <= r){
            mid = (r-l)/2+l;
            if (nums[mid] > k) r = mid - 1;
            else l = mid + 1;
        }
        //if (r < 0) return 0;
        return r;
    }
    
    int findUnsortedSubarray(vector<int>& nums) {
        int len = nums.size();
        if (len == 1) return 0;
        int i=1,lefti=0,righti=0,Max;
        while (i < len && nums[i] >= nums[i-1]) i++;    //first nums[i] not ascending
        if (i == len) return 0;
        Max = nums[i-1];
        lefti = bisearch(nums,0,i-1,nums[i]);
        righti = i;
        for (;i<len;i++)
            if (nums[i] > Max) Max = nums[i];
            else if (nums[i] < Max) {
                righti = i;
                if (lefti > -1 && nums[i] < nums[lefti])
                    lefti = bisearch(nums,0,lefti,nums[i]);
            }
        //cout<<lefti<<" "<<righti<<endl;
        return righti-lefti;
    }
    
//solution2, sort first, then compare, ensured O(nlog2n)
//48ms

    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> n1 = nums;
        sort(n1.begin(),n1.end());
        int len = n1.size();
        int l=0,r=len-1;
        while (l < len && n1[l] == nums[l]) l++;
        if (l == len) return 0;
        while (r >= 0 && n1[r] == nums[r]) r--;
        return r-l+1;
    }
