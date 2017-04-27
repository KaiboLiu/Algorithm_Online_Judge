//375_Guess_Number_Higher_or_Lower_II.h
//13ms     78.32%

/*
Total Accepted: 18655
Total Submissions: 52462
Instruction: LeetCode 375 - Guess Number Higher or Lower II - [M]
Developer: lrushx
Process Time: Apr 25, 2017
*/


/*
We are playing the Guess Game. The game is as follows:
I pick a number from 1 to n. You have to guess which number I picked.
Every time you guess wrong, I'll tell you whether the number I picked is higher or lower.
However, when you guess a particular number x, and you guess wrong, you pay $x. You win the game when you guess the number I picked.
*/

//1..n之中猜数字，猜错要扣掉所猜数字的分值，求猜对至少需要多少分。
//看的solution，用recursive，其实用DP数组可以更快。
//DP自己做，"DP[i][j]=min{k+ max(DP[i][k-1],DP[k+1][j])} for k=i..j，共O(n^3)"



///////////////////////////////// solution 1: recursive //26ms  36.27%
    int DP(int *num, int a, int b, int n){
        if (a >= b) return 0;
        if (*(num+a*n+b) > 0) return *(num+a*n+b);

        int res = INT_MAX;
        for (int i=a;i<=b;i++){
            int tmp = i + max(DP(num,a,i-1,n),DP(num,i+1,b,n));
            res = min(res,tmp);
        }
        *(num+a*n+b) = res;
        return res;
    
    }

    int getMoneyAmount(int n) {
        int num[n+1][n+1] = {0};
        memset(num,0,(n+1)*(n+1)*sizeof(int));
        return DP(*num,1,n,n);
    }

///////////////////////////////// solution 2: DP //13ms     78.32%

    int getMoneyAmount(int n) {
        int DP[n+2][n+2];
        memset(DP,0,(n+2)*(n+2)*sizeof(int));
        for (int d = 1;d<n;d++)
            for (int i=1;i<=n-d;i++){
                int tmp = 0,j=i+d;
                DP[i][j] = INT_MAX;
                for (int k=i;k<=j;k++){
                    tmp = k + max(DP[i][k-1],DP[k+1][j]);
                    DP[i][j] = min(DP[i][j],tmp);
                }
            }
        return DP[1][n];
    }

}
