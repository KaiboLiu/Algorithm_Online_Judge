//394_Decode_String.h
//0ms   100%


/*
Total Accepted: 26685
Total Submissions: 65325
Instruction: LeetCode 394 - Decode String - [M]
Developer: lrushx
Process Time: Apr 27, 2017
*/


/*
Given an encoded string, return it's decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.
You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.
Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].

Examples:
s = "3[a]2[bc]", return "aaabcbc".
s = "3[a2[c]]", return "accaccacc".
s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
*/

//一个字符串，包含数字、'['，']'和其他字符，数字i后紧接[str]意思是要把str重复i遍，可以嵌套，要返回重复后的字符。
//往后遍历，逐位复制到答案，如果碰到数字，则开始一个新的block：先提取数字k，再提取一对[]，再调用本函数返回[]间的答案作为subs，然后重复k次复制。
//一开始弄错了，没必要一定是数字开始，这样就可以通用地回溯调用本函数。



    int findpair(string s,int i,int len){
        int pair = 1,j;
        while (i < len && s[i] != '[') i++;
        j = i+1;
        while (j < len && pair > 0){
            if (s[j] == '[') pair++;
            else if (s[j] == ']') pair--;
            j++;
        }
        return --j;
    }
    
    string decodeString(string s) {
        int len = s.size();
        if (len < 1) return "";
        int i=0,j,pair,rep,i1;
        string ans = "",subs;
        while (i < len){
            rep = 0;
            if (s[i] > '9'){
                ans = ans + s.substr(i++,1);
                continue;
            }
            while (s[i] <= '9')
                rep = rep * 10 + (s[i++]-'0');
            j = findpair(s,i,len);// i..j is "[..]"
            //generate subs to repeat
            subs = decodeString(s.substr(i+1,j-i-1));

            for (i1 =0;i1<rep;i1++)
                ans = ans + subs;
            i = j + 1;
        }
        return ans;
        
    }