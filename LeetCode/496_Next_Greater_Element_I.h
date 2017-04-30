//496_Next_Greater_Element_I.h
//9ms	100.00%

/*
Total Accepted: 20432
Total Submissions: 35468
Instruction: LeetCode 496 - Next Greater Element I - [E]
Developer: lrushx
Process Time: Apr 29, 2017
*/


/*
You are given two arrays (without duplicates) nums1 and nums2 where nums1’s elements are subset of nums2. Find all the next greater numbers for nums1's elements in the corresponding places of nums2.

The Next Greater Number of a number x in nums1 is the first greater number to its right in nums2. If it does not exist, output -1 for this number.

Example 1:
Input: nums1 = [4,1,2], nums2 = [1,3,4,2].
Output: [-1,3,-1]
Explanation:
    For number 4 in the first array, you cannot find the next greater number for it in the second array, so output -1.
    For number 1 in the first array, the next greater number for it in the second array is 3.
    For number 2 in the first array, there is no next greater number for it in the second array, so output -1.
Note:
All elements in nums1 and nums2 are unique.
The length of both nums1 and nums2 would not exceed 1000.
*/


//给一个不重复元素的数组a0，其中任意元素组合的数组a1，求每a1元素在a0位置中，下一个(右侧最近的)更大的数，若没有更大返回-1
//用到了stack维护一个递降序列，遍历a0[i]，遇到比栈顶top更大的就更新结果map(m[stack.top]=a0[i])，然后出栈，入栈a0[i]。
//因为数组元素不重复，所以stack可存数组元素
//用for(i : nums) 即可遍历元素而无需索引，像python的for in

    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        stack<int> s;
        unordered_map<int,int> m;
        for (int a : nums){
            while (s.size() && s.top()<a){
                m[s.top()] = a; // s.top()'s next greater number is a;
                s.pop();
            }
            s.push(a);
        }
        vector<int> ans;
        for (int a : findNums) ans.push_back(m.count(a)? m[a] : -1);
        return ans;
        
    }