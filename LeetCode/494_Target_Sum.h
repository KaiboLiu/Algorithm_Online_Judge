//494_Target_Sum.h
//[DFS] 282ms   32.71%
//[DP1] 9ms     75.83%
//[DP2] 3ms     100%

/*
Instruction: LeetCode 494 - Target Sum - [M]
Developer: lrushx
Process Time: Apr 14, 2017 [DFS]
              Apr 19, 2017 [DP]
*/


/*
You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.

Find out how many ways to assign symbols to make sum of integers equal to target S.

Example 1:
Input: nums is [1, 1, 1, 1, 1], S is 3. 
Output: 5
Explanation: 

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

There are 5 ways to assign symbols to make the sum of nums be target 3.
Note:
The length of the given array is positive and will not exceed 20.
The sum of elements in the given array will not exceed 1000.
Your output answer is guaranteed to be fitted in a 32-bit integer.
*/

//给一组非负数，和一个target，求若干数字加负号后全部求和=target的方案数。(+0和-0视为不同)
//先是DFS回溯，倒也能做，282ms，剪枝用处不大；
//再是DP1，因为数字和最大10000，使得和状态的遍历成为可能，转移方程f[s,k]=f[m-a[k]]+f[m+a[k]]。为了避免溢出，用加法代替减法。结果9ms。
//最后是DP2，把加上-号的数字标为N，其余为P。sum(P)-sum(N)=target => sum(p)=(sum+target)/2。可以DP在所有数中选择要或者不要加入P中，结果3ms。


/*
//DFS, 282ms   32.71%
    int DFS(vector<int>& nums, vector<int>& sum, int pos,int l,int S){
        if (pos == l-1){
            if (nums[pos] == S || nums[pos] == -S)
                if (S == 0) return 2;
                else return 1;
            else return 0;
        }
        if (pos > 0){
            int subsum = sum[l-1]-nums[pos];
            if (subsum < S || subsum < -S) return 0;
        }
        if (nums[pos] ==0) return 2*DFS(nums,sum,pos+1,l,S);
        return DFS(nums,sum,pos+1,l,S-nums[pos])+DFS(nums,sum,pos+1,l,S+nums[pos]);
        
    }
    int findTargetSumWays(vector<int>& nums, int S) {
        if (nums.size() == 0) return 0;
        vector<int> sum=nums;
        for (int i=1;i<sum.size();i++) sum[i] += sum[i-1];
        return DFS(nums,sum,0,nums.size(),S);
    }
    
//DP1, 9ms     75.83% 
    int findTargetSumWays(vector<int>& nums, int S) {
        vector<int> s=nums;
        int l = nums.size();
        for (int i=1;i<l;i++) s[i] += s[i-1];
        if (S > s[l-1] || -S > s[l-1]) return 0;
        int f[2*s[l-1]+1]={0};
        int g[2*s[l-1]+1]={0};
        f[s[l-1]-nums[0]]++;
        f[s[l-1]+nums[0]]++;
        for (int k=1;k<l;k++){
            for (int m=s[l-1]-s[k-1];m<=s[l-1]+s[k-1];m++){//[-s[k]~s[k]] + s[l-1]
                g[m-nums[k]] += f[m];
                g[m+nums[k]] += f[m];
            }

            memcpy(f,g,(s[l-1]+s[l-1]+1)*sizeof(int));
            memset(g,0,(s[l-1]+s[l-1]+1)*sizeof(int));
 
        }
        return f[S+s[l-1]];
    }
*/
//DP2, 3ms     100%  
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = 0,target;
        int l = nums.size();
        for (int i=0;i<l;i++) sum += nums[i];
        if (S > sum || -S > sum) return 0;
        if (S > 0) target = sum-S;
        else target = sum+S;
        if (target & 1 == 1) return 0;
        target = target / 2;
        int f[target+1]={0};
        f[0] = 1;
        for (int k=0;k<l;k++){
            for (int m=target;m>=nums[k];m--)
                f[m] += f[m-nums[k]];
            }
        return f[target];        
        
    }
    
    
int main(){
    
    cout<<"494_Target_Sum:input numbers added to vector a[] until -100"<<endl;

    vector<int> a;
    int i,S;
    cin>>i;
    while (i != -100){
        a.push_back(i);
        cin>>i;
    }
    cout<<"input the target integer:";
    cin>>S;
    for (i=0;i<a.size();i++) cout<<a[i]<<" ";
    //cout<<endl<<findTargetSumWays(a,S)<<endl;
    cout<<endl;
    cout<<DP2(a,S)<<endl;
    
        
        
}
