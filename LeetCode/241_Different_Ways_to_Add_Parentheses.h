//241_Different_Ways_to_Add_Parentheses.h
//3ms	100.00%

/*
Total Accepted: 41938
Total Submissions: 97746
Instruction: LeetCode 241 - Different Ways to Add Parentheses - [M]
Developer: lrushx
Process Time: May 16, 2017
*/


/*
Given a string of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. The valid operators are +, - and *.

Example 1
Input: "2-1-1".

((2-1)-1) = 0
(2-(1-1)) = 2
Output: [0, 2]


Example 2
Input: "2*3-4*5"

(2*(3-(4*5))) = -34
((2*3)-(4*5)) = -14
((2*(3-4))*5) = -10
(2*((3-4)*5)) = -10
(((2*3)-4)*5) = 10
Output: [-34, -14, -10, -10, 10]
*/


//给一个只有*+-的整数表达式字符串，按照所有加括号的组合，返回所有计算值
//分治，扫字符串，遇到运算符就把前后分成2部分，返回这2部分的所有结果，两两组合放到当前结果数组中，若当下操作后结果为空，说明没有运算符只有单个数字，那么只返回这个数字即可，这种方法是确定一个运算符，让两边分治，而不是确定一个运算符让其先算相邻2个数。前者不用考虑顺序，后者一开始就用运算的先后顺序限制了算法的适用性
//if (ispunct (int c))，返回char c或者c对应编码是不是标点
//stoi(str s)可以得到字符串对应的数字



    vector<int> diffWaysToCompute(string input) {
        vector<int> output;
        int i,len = input.size();
        for (i=0; i<len; i++)
            if (ispunct(input[i]))
                for (int a : diffWaysToCompute(input.substr(0,i)))
                    for (int b : diffWaysToCompute(input.substr(i+1)))
                        output.push_back(input[i] == '+'? a+b : input[i] == '-'? a-b : a*b);
        if (output.size() == 0) output.push_back(stoi(input));
        return output;
    }