//553_Optimal_Division.h
//3ms	97.07%

/*
Total Accepted: 2565
Total Submissions: 4776
Instruction: LeetCode 553 - Optimal Division - [M]
Developer: lrushx
Process Time: Apr 29, 2017
*/


/*
Given a list of positive integers, the adjacent integers will perform the float division. For example, [2,3,4] -> 2 / 3 / 4.
However, you can add any number of parenthesis at any position to change the priority of operations. You should find out how to add parenthesis to get the maximum result, and return the corresponding expression in string format. Your expression should NOT contain redundant parenthesis.

Example:
Input: [1000,100,10,2]
Output: "1000/(100/10/2)"
Explanation:
1000/(100/10/2) = 1000/((100/10)/2) = 200
However, the bold parenthesis in "1000/((100/10)/2)" are redundant, 
since they don't influence the operation priority. So you should return "1000/(100/10/2)". 
*/


//给n个数中间全加除号，求加上括号的方案使得结果最大，输出表达式字符串
//第一个必须是被除数；又因为全是integer，相除必定越来越小，而要让结果最大，只要第二个到最后一个的结果最小，只要连除即可，注意n为2和1的额外情况
//应该算是easy吧。。。


    string optimalDivision(vector<int>& nums) {
        int len = nums.size();  // garanteed >= 1
        string ans = to_string(nums[0]);
        if (len == 2) ans += "/" + to_string(nums[1]);
        else if (len > 2){
            ans += "/(" + to_string(nums[1]);
            for (int i=2;i<len;i++)
                ans += "/" + to_string(nums[i]);
            ans += ")";
        }
        return ans;
    }