//312_Burst_Balloons.h
//9ms  93.66%

/*
Total Accepted: 24227
Total Submissions: 57431
Instruction: LeetCode 312 - Burst Balloons - [H]
Developer: lrushx
Process Time: Apr 20, 2017
*/
 
/*
Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented by array nums. You are asked to burst all the balloons. If the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins. Here left and right are adjacent indices of i. After the burst, the left and right then becomes adjacent.

Find the maximum coins you can collect by bursting the balloons wisely.

Note: 
(1) You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can not burst them.
(2) 0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100

Example:

Given [3, 1, 5, 8]

Return 167

    nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
   coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167
*/



//给n个数字作为气球标号，每次pop一个气球i，分数+a[i-1]*a[i]*a[i+1]，边界可各加1，求pop所有气球可以得到的最高分数
//High level DP!


    int maxCoins(vector<int>& nums) {
        int n = 0;
        n = nums.size();
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        //vector<vector<int> > dp(nums.size(), vector<int>(nums.size(), 0));
        int dp[n+2][n+2]={0};
        for (int len=1;len<=n;len++)
            for (int i=1;i<=n-len+1;i++){
                int j = i+len-1;
                for (int k=i;k<=j;k++)
                    dp[i][j] = max(dp[i][j],dp[i][k-1]+dp[k+1][j]+nums[i-1]*nums[k]*nums[j+1]);                
            }
        return dp[1][n];
    }
    
    
int main(){
    
    cout<<"312_Burst_Balloons:input numbers added to vector a[] until -100, as the balloons' value:"<<endl;

    vector<int> a;
    int i;
    cin>>i;
    while (i != -100){
        a.push_back(i);
        cin>>i;
    }
    for (i=0;i<a.size();i++) cout<<a[i]<<" ";
    //cout<<endl<<findTargetSumWays(a,S)<<endl;
    cout<<endl;
    cout<<maxCoins(a)<<endl;
    
        
        
}
