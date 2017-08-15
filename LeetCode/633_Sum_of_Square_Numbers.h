//633_Sum_of_Square_Numbers.h
//3ms 99.85%


/*
Total Accepted: 8.1k
Total Submissions: 25.7k
Instruction: LeetCode 633 - Sum of Square Numbers - [E]
Developer: lrushx
Process Time: Aug 14, 2017
*/

/*
Given a non-negative integer c, your task is to decide whether there're two integers a and b such that a^2 + b^2 = c.

Example 1:
Input: 5
Output: True
Explanation: 1 * 1 + 2 * 2 = 5
Example 2:
Input: 3
Output: False
*/


//inspired by Fermat's Conjecture
//return true if the number of each prime factor which can be written as p=4m+3 is even.
//once there is a prime factor p=4m+3 in odd times, return false
//example: 18 = 3*3*2, there are 2 times for the prime factor 3, return true(3^2+3^2)
//example: 27 = 3*3*3, there are 3 times for the prime factor 3, return false



    bool judgeSquareSum(int c) {
        int div = 3,t,sq = sqrt(c);
        if ((c-3)%4 == 0) return false;
        for (int i=2;i<=sq;i++){
            if (c % i == 0){
                if ((i-3) % 4 == 0){
                    t = 0;
                    while (c % i == 0){
                        t++;
                        c /= i;
                    }
                    if ((t & 1) == 1) return false;
                }
                else while (c % i == 0) c /= i;
                if (c == 1) return true;
            }
        }
        if ((c-3)%4 == 0) return false;
        return true;
        
    }
