//385_Mini_Parser.h
//19ms	90.19%

/*
Total Accepted: 14158
Total Submissions: 47239
Instruction: LeetCode 385 - Mini Parser - [M]
Developer: lrushx
Process Time: May 28, 2017
*/


/*
Given a nested list of integers represented as a string, implement a parser to deserialize it.
Each element is either an integer, or a list -- whose elements may also be integers or other lists.
Note: You may assume that the string is well-formed:
String is non-empty.
String does not contain white spaces.
String contains only digits 0-9, [, - ,, ].
Example 1:
Given s = "324",
You should return a NestedInteger object which contains a single integer 324.
Example 2:
Given s = "[123,[456,[789]]]",
Return a NestedInteger object containing a nested list with 2 elements:
1. An integer containing value 123.
2. A nested list containing two elements:
    i.  An integer containing value 456.
    ii. A nested list with one element:
         a. An integer containing value 789.
*/


//类似341，根据字符串生成嵌套数，可以是一个数字，也可以是一个列表，每个元素是数字或者列表
//在这里要摒弃vector固有函数，用题目给的内部函数，返回值为NestedInteger res。
//若这个结构只含一个数(字符串没有开头的'[')则直接把当前字符串变成数字a，用赋值函数res.setInteger(a)，再返回res；
//若这个结构以'['开头，说明是个嵌套列表，则遍历当前字符串s[1,-1]，根据逗号分割，若是数字则转成数字a后用内部构成函数NestedInteger N(a)，再res.add(N)，若是列表('['开头)则找到这个列表的尾部，联通起止的'['']'一起复制字串递归计算结果返回这部分的嵌套值，add到当前res后

//要继承vector思想但是摈弃其固有函数。
//拿到字符串直接判断有没有初始的'['，若没有，则为数字，直接把res当一个数字考虑，用res.setInteger(a)；若有'['则要当vector考虑，只是res.push_back(N)变成了res.add(N)，并且这里的N需要继续递归
//题目给的提示是stack，有空可以做做


    NestedInteger deserialize(string s){
        int len = s.size(),i=1,j;
        NestedInteger res;
        if (s[0] != '['){
            res.setInteger(stoi(s));
            return res;
        }
        while (i < len-1){
            if (s[i] == ',') i++;
            j = i + 1;
            if (s[i] == '['){
                int count = 1;
                while (j < len-1 && count){
                    if (s[j] == '[') count++;
                    else if (s[j] == ']') count--;
                    j++;
                }
                res.add(deserialize(s.substr(i,j-i)));
            } else{
                while (j < len-1 && isdigit(s[j])) j++;
                NestedInteger N(stoi(s.substr(i,j-i)));
                res.add(N);
            }
            i = j;
        }
        return res;
    }