//322_Coin_Change.h
//19ms	97.05%

/*
Total Accepted: 56045
Total Submissions: 213797
Instruction: LeetCode 322 - Coin Change - [M]
Developer: lrushx
Process Time: May 01, 2017
*/


/*
You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

Example 1:
coins = [1, 2, 5], amount = 11
return 3 (11 = 5 + 5 + 1)

Example 2:
coins = [2], amount = 3
return -1.
*/

//给一个数组和一个数n，数组中的数可以取无限次，求取数和为n需要最少取多少个数
//dp数组索引为和，值为取数最小个数，按照和s遍历，dp[s]=min{dp[s-a[i]]}+1 (for all i, if dp[s-a[i]]>=0)，初始时dp[]=-1,dp[0]=0
//给的数组如果不排序，就不要认为排序从而通过len--来排除处理大数
//DP一定要多想想转移方程和索引范围、初始状态


    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        vector<int> dp(amount+1,-1);
        int len = coins.size(),i,j,n_best;
        int min_coin = *std::min_element(coins.begin(),coins.end());
        for (i = 0;i < len;i++) 
            if (coins[i] == amount) return 1;
        dp[0] = 0;
        for (i = min_coin;i <= amount;i++){
            n_best = INT_MAX;
            for (j = 0;j < len;j++)
                if (i >= coins[j] && dp[i-coins[j]] >= 0 && dp[i-coins[j]] < n_best)
                    n_best = dp[i-coins[j]];
            if (n_best < INT_MAX) dp[i] = n_best + 1;
        }
        return dp[amount];
    }