//020_Valid_Parentheses.h
//字符串中只有'(){}[]'判断是否为合格的括号组合，如([)]为否
//找到一组括号，掐头去尾后递归,剩下部分也递归



    bool isValid(string s) {
        int len = s.size(),tmp = 1;
        if (len == 0) return true;
        if ((len % 2) == 1) return false;
        char c1,c2;
        c1 = s[0];
        
        if (c1 == '(') c2 = ')';
        else if (c1 == '[') c2 = ']';
        else if (c1 == '{') c2 = '}';
        else return false;
        
        for(int i=1;i<len;i++){
            if (s[i] == c1) tmp++;
            if (s[i] == c2) tmp--;
            if (tmp == 0){          //找到了配对的右括号
                return (isValid(s.substr(1, i-1)) && isValid(s.substr(i+1, len-i-1)));
            }
        }
        return false;
        
    }
    
    
int main(){
    cout<<"020_Valid Parentheses:Input a string,Output whether it is valid with (){}[]"<<endl;
    string s;
    cin>>s;
    while(s!= "-1"){
        cout<<isValid(s)<<endl;
        cin>>s;
    }
    
    return 0;
}
