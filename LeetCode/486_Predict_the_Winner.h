//LeetCode - 486_Predict_the_Winner.h
//0ms  100%

/*
Instruction: LeetCode 486 - Predict the Winner - [M]
Developer: lrushx
Process Time: Apr 14, 2017
*/
 
/*
Total Accepted: 7944
Total Submissions: 17915

Given an array of scores that are non-negative integers. Player 1 picks one of the numbers from either end of the array followed by the player 2 and then player 1 and so on. Each time a player picks a number, that number will not be available for the next player. This continues until all the scores have been chosen. The player with the maximum score wins.

Given an array of scores, predict whether player 1 is the winner. You can assume each player plays to maximize his score.

Example 1:
Input: [1, 5, 2]
Output: False
Explanation: Initially, player 1 can choose between 1 and 2. 
If he chooses 2 (or 1), then player 2 can choose from 1 (or 2) and 5. If player 2 chooses 5, then player 1 will be left with 1 (or 2). 
So, final score of player 1 is 1 + 2 = 3, and player 2 is 5. 
Hence, player 1 will never be the winner and you need to return False.
Example 2:
Input: [1, 5, 233, 7]
Output: True
Explanation: Player 1 first chooses 1. Then player 2 have to choose between 5 and 7. No matter which number player 2 choose, player 1 can choose 233.
Finally, player 1 has more score (234) than player 2 (12), so you need to return True representing player1 can win.
*/

//给一串数字，两人博弈，分别从两端取数，和大者胜。判断先手者是否能赢。
//用DP，用f[i,j]表示此区间数列中1号玩家先手可以获得的最多分数，
//状态转移方程f[i,j]=sum[i,j]-min(f[i+1,j],f[i,j-1])，最后比较2f[0,l-1]和sum[0,l-1]，>=则赢。


    bool PredictTheWinner(vector<int>& nums) {
        int l=nums.size();
        if (l <= 2) return true;
        vector<int> s = nums;
        vector<vector<int> > f(l,vector<int>(l,0)); 
        f[0][0] = nums[0];
        for (int i=1;i<l;i++) {
            f[i][i] = nums[i];
            s[i] += s[i-1];
        }
        for (int d=1;d<l;d++)
            for (int i=0;i<l-d;i++){
                int sum = s[i+d];
                if (i > 0) sum -= s[i-1];
                f[i][i+d] = sum - min(f[i+1][i+d],f[i][i+d-1]);            
            }
        if (2*f[0][l-1] >= s[l-1]) return true;
        else return false;
    }


int main(){
    
    cout<<"486_Predict_the_Winner: input arr"<<endl;
    vector<int> a;
    a.push_back(1);
    a.push_back(5);
    a.push_back(2);
    
    cout<<PredictTheWinner(a)<<endl;
        
    }
}
    