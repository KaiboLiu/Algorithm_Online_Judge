//412_Fizz_Buzz.h
//3ms   100%

/*
Total Accepted: 60176
Total Submissions: 102344
Instruction: LeetCode 412 - Fizz Buzz - [E]
Developer: lrushx
Process Time: Apr 27, 2017
*/


/*
Write a program that outputs the string representation of numbers from 1 to n.
But for multiples of three it should output “Fizz” instead of the number and for the multiples of five output “Buzz”. For numbers which are multiples of both three and five output “FizzBuzz”.

Example:
n = 15,
Return:
[
    "1",
    "2",
    "Fizz",
    "4",
    "Buzz",
    "Fizz",
    "7",
    "8",
    "Fizz",
    "Buzz",
    "11",
    "Fizz",
    "13",
    "14",
    "FizzBuzz"
]
*/

//给一个n，输出1..n的数字字符，只是3的倍数用Fizz表示，5倍数用Buzz，15倍数用FizzBuzz表示
//从1到n遍历，遇到倍数就用特殊串，否则按位构成数字字符
//把一个生成的char加到字符串：string(1, ch) + str



    string convert(int n){
        if (n % 15 == 0) return "FizzBuzz";
        if (n % 3 == 0) return "Fizz";
        if (n % 5 == 0) return "Buzz";
        string ans = "";
        while (n > 0){
            ans = string(1,(n%10)+'0') + ans;
            n = n / 10;
        }
        return ans;
    }
    
    
    vector<string> fizzBuzz(int n) {
        vector<string> ans(n,"");
        for (int i=1;i<=n;i++)
            ans[i-1] = convert(i);
        return ans;
    }