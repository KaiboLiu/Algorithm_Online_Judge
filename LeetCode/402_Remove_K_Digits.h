//402_Remove_K_Digits.h
//6ms	76.64%

/*
Total Accepted: 18502
Total Submissions: 70839
Instruction: LeetCode 402 - Remove K Digits - [M]
Developer: lrushx
Process Time: June 17, 2017
*/

/*
Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.

Note:
The length of num is less than 10002 and will be ≥ k.
The given num does not contain any leading zero.
Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
Example 2:

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
Example 3:

Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.
*/

//给一个字符串作为高精度整数，删除k位后返回最小的答案
//贪心，从左往右找i，若i位>i+1位则删除i位，否则删除最后一位。删除一位后判断首位为0的情况，删除所有首位0。可以在最后加一个"0"简化操作。



    string removeKdigits(string num, int k) {
        int i,i0=0;
        num += "0";
        while (k){
            if (num.size()-1 <= k) return "0";
            for (i=i0;i<num.size()-1;i++)
                if (num[i] > num[i+1]){
                    i0 = max(0,i-1);
                    num.erase(i,1);
                    while (num.size() > 1 && num[0] == '0')
                        num.erase(0,1);
                    break;
                }
            k--;
        }
        num.pop_back();
        return num.empty()? "0" : num;
        //return num.size()>1? num.substr(0,num.size()-1) : "0";
    }
