//434_Number_of_Segments_in_a_String.h
//0ms	100.00%

/*
Total Accepted: 19217
Total Submissions: 51852
Instruction: LeetCode 434 - Number of Segments in a String - [E]
Developer: lrushx
Process Time: May 15, 2017
*/


/*
Count the number of segments in a string, where a segment is defined to be a contiguous sequence of non-space characters.
Please note that the string does not contain any non-printable characters.

Example:

Input: "Hello, my name is John"
Output: 5
*/


//给一个字符串，返回其中有多少个单词(以空格分开)
//尾部+1个空格，然后从前往后找空格，有连续的就继续往后更新



    int countSegments(string s) {
        int len = s.size()+1,res=0,i=0;
        s += " ";
        while (i<len && s[i]==' ') i++;
        if (i == len) return 0;
        while (i < len){
            while (i < len && s[i] != ' ') i++;
            res++;
            while (i<len && s[i]==' ') i++;
        }
        return res;
    }