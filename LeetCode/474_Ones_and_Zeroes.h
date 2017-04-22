//474_Ones_and_Zeroes.h
//49ms     92.84%

/*
Total Accepted: 8391
Total Submissions: 22312
Instruction: LeetCode 474 - Ones and Zeroes - [M]
Developer: lrushx
Process Time: Apr 21, 2017
*/


/*
Suppose you are a dominator of m 0s and n 1s respectively. On the other hand, there is an array with strings consisting of only 0s and 1s.

Now your task is to find the maximum number of strings that you can form with given m 0s and n 1s. Each 0 and 1 can be used at most once.

Note:
The given numbers of 0s and 1s will both not exceed 100
The size of given string array won't exceed 600.
Example 1:
Input: Array = {"10", "0001", "111001", "1", "0"}, m = 5, n = 3
Output: 4

Explanation: This are totally 4 strings can be formed by the using of 5 0s and 3 1s, which are “10,”0001”,”1”,”0”
Example 2:
Input: Array = {"10", "0", "1"}, m = 1, n = 1
Output: 2

Explanation: You could form "10", but then you'd have nothing left. Better form "0" and "1".
*/

//给一组二进制字符串和m、n，取若干个字符串，使得'0'个数为m，'1'个数为n，求满足条件取法中字符串最多的个数。
//dp，用dp[i][j]表示组成i个0和j个1需要的最多字符串个数，遍历字符串数组，当前字符串中zeros个0，ones个1，则
//dp[i][j] = max(dp[i][j],dp[i-zeros][j-ones]+1);
//非常奇怪：初始化int dp[m+1][n+1]={0}，竟然dp[0][1]并没有初始化，为32767。以前都没出现过。只好加上memset(dp,0,(m+1)*(n+1)*sizeof(int));

    int findMaxForm(vector<string>& strs, int m, int n) {
        int l = strs.size();
        if (l < 1) return 0;
        
        int dp[m+1][n+1] = {0};
        memset(dp,0,(m+1)*(n+1)*sizeof(int));
        for (int k=0;k<l;k++){
            int ones=0,zeros;
            for (int i=0;i<strs[k].size();i++)
                ones += strs[k][i]-'0';
            zeros = strs[k].size()-ones;
        
            for (int i=m;i>=zeros;i--)
                for (int j=n;j>=ones;j--){
                    //cout<<k<<' '<<i<<' '<<j<<':'<<dp[i][j]<<' '<<dp[i-zeros][j-ones]<<endl;
                    dp[i][j] = max(dp[i][j],dp[i-zeros][j-ones]+1);
                    //cout<<'f'<<i<<j<<'='<<f[i][j]<<endl;
                }
        }
        return dp[m][n];
    }