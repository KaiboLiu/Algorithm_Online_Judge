//398_Random_Pick_Index.h
//88ms	96.61%

/*
Total Accepted: 19021
Total Submissions: 45331
Instruction: LeetCode 398 - Random Pick Index - [M]
Developer: lrushx
Process Time: May 30, 2017
*/

/*
Given an array of integers with possible duplicates, randomly output the index of a given target number. You can assume that the given target number must exist in the array.
Note:
The array size can be very large. Solution that uses too much extra space will not pass the judge.
Example:
int[] nums = new int[] {1,2,3,3,3};
Solution solution = new Solution(nums);
// pick(3) should return either index 2, 3, or 4 randomly. Each index should have equal probability of returning.
solution.pick(3);
// pick(1) should return 0. Since in the array only nums[0] is equal to 1.
solution.pick(1);
*/

//给一个数列a，内容可重复，再多次调用pick(t)函数，等概率地返回t在a中的索引，要求不能用多余space
//一开始就想到了蓄水池抽样法，但是想用hash表先试试，存元素对应的所有索引map<int,vector>，这样虽然快并且没有增加元素个数，但是多了好多个vector，在无意识下会增加space开销，导致MLE；
//之后就乖乖用蓄水池了


/*
private:
    unordered_map<int,vector<int>> m;
public:
//map<int, vector> is too big for space, even input is [1,2,3,3,3]

    Solution(vector<int> nums) {
        m.clear();
        vector<int> v;
        int len = nums.size();
        for (int i=0;i<len;i++){
            if (m.find(nums[i]) == m.end()) m[nums[i]] = v;
            m[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) {
        int len = m[target].size();
        return m[target][rand() % len];
    }
    
};
*/
private:
    vector<int> v;
    int len;
public:

    Solution(vector<int> nums) {
        v = nums;
        len = nums.size();
    }
    
    int pick(int target) {
        int res=0,count=0;
        for (int i=0;i<len;i++)
            if (v[i] == target){
                res = rand()%(++count)? res : i;
            }
        return res;
    }