//604_Design_Compressed_String_Iterator.h
//
//LeetCode Contest 36

/*
Total Accepted: 777
Total Submissions: 1091
Instruction: LeetCode 604 - Design Compressed String Iterator - [E]
Developer: lrushx
Process Time: June 10, 2017
*/

/*Design and implement a data structure for a compressed string iterator. It should support the following operations: next and hasNext.

The given compressed string will be in the form of each letter followed by a positive integer representing the number of this letter existing in the original uncompressed string.

next() - if the original string still has uncompressed characters, return the next letter; Otherwise return a white space.
hasNext() - Judge whether there is any letter needs to be uncompressed.

Note:
Please remember to RESET your class variables declared in StringIterator, as static/class variables are persisted across multiple test cases. Please see here for more details.

Example:

StringIterator iterator = new StringIterator("L1e2t1C1o1d1e1");

iterator.next(); // return 'L'
iterator.next(); // return 'e'
iterator.next(); // return 'e'
iterator.next(); // return 't'
iterator.next(); // return 'C'
iterator.next(); // return 'o'
iterator.next(); // return 'd'
iterator.hasNext(); // return true
iterator.next(); // return 'e'
iterator.hasNext(); // return false
iterator.next(); // return ' '
*/

//给一个字符串s，<字母数字><字母数字>..的组合，数字表示字母的重复次数，用户调用hasNext和Next来获取下一个字母
//设定全局变量pos,Npos,num，分别表示当前字母在s中的位置，下一个字母位置，当前字母重复的剩余次数。
//每次Next时都调用hasNext，若num为0则读取下一个字母pos=Npos，并且从pos+1开始确定新字母的重复次数
//注意重复次数可能是多位数

class StringIterator {
private:
    string S;
    int pos,num,len,Npos;
public:
    StringIterator(string compressedString) {
        S = compressedString;
        len = compressedString.size();
        num = 0;
        Npos = 0;
    }
    
    char next() {
        if (!hasNext()) return ' ';
        num--;
        return S[pos];
        
    }
    
    bool hasNext() {
        if (num == 0){
            pos = Npos;
            Npos++;
            while (Npos < len && S[Npos] <= '9'){
                num = num*10+S[Npos]-'0';
                Npos++;
            }
        }
        return pos < len;
    }
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator obj = new StringIterator(compressedString);
 * char param_1 = obj.next();
 * bool param_2 = obj.hasNext();
 */
