//583_Delete_Operation_for_Two_Strings.h
//25ms	100.00%
//LeetCode Contest 32

/*
Total Accepted: 624
Total Submissions: 1626
Instruction: LeetCode 583 - Delete Operation for Two Strings - [M]
Developer: lrushx
Process Time: May 13, 2017
*/


/*
Given two words word1 and word2, find the minimum number of steps required to make word1 and word2 the same, where in each step you can delete one character in either string.

Example 1:
Input: "sea", "eat"
Output: 2
Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".
Note:
The length of given words won't exceed 500.
Characters in given words can only be lower-case letters.
*/


//给2个字符串，求共删除多少个字符可以让2个串相等
//O(mn)的DP, f[i][j]表示长为i的s和长为j的t需要删除多少个才能相等，初始化很重要，f[i][0]=f[0][i]=i，然后遍历i,j，若s[i-1]==t[j-1]则f[i][j]=f[i-1][j-1]否则f[i][j]=min(f[i-1][j],f[i][j-1])+1


    int minDistance(string word1, string word2) {
        int len1 = word1.size();
        int len2 = word2.size();
        int f[len1+1][len2+1] = {};
        int i,j;
        f[0][0] = 0;
        for (i = 1;i<=len2;i++) f[0][i] = i;
        for (i = 1;i<=len1;i++) f[i][0] = i;
        for (i = 1;i<=len1;i++)
            for (j = 1;j<=len2;j++)
                if (word2[j-1] == word1[i-1]) f[i][j] = f[i-1][j-1];
                else f[i][j] = min(f[i-1][j],f[i][j-1])+1;
        return f[len1][len2];
    }
