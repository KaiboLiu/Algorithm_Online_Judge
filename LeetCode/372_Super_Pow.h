//372_Super_Pow.h
//9ms	96.97%

/*
Total Accepted: 14610
Total Submissions: 43203
Instruction: LeetCode 372 - Super Pow - [M]
Developer: lrushx
Process Time: May 05, 2017
*/


/*
Your task is to calculate ab mod 1337 where a is a positive integer and b is an extremely large positive integer given in the form of an array.

a = 2
b = [1,0]

Result: 1024
*/

//给一个a和高精度数组b，求a^b % 1337的结果
//一开始用指数二分法，结果时间很长，因为高精度数组可以很大，二分虽然挺好但不是最快
//看了答案后发现可以用a^12345=a^12340*a^5=(a^1234)^10*a^5, 也就是f(a,12345)=f(f(a,1234),10) * f(5)，按位来算，从log2n变成了log10n



//solution1, calc by binary divide in exponent,log2(n)
//479ms 6%
    int superPow(int a, vector<int>& b) {
        int len = b.size();
        if (len == 1 && b[0] == 0) return 1;
        int res,i,odd=1;
        if (a > 1337) a = a % 1337;
        if (len == 1 && b[0] == 1) return a;
        
        if ((b[len-1] & 1) == 1) odd = a;
        for (i = 0;i < len-1;i++){
            b[i+1] += (b[i] % 2)*10;
            b[i] = b[i] / 2;
        }
        b[len-1] = b[len-1] / 2;
        if (b[0] == 0) b.erase(b.begin());
        //for (i=0;i<b1.size();i++) cout<<b1[i]<<" "; cout<<endl;
        res = superPow(a,b);
        res = (res * res) % 1337;
        return (res * odd) %1337;
    }


//solution2, calc by digit in exponent,log10(n)
//9ms	96.97%

    int Pow(int a,int b){
        if (b == 1) return a;
        int res;
        res = Pow(a,b/2);
        res = (res * res) % 1337;
        if ((b & 1) == 1) return (res * a) % 1337;
        else return res;
    }
    
    int superPow(int a, vector<int>& b) {
        if (a >= 1337) a = a % 1337;
        
        int len = b.size(),Powtail;
        int tail=b[len-1];
        if (tail ==0) Powtail = 1;
        else Powtail = Pow(a,tail);
        
        if (len == 1) return Powtail;
        
        b.pop_back();
        return (Pow(superPow(a,b),10) * Powtail) % 1337;

    }