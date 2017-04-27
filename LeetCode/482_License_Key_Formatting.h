//482_License_Key_Formatting.h
//9ms	90.13%


/*
Total Accepted: 13153
Total Submissions: 31911
Instruction: LeetCode 482 - License Key Formatting - [M]
Developer: lrushx
Process Time: Apr 22, 2017
*/

/*
Now you are given a string S, which represents a software license key which we would like to format. The string S is composed of alphanumerical characters and dashes. The dashes split the alphanumerical characters within the string into groups. (i.e. if there are M dashes, the string is split into M+1 groups). The dashes in the given string are possibly misplaced.
We want each group of characters to be of length K (except for possibly the first group, which could be shorter, but still must contain at least one character). To satisfy this requirement, we will reinsert dashes. Additionally, all the lower case letters in the string must be converted to upper case.
So, you are given a non-empty string S, representing a license key to format, and an integer K. And you need to return the license key formatted according to the description above.

Input: S = "2-4A0r7-4k", K = 3
Output: "24-A0R-74K"
*/

//给一个字符和-组成的码和int K，删除全部-后等K长地插入-，除第一组可以不为K，另外把所有小写改成大写。
//删除从前往后找-，插入从后往前即可。


    string licenseKeyFormatting(string S, int K) {
        int len = S.size(),i=0;
        string t=S;
        while (i < t.size()){
            if (t[i] == '-') {
                t.erase(i,1);
                continue;
            }
            if (t[i]>='a') t[i]=t[i]-'a'+'A';
            i++;
        }// end when i==t.size()
        i -= K;
        while (i > 0){
            t.insert(i,"-");
            i -= K;
        }
        return t;

    }