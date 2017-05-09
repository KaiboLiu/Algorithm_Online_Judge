//384_Shuffle an_Array.h
//242ms	71.65%

/*
Total Accepted: 23205
Total Submissions: 50498
Instruction: LeetCode 384 - Shuffle an Array - [M]
Developer: lrushx
Process Time: May 06, 2017
*/


/*
Shuffle a set of numbers without duplicates.
Example:

// Init an array with set 1, 2, and 3.
int[] nums = {1,2,3};
Solution solution = new Solution(nums);

// Shuffle the array [1,2,3] and return its result. Any permutation of [1,2,3] must equally likely to be returned.
solution.shuffle();

// Resets the array back to its original configuration [1,2,3].
solution.reset();

// Returns the random shuffling of array [1,2,3].
solution.shuffle();
*/


//实现一个类，包含新建数组，重排数组，恢复数组
//创造一个类内全局变量储存原数组，至于重排，可以用i遍历元素，rand()%len得到j，然后交换i,j元素即可。


class Solution {
public:
    vector<int> origin;
    Solution(vector<int> nums) {
        origin = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return origin;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> res = origin;
        int i,j,len=origin.size();
        for (int i=0;i<len;i++){
            j = rand() % len;
            swap(res[i],res[j]);
        }
        return res;
            
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */