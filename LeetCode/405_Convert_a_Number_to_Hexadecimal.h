//405_Convert_a_Number_to_Hexadecimal.h
//3ms   93.58%

/*
Total Accepted: 19937
Total Submissions: 48865
Instruction: LeetCode 405 - Convert a Number to Hexadecimal - [E]
Developer: lrushx
Process Time: Apr 26, 2017
*/


/*
Given an integer, write an algorithm to convert it to hexadecimal. For negative integer, two’s complement method is used.
Note:
All letters in hexadecimal (a-f) must be in lowercase.
The hexadecimal string must not contain extra leading 0s. If the number is zero, it is represented by a single zero character '0'; otherwise, the first character in the hexadecimal string will not be the zero character.
The given number is guaranteed to fit within the range of a 32-bit signed integer.
You must not use any method provided by the library which converts/formats the number to hex directly.
Input:26
Output:"1a"
Input:-1
Output:"ffffffff"
*/

//输入int输出10进制转16进制的string



    string toHex(int num) {
        if (num == 0) return "0";
        string ans = "";
        string d2h[] = {"0","1","2","3","4","5","6","7","8","9","a","b","c","d","e","f"};
        if (num < 0){
            num = -1-num;
            for (int i=0;i<8;i++){
                ans = d2h[15-(num%16)] + ans;
                num = num / 16;
            }
        }else while (num > 0){
            ans = d2h[num%16] + ans;
            num = num / 16;
        }
        return ans;
    }
