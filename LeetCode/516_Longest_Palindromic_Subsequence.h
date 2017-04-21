//516_Longest_Palindromic_Subsequence.h
//55ms  81.55%

/*
Total Accepted: 7730
Total Submissions: 18337
Instruction: LeetCode 516 - Longest Palindromic Subsequence - [M]
Developer: lrushx
Process Time: Apr 20, 2017
*/


/*
Given a string s, find the longest palindromic subsequence's length in s. You may assume that the maximum length of s is 1000.

Example 1:
Input:

"bbbab"
Output:
4
One possible longest palindromic subsequence is "bbbb".
Example 2:
Input:

"cbbd"
Output:
2
One possible longest palindromic subsequence is "bb".
*/

//给一个字符串，求字串中回文的最长长度（可以不连续）
//dp[i][i]=1
//if s[i]==s[j]则dp[i][j]=dp[i+1][j-1]+2，否则dp[i][j]=max(dp[i+1][j],dp[i][j-1])



    int longestPalindromeSubseq(string s) {
        int n = s.length();
        if (n < 1) return 0;
        int dp[n][n] = {0};
        
        for (int i=0;i<n;i++) 
            dp[i][i] = 1;
        for (int len=2;len<=n;len++)
            for (int i=0;i<n-len+1;i++){
                int j = i+len-1;
                if (s[i] == s[j])
                    dp[i][j] = dp[i+1][j-1]+2;
                else dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
            }
        return dp[0][n-1];
    }
