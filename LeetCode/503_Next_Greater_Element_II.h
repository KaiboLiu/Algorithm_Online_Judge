//503_Next_Greater_Element_II.h
//105ms	93.36%

/*
Total Accepted: 9218
Total Submissions: 19452
Instruction: LeetCode 503 - Next Greater Element II - [M]
Developer: lrushx
Process Time: Apr 29, 2017
*/


/*
Given a circular array (the next element of the last element is the first element of the array), print the Next Greater Number for every element. The Next Greater Number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, output -1 for this number.

Example 1:
Input: [1,2,1]
Output: [2,-1,2]
Explanation: The first 1's next greater number is 2; 
The number 2 can't find next greater number; 
The second 1's next greater number needs to search circularly, which is also 2.
*/


//给一个数组构成的环，求每个数字下一个(右侧最近)比其大的数，返回一个新数组，若没有更大返回-1
//参考496，用到了stack维护一个递降序列，遍历a0[i]，遇到比栈顶top更大的就更新结果map(m[stack.top]=a0[i])，然后出栈，入栈a0[i]。
//因为是环，所以要再遍历一次a0[i]，此轮无需再push
//因为数组元素可重复，所以stack存的是索引；第二轮遍历可以在最大值时停止



        stack<int> s;       // store the index with decrease oreder of value
        int len = nums.size(),maxi=0;
        vector<int> ans(len,-1);
        
        for (int i=0;i<len;i++){
            if (nums[i] > nums[maxi])   maxi = i;
            while (!s.empty() && nums[i] > nums[s.top()]){
                ans[s.top()] = nums[i];
                s.pop();
            }
            s.push(i);
        }
        for (int i=0;i<=maxi;i++){
            if (s.empty()) break;
            while (!s.empty() && nums[i] > nums[s.top()]){
                ans[s.top()] = nums[i];
                s.pop();
            }
            //s.push(i);
        }
        
        return ans;

    }