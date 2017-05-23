//592_Fraction_Addition_and_Subtraction.h
//3ms	100.00%
//LeetCode Contest 33

/*
Total Accepted: 348
Total Submissions: 407
Instruction: LeetCode 592 - Fraction Addition and Subtraction - [M]
Developer: lrushx
Process Time: May 20, 2017
*/


/*
Given a string representing an expression of fraction addition and subtraction, you need to return the calculation result in string format. The final result should be irreducible fraction. If your final result is an integer, say 2, you need to change it to the format of fraction that has denominator 1. So in this case, 2 should be converted to 2/1.

Example 1:
Input:"-1/2+1/2"
Output: "0/1"
Example 2:
Input:"-1/2+1/2+1/3"
Output: "1/3"
Example 3:
Input:"1/3-1/2"
Output: "-1/6"
Example 4:
Input:"5/3+1/3"
Output: "2/1"
Note:
The input string only contains '0' to '9', '/', '+' and '-'. So does the output.
Each fraction (input and output) has format ±numerator/denominator. If the first input fraction or the output is positive, then '+' will be omitted.
The input only contains valid irreducible fractions, where the numerator and denominator of each fraction will always be in the range [1,10]. If the denominator is 1, it means this fraction is actually an integer in a fraction format defined above.
The number of given fractions will be in the range [1,10].
The numerator and denominator of the final result are guaranteed to be valid and in the range of 32-bit int.
*/


//分数字符串表达式求解，只有加减法，所有数字都已最简分数表示(包括整数c为c/1)
//提取每一个分数，表示为a/b，答案为a0/b0，逐个相加即可，注意负数，以及及时除以公约数gcd



    int gcd(int a,int b){
        if (b == 0) return a;
        return gcd(b,a % b);
    }

    string fractionAddition(string expression) {
        int len = expression.size();
        if (len <= 6) return expression;
        if (expression[0] != '-') {expression = "+"+expression; len++;}
        int i=0,j,a,b,a0=0,b0=1,g;
        bool neg;
        while (i < len){
            if (expression[i] == '-') neg = true; else neg = false;
            a = 0; b = 0;
            j = i + 1;
            while (expression[j] != '/') a = a*10+(expression[j++]-'0');
            j++;
            while (j < len && expression[j] != '+' && expression[j] != '-') b = b*10+(expression[j++]-'0');
            if (neg) a = -a;
            a0 = a0*b + b0*a;
            b0 = b0*b;
            if (a0 == 0) b0 = 1;
            else{
                g = gcd(abs(a0),b0);
                a0 /= g;  b0 /= g;
            }
            i = j;
        }
        return (to_string(a0)+"/"+to_string(b0));
        
    }