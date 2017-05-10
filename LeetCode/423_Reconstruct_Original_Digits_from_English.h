//423_Reconstruct_Original_Digits_from_English.h
//19ms	99.62%

/*
Total Accepted: 9172
Total Submissions: 21228
Instruction: LeetCode 423 - Reconstruct Original Digits from English - [M]
Developer: lrushx
Process Time: May 09, 2017
*/


/*
Given a non-empty string containing an out-of-order English representation of digits 0-9, output the digits in ascending order.

Note:
Input contains only lowercase English letters.
Input is guaranteed to be valid and can be transformed to its original digits. That means invalid inputs such as "abc" or "zerone" are not permitted.
Input length is less than 50,000.
Example 1:
Input: "owoztneoer"

Output: "012"
Example 2:
Input: "fviefuro"

Output: "45"
*/



//给一些字符串，可以重排成one,one,two,five之类，输出对应的数字字符
//每个数字对应的单词写出来，找单独的和组合的，列线性方程，分别求出0-9的个数



    string originalDigits(string s) {
        vector<int> m(26,0);
        vector<int> c(10,0);
        int len = s.size(),i,j;
        string res,tmp;
        for (i=0;i<len;i++) m[s[i]-'a']++;
        c[0] = m[25];       //'z'
        c[2] = m['w'-'a'];  //'w'
        c[6] = m['x'-'a'];  //'x'
        c[8] = m['g'-'a'];  //'g'
        c[7] = m['s'-'a'] - c[6];
        c[5] = m['v'-'a'] - c[7];
        c[3] = m['h'-'a'] - c[8];
        c[9] = m['i'-'a'] - c[6] -c[8] -c[5];
        c[4] = m['r'-'a'] - c[0] -c[3];
        c[1] = m['n'-'a'] - c[7] -c[9]-c[9];
        for (i=0;i<10;i++)
            if (c[i]) {
                tmp = to_string(i);
                for (j=0;j<c[i];j++) res += tmp;
            }
        return res;
    }