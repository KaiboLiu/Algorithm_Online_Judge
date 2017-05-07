//396_Rotate_Function.h
//9ms	100.00%

/*
Total Accepted: 17855
Total Submissions: 56460
Instruction: LeetCode 396 - Rotate Function - [M]
Developer: lrushx
Process Time: May 05, 2017
*/


/*
Given an array of integers A and let n to be its length.

Assume Bk to be an array obtained by rotating the array A k positions clock-wise, we define a "rotation function" F on A as follow:

F(k) = 0 * Bk[0] + 1 * Bk[1] + ... + (n-1) * Bk[n-1].

Calculate the maximum value of F(0), F(1), ..., F(n-1).

Note:
n is guaranteed to be less than 105.

Example:

A = [4, 3, 2, 6]

F(0) = (0 * 4) + (1 * 3) + (2 * 2) + (3 * 6) = 0 + 3 + 4 + 18 = 25
F(1) = (0 * 6) + (1 * 4) + (2 * 3) + (3 * 2) = 0 + 4 + 6 + 6 = 16
F(2) = (0 * 2) + (1 * 6) + (2 * 4) + (3 * 3) = 0 + 6 + 8 + 9 = 23
F(3) = (0 * 3) + (1 * 2) + (2 * 6) + (3 * 4) = 0 + 2 + 12 + 12 = 26

So the maximum value of F(0), F(1), F(2), F(3) is F(3) = 26.
*/

//f=和(i*a[i])，然后以此轮转a[i]后继续求f，求最大的f
//用递推式，f[k]-f[k-1]=所有和-na[n-k]

    int maxRotateFunction(vector<int>& A) {
        int len = A.size();
        if (len < 2) return 0;
        int i,f=0,res,sum=0;
        for (i=0;i<len;i++){
            f += i*A[i];
            sum += A[i];
        } 
        res = f;
        for (i=1;i<len;i++){
            f = f + (sum - len * A[len-i]);
            if (f > res) res = f;
        }
        return res;
    }
