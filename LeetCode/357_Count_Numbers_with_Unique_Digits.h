//LeetCode - 357_Count_Numbers_with_Unique_Digits.h
//0ms  100%

/*
Instruction: LeetCode 357 - Count Numbers with Unique Digits - [M]
Developer: lrushx
Process Time: Apr 14, 2017
*/
 
/*
Total Accepted: 30577
Total Submissions: 67104

Given a non-negative integer n, count all numbers with unique digits, x, where 0 ≤ x < 10n.

Example:
Given n = 2, return 91. (The answer should be the total numbers in the range of 0 ≤ x < 100, excluding [11,22,33,44,55,66,77,88,99])
*/

//给一个n,求0~10^n-1中共有多少数字位数不重复？比如11，22不算
//用数学统计法，0:1, 1:10, 2:9*9, 3:9*9*8

    int calc(int n){
        
        if (n == 1) return 10;
        int ans = 9;
        for (int i=1;i<n;i++){
            ans = ans * (10-i);
        }
        return ans;
    }

    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        int ans=0;
        for (int i=1;i<=min(n,10);i++)
            ans += calc(i);
        return ans;
    }
    
    
int main(){
    
    cout<<"357_Count_Numbers_with_Unique_Digits: input n"<<endl;
    int n=0;
    while (n >= 0){
        cin>>n;
        cout<<countNumbersWithUniqueDigits(n)<<endl;
        
    }
}
    