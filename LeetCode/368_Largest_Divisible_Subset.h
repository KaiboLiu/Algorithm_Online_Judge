//368_Largest_Divisible_Subset.h


    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int l = nums.size();
        int dp[l] = {0};
        int prev[l] = {0};
        for (int i=0;i<l;i++){
            dp[i] = 1;
            prev[i] = -1;            
        }
        for (int k=0;k<l;k++)
            for (int i=0;i<k;i++)
                if (nums[k] % nums[i] == 0 || (dp[i]+1)>dp[k]){
                    dp[k] = dp[i] + 1;
                    prev[k] = i;                    
                }
        vector<int> ans;
        int k
        for (int i=0;i<l;i++)
    }