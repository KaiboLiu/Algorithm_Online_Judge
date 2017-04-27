//537_Complex_Number_Multiplication.h
//0ms   100%

/*
Total Accepted: 4947
Total Submissions: 7534
Instruction: LeetCode 537 - Complex Number Multiplication - [M]
Developer: lrushx
Process Time: Apr 25, 2017
*/


/*
Given two strings representing two complex numbers.
You need to return a string representing their multiplication. Note i2 = -1 according to the definition.

Input: "1+1i", "1+1i";    Output: "0+2i"
Input: "1+-1i", "1+-1i";  Output: "0+-2i"

The input strings will not have extra blank.
The input strings will be given in the form of a+bi, where the integer a and b will both belong to the range of [-100, 100]. And the output should be also in this form.
*/

//复数乘法，字符串输入输出；
//注意字符串转换即可
//把一个生成的char加到字符串：string(1, ch) + str


    int tonum(string a,int i,int j){
        int ans = 0;
        for (int k=i;k<=j;k++)
            ans = ans * 10 + (a[k]-'0');
        return ans;
    }
    
    string tostr(int n){
        if (n == 0) return "0";
        string ans="";
        int a;
        a = n < 0 ? -n:n;
        while (a > 0){
            ans = string(1, (a%10)+'0') + ans;
            a = a / 10;
        }
        if (n < 0) ans = "-" + ans;
        return ans;
    }
    
    string complexNumberMultiply(string a, string b) {
        size_t symb=0;
        int x1,x2,y1,y2,x3=0,y3;
        int start = 0;
        
        // string a
        symb = a.find("+");
        if (a[start] == '-') {
            start++;
            x1 = -tonum(a,start,symb-1);
        }else x1 = tonum(a,start,symb-1);
        
        start = symb + 1;
        symb = a.size()-2;
        if (a[start] == '-') {
            start++;
            y1 = -tonum(a,start,symb);
        }else y1 = tonum(a,start,symb);
        
        // string b
        start = 0;
        symb = b.find("+");
        if (b[start] == '-') {
            start++;
            x2 = -tonum(b,start,symb-1);
        }else x2 = tonum(b,start,symb-1);
        
        start = symb + 1;
        symb = b.size()-2;
        if (b[start] == '-') {
            start++;
            y2 = -tonum(b,start,symb);
        }else y2 = tonum(b,start,symb);
        
        x3 = x1 * x2 - y1 * y2;
        y3 = x1*y2 + x2*y1;
        
        return tostr(x3)+"+"+tostr(y3)+"i";
    }
