//526_Beautiful_Arrangement.h
//13ms	74.68%

/*
Total Accepted: 7182
Total Submissions: 13255
Instruction: LeetCode 526 - Beautiful Arrangement - [M]
Developer: lrushx
Process Time: Apr 30, 2017
*/


/*
Suppose you have N integers from 1 to N. We define a beautiful arrangement as an array that is constructed by these N numbers successfully if one of the following is true for the ith position (1 ≤ i ≤ N) in this array:
The number at the ith position is divisible by i.
i is divisible by the number at the ith position.
Now given N, how many beautiful arrangements can you construct?

Input: 2    Output: 2
Explanation: 
The first beautiful arrangement is [1, 2]:
The second beautiful arrangement is [2, 1]:
*/


//给一个n，求1..n有多少种排列，使得位置和对应数字之间可以整除
//像八皇后问题一样回溯

    int ans = 0;
    void dfs(vector<bool>& visited,int k,int n){
        if (k == 0){
            ans++;
            return;
        }
        for (int i=1;i<=n;i++){
            if (visited[i] || (i % k != 0 && k % i != 0)) 
                continue;
            visited[i] = true;
            dfs(visited,k-1,n);
            visited[i] = false;
        }
        return;
    }
    
    int countArrangement(int N) {
        //bool visited[N+1];
        //memset(visited,0,(N+1)*sizeof(bool));
        vector<bool> visited(N+1,false);
        dfs(visited,N,N);
        return ans;
    }