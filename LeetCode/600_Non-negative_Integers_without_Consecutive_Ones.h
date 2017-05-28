//600_Non-negative_Integers_without_Consecutive_Ones.h
//6ms
//LeetCode Contest 34

/*
Total Accepted: 126
Total Submissions: 460
Instruction: LeetCode 600 - Non-negative Integers without Consecutive Ones - [H]
Developer: lrushx
Process Time: May 27, 2017
*/

/*
Given a positive integer n, find the number of non-negative integers less than or equal to n, whose binary representations do NOT contain consecutive ones.

Example 1:
Input: 5
Output: 5
Explanation: 
Here are the non-negative integers <= 5 with their corresponding binary representations:
0 : 0
1 : 1
2 : 10
3 : 11
4 : 100
5 : 101
Among them, only integer 3 disobeys the rule (two consecutive ones) and the other 5 satisfy the rule. 
Note: 1 <= n <= 109
*/

//给一个数n,求0~n中二进制数没有连续1的数的个数
//可以用递归做，但我选择了数学方法，用g[l]表示长度最大为l的二进制数中所有不连续1的数的个数(遍历0的个数，然后插入1的组合数相加方法)，存到数组g中。
//根据给的num,算出其二进制数长度len，以b=1<<len-1为界，分成0～b-1和b~num两部分，前者即为g[len-1]，后者根据最左边2位为10或者11，答案为f(num-2<<(len-2))或者g[len-2]。
//因为左边2位为10的话，去掉左边10剩下的数做递归的答案就是这部分的解；而左边为11的话，要保证最左的1保留，那么第二位必须位0，第三位到最后可以随便取，即为g[len-2]
//先写了个组合数的函数，用了double，算完后返回(int)，没有意识到这里精度问题，g[]数组里有几个数个位有偏差。。。tmd。。。导致结果一直不对。直到比赛结束后才发现，换成round()返回就对了。。。



/*
    void res_from_len_no_restrict(){
        int tmp;
        for (int n=1;n<=32;n++){
            tmp = 0;
            for (int i=0;i<=(n+1)/2;i++) 
                int tmp += comp(i,n-i+1);
            cout<<"--"<<n<<" "<<tmp<<endl;
        }
        return;
    }
    
    int comp(int i,int n){
        if (i > n/2) i = n-i;
        double res = 1;
        for (int j=0;j<i;j++) res = res * (n-j)/(i-j);
        return round(res);
    }
*/    
    int g[33] = {1,2,3,5,8,13,21,34,55,89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946, 17711, 28657, 46368, 75025, 121393, 196418, 317811, 514229, 832040, 1346269, 2178309, 3524578, 5702887};
    
    int findIntegers(int num) {
        if (num == 0) return 1;
        int res = 0;
        int len = 0,n=num;
        while (n > 0){
            len ++;
            n >>= 1;
        }
        
        if (len < 3) return g[len];
        
        n = num >> (len-2);
        if (n == 2) return findIntegers(num- (2<<(len-2)))+g[len-1];
        else return g[len-1]+g[len-2];

    }
