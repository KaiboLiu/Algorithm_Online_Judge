//397_Integer_Replacement.h
//0ms   100%

/*
Total Accepted: 17886
Total Submissions: 60322
Instruction: LeetCode 397 - Integer Replacement - [M]
Developer: lrushx
Process Time: May 05, 2017
*/


/*
Given a positive integer n and you can do operations as follow:

If n is even, replace n with n/2.
If n is odd, you can replace n with either n + 1 or n - 1.
What is the minimum number of replacements needed for n to become 1?

Example 1:

Input:
8

Output:
3

Explanation:
8 -> 4 -> 2 -> 1
*/

//给一个n，偶数时/2，奇数时+1或者-1，求最少多少次操作到1
//转成二进制后，当尾部是11时，+1可以更短(3本身除外)，其余奇数都-1


    int integerReplacement(int n) {
        if (n == INT_MAX) return 32;
        int res=0;
        while (n > 1){
            if ((n & 1) == 0) n = n >> 1;
            else if (n == 3) n--;
            else if ((n & 3) == 3) n++;
            else n--;
            res++;
        }
        return res;
    }