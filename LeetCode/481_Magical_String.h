//481_Magical_String.h
//3ms	100.00%

/*
Total Accepted: 6920
Total Submissions: 15315
Instruction: LeetCode 481 - Magical String - [M]
Developer: lrushx
Process Time: May 06, 2017
*/


/*
A magical string S consists of only '1' and '2' and obeys the following rules:
The string S is magical because concatenating the number of contiguous occurrences of characters '1' and '2' generates the string S itself.
The first few elements of string S is the following: S = "1221121221221121122……"
If we group the consecutive '1's and '2's in S, it will be:
1 22 11 2 1 22 1 22 11 2 11 22 ......
and the occurrences of '1's or '2's in each group are:
1 2	2 1 1 2 1 2 2 1 2 2 ......
You can see that the occurrence sequence above is the S itself.
Given an integer N as input, return the number of '1's in the first N number in the magical string S.
Note: N will not exceed 100,000.

Example 1:
Input: 6
Output: 3
Explanation: The first 6 elements of magical string S is "12211" and it contains three 1's, so return 3.
*/


//一个字符串1221121...用次数代表连续1或者2的个数，给个n，求前n位中1的个数
//有了122后可以自己生成，类似宽搜，原串位置i，生成的尾为j，根据i处的1或者2在j处生成1或者2个数，这个数会根据1/2交替，最后数一下就好



    int magicalString(int n) {
        if (n == 0) return 0;
        if (n < 4) return 1;
        unsigned s[n+1];
        int i=2,j=2,token=1,res=1;
        s[0] = 1; s[1] = 2;s[2] = 2;
        while (j < n-1){
            if (s[i] == 1) {
                if (token == 1) res ++;
                s[++j] = token;
            }
            else if (s[i] == 2){
                if (token == 1) res += 2;
                s[++j] = token;
                s[++j] = token;
            }
            i++;
            token = 3 - token;
        }
        if (j == n && s[n] == 1) res--;
        return res;
    }

