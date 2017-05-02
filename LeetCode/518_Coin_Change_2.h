//518_Coin_Change_2.h
//3ms	100.00%

/*
Total Accepted: 3484
Total Submissions: 11453
Instruction: LeetCode 518 - Coin Change 2 - [M]
Developer: lrushx
Process Time: May 01, 2017
*/


/*
You are given coins of different denominations and a total amount of money. Write a function to compute the number of combinations that make up that amount. You may assume that you have infinite number of each kind of coin.

Note: You can assume that

0 <= amount <= 5000
1 <= coin <= 5000
the number of coins is less than 500
the answer is guaranteed to fit into signed 32-bit integer
Example 1:

Input: amount = 5, coins = [1, 2, 5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
*/

//给一个数组和一个数n，数组中的数可以取无限次，求取数和为n的方案数(相同数换位不算)
//DP，不是按和0..n遍历，而是先遍历数组a[i]，再遍历和dp[sum]+=dp[sum-a[i]];
//无限背包问题，但是不是求最大值而是方案数，稍微改动一点就好

    int change(int amount, vector<int>& coins) {
        if (amount == 0) return 1;
        vector<int> dp(amount+1,0);
        int n_coin = coins.size();
        if (n_coin < 1) return 0;
        int i,j;
        dp[0] = 1;
        while (n_coin >0 && coins[n_coin-1] > amount) n_coin--;
        for (i = 0;i < n_coin;i++){
            for (j = coins[i];j <= amount;j++)
                dp[j]+= dp[j-coins[i]];
        }
        return dp[amount];
            
    }