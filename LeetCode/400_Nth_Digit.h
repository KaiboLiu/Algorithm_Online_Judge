//400_Nth_Digit.h
//0ms	100.00%

/*
Total Accepted: 19760
Total Submissions: 65603
Instruction: LeetCode 400 - Nth Digit - [E]
Developer: lrushx
Process Time: May 03, 2017
*/


/*
Find the nth digit of the infinite integer sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...
Note:
n is positive and will fit within the range of a 32-bit signed integer (n < 231).

Example:
Input:11
Output:0
Explanation:
The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... is a 0, which is part of the number 10.
*/

//从1,2,3,4中按位取出第k位(十位数每个2位，百位数每个3位。。。)
//递推关系，个位数9个，十位数90个长度90*2，百位数900个长度900*3，往后算到临界就行
//注意溢出，输入为INT_MAX时数据范围是8位数



    int findNthDigit(int n) {
        int base=1,k=1,l=9;
        n--;
        while (n > l && k < 9){
            n -= l;
            base = base * 10;   //位数为k的数的第一个，比如k为3，base即为100
            k++;                // k 为十进制数的位数
            l = base * k * 9;    // 位数为k的数有l个
            //cout<<k<<" "<<base<<" "<<l<<" "<<n<<endl;
        }
        //cout<<k<<" "<<to_string(base+n/k)<<endl;
        return to_string(base+n/k)[n%k]-'0';
    }