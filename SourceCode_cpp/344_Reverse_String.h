//344_Reverse_String.h
//[E]
//12ms

//Write a function that takes a string as input and returns the string reversed.

class Solution {
public:
    string reverseString(string s) {
        string ans=s;
        char c;
        int l=s.size();
        for (int i=0;i<l/2;i++){
            c = s[i];
            s[i] = s[l-1-i];
            s[l-1-i] = c;
        }
        return s;
    }
};
