//575_Distribute_Candies.h
//

/*
Total Accepted: 1340
Total Submissions: 2123
Instruction: LeetCode 575 - Distribute Candies - [E]
Developer: lrushx
Process Time: May 06, 2017
*/


/*
Given an integer array with even length, where different numbers in this array represent different kinds of candies. Each number means one candy of the corresponding kind. You need to distribute these candies equally in number to brother and sister. Return the maximum number of kinds of candies the sister could gain.

Example 1:
Input: candies = [1,1,2,3]
Output: 2
Explanation: For example, the sister has candies [2,3] and the brother has candies [1,1]. 
The sister has two different kinds of candies, the brother has only one kind of candies. 
Note:

The length of the given array is in range [2, 10,000], and will be even.
The number in given array is in range [-100,000, 100,000].
*/


//LeetCode Contest 30
//给偶数个数字代表种类，分成2份使其中一份不同数字最多，返回这个最多种类
//简单贪心 用hash table统计每个数字出现次数c，返回min(c,n/2)即可


    int distributeCandies(vector<int>& candies) {
        unordered_map<int,int> m;
        int len = candies.size();
        int i,kind=0;
        for (i=0;i<len;i++){
            m[candies[i]]++;
            if (m[candies[i]] == 1) kind++;
        }
        return min(len/2,kind);
    }