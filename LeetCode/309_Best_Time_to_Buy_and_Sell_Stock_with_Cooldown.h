//309_Best_Time_to_Buy_and_Sell_Stock_with_Cooldown.h
//6ms	91.61%

/*
Total Accepted: 39401
Total Submissions: 97939
Instruction: LeetCode 309 - Best Time to Buy and Sell Stock with Cooldown - [M]
Developer: lrushx
Process Time: May 22, 2017
*/


/*
Say you have an array for which the ith element is the price of a given stock on day i.
Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
Example:
prices = [1, 2, 3, 0, 2]
maxProfit = 3
transactions = [buy, sell, cooldown, buy, sell]
*/

//给每日股价，可以买卖无数次（必须买卖交替，卖之后必须空一天才能买），求最大利润
//buy[i]和sell[i]表示买或者卖第i天股票的收益，buy[i] = max{sell[0~i-2]-a[i]}，sell[i] = max{buy[0~i-1]+a[i]}
//加2个数组储存sell和buy的当前最大值，避免搜索最大，从72ms到6ms


    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len < 2) return 0;
        int buy[len] = {0}, sell[len] = {0}, maxs[len]={0},maxb[len]={0};
        int i,res;
        maxb[0] = buy[0] = -prices[0];
        buy[1] = -prices[1];
        maxb[1] = max(buy[1],buy[0]);
        res = sell[1] = maxs[1] = prices[1] + buy[0];
        
        for (i = 2; i < len; i++){

            buy[i] =  max(0,maxs[i-2]) - prices[i];
            sell[i] = maxb[i-1] + prices[i];
            maxb[i] = max(maxb[i-1],buy[i]);
            maxs[i] = max(maxs[i-1],sell[i]);
            res = max(res,sell[i]);
        }
        return max(res,0);
    }
