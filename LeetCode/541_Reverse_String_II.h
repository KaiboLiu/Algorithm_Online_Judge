//541_Reverse_String_II.h
//6ms	100.00%

/*
Total Accepted: 11049
Total Submissions: 17877
Instruction: LeetCode 541 - Reverse String II - [E]
Developer: lrushx
Process Time: Apr 25, 2017
*/


/*
Given a string and an integer k, you need to reverse the first k characters for every 2k characters counting from the start of the string. If there are less than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and left the other as original.
Example:
Input: s = "abcdefg", k = 2
Output: "bacdfeg"
*/

//给一个字符串和，只有字母没有空格，再给个k，反转第0~k-1,2k-1~3k-1,..区间内的字符。
//用while语句即可，p1,p2表示需要反转区间的起止，最后再判断下若p1<len && p2 >=len，要把剩下全部反转。
//不要生成ans字符串，复制原串再替换所需更快。



    string reverseStr(string s, int k) {
        int len = s.size(),tmp,k2 = k+k;
        string ans=s;
        unsigned p1=0,p2=k-1;
        while (p2 < len){
            tmp = p1 + p2;
            for (int i=p1;i<=p2;i++) ans[tmp-i] = s[i];
            p1 += k2;
            p2 += k2;
        }
        if (p1 < len){
            tmp = len + p1 - 1;
            for (int i=p1;i<len;i++) ans[tmp-i] = s[i];
        } 
        return ans;
    }
