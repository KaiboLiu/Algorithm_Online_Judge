//468_Validate_IP_Address.h
//3ms	99.12%

/*
Total Accepted: 5684
Total Submissions: 27851
Instruction: LeetCode 468 - Validate IP Address - [M]
Developer: lrushx
Process Time: May 18, 2017
*/


/*
Write a function to check whether an input string is a valid IPv4 address or IPv6 address or neither.
IPv4 addresses are canonically represented in dot-decimal notation, which consists of four decimal numbers, each ranging from 0 to 255, separated by dots ("."), e.g.,172.16.254.1;
Besides, leading zeros in the IPv4 is invalid. For example, the address 172.16.254.01 is invalid.
IPv6 addresses are represented as eight groups of four hexadecimal digits, each group representing 16 bits. The groups are separated by colons (":"). For example, the address 2001:0db8:85a3:0000:0000:8a2e:0370:7334 is a valid one. Also, we could omit some leading zeros among four hexadecimal digits and some low-case characters in the address to upper-case ones, so 2001:db8:85a3:0:0:8A2E:0370:7334 is also a valid IPv6 address(Omit leading zeros and using upper cases).
However, we don't replace a consecutive group of zero value with a single empty group using two consecutive colons (::) to pursue simplicity. For example, 2001:0db8:85a3::8A2E:0370:7334 is an invalid IPv6 address.
Besides, extra leading zeros in the IPv6 is also invalid. For example, the address 02001:0db8:85a3:0000:0000:8a2e:0370:7334 is invalid.
Note: You may assume there is no extra space or special characters in the input string.
Example 1:
Input: "172.16.254.1"
Output: "IPv4"
Explanation: This is a valid IPv4 address, return "IPv4".
Example 2:
Input: "2001:0db8:85a3:0:0:8A2E:0370:7334"
Output: "IPv6"
Explanation: This is a valid IPv6 address, return "IPv6".
Example 3:
Input: "256.256.256.256"
Output: "Neither"
Explanation: This is neither a IPv4 address nor a IPv6 address.
*/


//给一个字符串，判断是否是合理IPv4或者IPv6
//IPv4是有4个十进制数中间隔3个.构成，每个[0,255]，不能有前面多余0；IPv６是有8个４位十六进制数中间隔7个:构成，每位[0,F]，字母可以大小写。
//IPv4的异常情况是：多余./连续./数字之外异常字符/数字大于4位/3位以下数字>255/1位以上数字0开头
//IPv6的异常情况是：多余:/连续:/数字、a~f、A~F之外异常字符/数字大于4位
//规定个数.或者:结束后判断有没有到字符串尾巴，若不是，说明后面有多余字符


    string validIPAddress(string IP) {
        string out[] = {"IPv4","IPv6","Neither"};
        int res,k,i,tmp,j;
        size_t found = IP.find('.');
        if (found != std::string::npos) res = 0;
        else {
            found = IP.find(':');
            if (found != std::string::npos) res = 1;
            else return out[2];
        }
        if (res == 0){
            IP += '.';
            i = 0;
            for (k=0;k<4;k++){
                //if (IP[i] == '.') return out[2];
                found = IP.find('.',i);
                if (found == std::string::npos || found == i || found-i > 3 || (found-i>1 && IP[i] == '0')) return out[2];
                tmp = 0;
                for (j = i; j<found; j++){
                    if (IP[j] < 48 || IP[j] > 57) return out[2];
                    tmp = tmp * 10 + (IP[j] - '0');
                }
                //tmp = stoi(IP.substr(i,found-i));
                if (tmp > 255) return out[2];
                i = found + 1;
            }
            if (i == IP.size()) return out[res]; else return out[2];
        } else {
            IP += ":";
            i = 0;
            for (k=0;k<8;k++){
                found = IP.find(':',i);
                if (found == std::string::npos || found == i || found-i > 4) return out[2];
                for (j = i; j<found; j++)
                    if (IP[j] < 48 || (IP[j]>57 && IP[j]<65) || (IP[j]>70 && IP[j]<97) || IP[j] > 102) return out[2];
                i = found + 1;
            }
            if (i == IP.size()) return out[res]; else return out[2];
        }
        
    }




