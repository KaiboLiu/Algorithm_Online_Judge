//326_Power_of_Three.h
//52ms	98.76%

/*
Total Accepted: 89871
Total Submissions: 225631
Instruction: LeetCode 326 - Power of Three - [E]
Developer: lrushx
Process Time: Apr 27, 2017
*/


/*
Given an integer, write a function to determine if it is a power of three.

Follow up:
Could you do it without using any loop / recursion?
*/


//假设n=3^k，对指数用二分法，也就是返回f(根n)或者f(根n/3)
//52ms	98.76%
    bool isPowerOfThree(int n) {
        if (n < 1) return false;
        if (n == 1) return true;
        if (n % 3 != 0) return false;
        int i = sqrt(n);
        if (i*i == n) return isPowerOfThree(i);
        n = n / 3;
        i = sqrt(n);
        if (i*i == n) return isPowerOfThree(i);
        return false;
    }
    
    
//用取对数的方法，求出答案后再算幂，和原数对比
//76ms	20.88%
    bool isPowerOfThree(int n) {
        return ((n>0) && (pow(3,round(log(n)/log(3)))==n));
    }