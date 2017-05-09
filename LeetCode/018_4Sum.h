//018_4Sum.h
//12ms	99.17%

/*
Total Accepted: 112977
Total Submissions: 429939
Instruction: LeetCode 018 - 4Sum - [M]
Developer: lrushx
Process Time: May 08, 2017
*/


/*
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.
Note: The solution set must not contain duplicate quadruplets.
For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.
A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
*/


//给一个数组和一个t，找出所有不重复的4数组合，使得4数和为t
//先排序，然后i从0~n-4，j从i+1~n-3，k=j+1，l=n-1，让k和l往中间找，他们的和如果<t-a[i]-a[j]则k++否则l--。
//因为不能重复，所以每个索引不能找重复的值，当出现重复要用while语句继续向后找。并且，在一组i,j下可能有多组k,l成立，所以在k,l找到之后要继续k++,l--并且判断重复后继续找更中间的满足条件的数队，最后复杂度O(n^3).
//答案提示hash table，但我没有用，复杂度O(n^3)，成绩也不错，终于解决了一直逃避的一道题。
//虽然是暴搜，但是用了一些小trick降了一维复杂度。



    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int len = nums.size();
        if (len < 4) return res;
        sort(nums.begin(),nums.end());
        int i,j,k,l,s;
        for (i=0;i<len-3;i++){
            if (i > 0 && nums[i] == nums[i-1]) continue;
            for (j=i+1;j<len-2;j++) {
                if (j > i+1 && nums[j] == nums[j-1]) continue;
                k = j+1;
                l = len-1;
                s = target - (nums[i]+nums[j]);
                if (nums[k]+nums[k+1] > s || nums[l]+nums[l-1] < s) continue;
                while (k < l){
                    while (k < l && nums[k]+nums[l] !=s){
                        while (nums[k]+nums[l] > s) l--;
                        while (nums[k]+nums[l] < s) k++;
                    }
                    if (k < l){
                        vector<int> tmp(4,0);
                        tmp[0] = nums[i];
                        tmp[1] = nums[j];
                        tmp[2] = nums[k];
                        tmp[3] = nums[l];
                        res.push_back(tmp);
                        k++; l--;
                        while (k < len-2 && nums[k] == nums[k-1]) k++;
                        if (k == len-2) break;
                        while (l > k && nums[l] == nums[l+1]) l--;
                        //if (l == k) break;
                    }
                }
            }
        }
        return res;
        
    }
