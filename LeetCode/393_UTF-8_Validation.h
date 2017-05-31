//393_UTF-8_Validation.h
//16ms	75.43%

/*
Total Accepted: 13203
Total Submissions: 37933
Instruction: LeetCode 393 - UTF-8 Validation - [M]
Developer: lrushx
Process Time: May 26, 2017
*/


/*
A character in UTF8 can be from 1 to 4 bytes long, subjected to the following rules:

For 1-byte character, the first bit is a 0, followed by its unicode code.
For n-bytes character, the first n-bits are all one's, the n+1 bit is 0, followed by n-1 bytes with most significant 2 bits being 10.
This is how the UTF-8 encoding would work:

   Char. number range  |        UTF-8 octet sequence
      (hexadecimal)    |              (binary)
   --------------------+---------------------------------------------
   0000 0000-0000 007F | 0xxxxxxx
   0000 0080-0000 07FF | 110xxxxx 10xxxxxx
   0000 0800-0000 FFFF | 1110xxxx 10xxxxxx 10xxxxxx
   0001 0000-0010 FFFF | 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
Given an array of integers representing the data, return whether it is a valid utf-8 encoding.

Note:
The input is an array of integers. Only the least significant 8 bits of each integer is used to store the data. This means each integer represents only 1 byte of data.

Example 1:

data = [197, 130, 1], which represents the octet sequence: 11000101 10000010 00000001.

Return true.
It is a valid utf-8 encoding for a 2-bytes character followed by a 1-byte character.
Example 2:

data = [235, 140, 4], which represented the octet sequence: 11101011 10001100 00000100.

Return false.
The first 3 bits are all one's and the 4th bit is 0 means it is a 3-bytes character.
The next byte is a continuation byte which starts with 10 and that's correct.
But the second continuation byte does not start with 10, so it is invalid.
*/


//介绍UTF-8编码方式，用1个整数的低8位表示UTF-8的1个Byte编码
//先把每个数据都&256只留低8位，然后用&128取最高位判断是否为1，若是则为1B编码，否则为nB编码，nB编码的第一个B的高n位是1，之后的所有B都是10开头，所以判断第一个B>>6!=2之后就可以数1的个数再判断之后的B是否以10开头
//自学了挺多UTF-8的知识，其为Unicode的一种最流行实现方式



    bool validUtf8(vector<int>& data) {
        int i,first,len = data.size(),token;
        if (len == 0) return false;
        for (i=0;i<len;i++) data[i] = data[i] & 255;
        i = 0;
        while (i < len){
            if ((data[i] & 128) == 0) { i++; continue;}
            if (data[i] >> 6 == 2) return false;
            first = 1;
            token = 64; // only 2nd bit is 1
            while (first < 5 && (data[i] & token) > 0) {
                first++;
                token >>= 1;
            }
            if (first == 5 || i+first > len) return false;
            i++;
            first--;
            while (first--){
                if (data[i++] >> 6 != 2) return false;
            }
        }
        return true;
    }