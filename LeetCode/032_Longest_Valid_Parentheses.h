//032_Longest_Valid_Parentheses.h
//找到左右括号组成的字符中最长的合格括号组合，返回长度
//此种方法超时<-遍历左括号，搜索到相应右括号，用20的方法判断中间是否合格，更新合格组合的长度。
//用DP，先搁置

/*
//找到左右括号组成的字符中最长的合格括号组合，返回长度
//此种方法超时<-遍历左括号，搜索到相应右括号，用20的方法判断中间是否合格，更新合格组合的长度。
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
    
    
    int longestValidParentheses(string s) {
        int ans = 0,tail = -1,l1,r1,l2,r2;
        int len = s.size();
        if (len < 2) return 0;
        cout<<len<<endl;
        l1 = r1 = l2 = r2 = -1;
        for (int i=0;i<len;i++){//寻找第一个左括号和第一个右括号
        
            if (s[i] == '(' && l1 < 0) {  l1 = i; ans++;}
            else if (s[i] == ')' && r1 < 0) {r1 = i;ans++;}
            
            if (s[len-i-1] == '(' && l2 < 0) {  l2 = len-i-1; ans++;}
            else if (s[len-i-1] == ')' && r2 < 0) {r2 = len-i-1;ans++;}
            
            if (ans >= 4) break;
        }
        cout<<l1<<" "<<r1<<" "<<l2<<" "<<r2<<endl;
        ans = 0;
        for (int i=l1;i<=l2;i++){
            if (s[i] == ')') continue;
            int tmp = 1;
            for(int j=i+1;j<=min(len-1,r2);j++){
                if (s[j] == '(') tmp++;
                if (s[j] == ')') tmp--;
                if (tmp == 0){          //找到了配对的右括号
                   cout<<i<<"  "<<j<<endl;
                    if (isValid(s.substr(i+1, j-i-1))){
                        if (tail == (i - 1)) ans += j-i+1; //新的配对括号组和上一个相邻，则加在一起
                        else if (j-i+1 > ans) ans = j-i+1; //新的配对括号组和上一个不相邻，则按大的更新ans
                        i = tail = j;
                        break;//之前没加这句，那么一直会去找j
                    }
                    
                }
            }
        }
        return ans;
    }
*/    
//DP,8ms,100%
    
    int longestValidParentheses(string s) {
        vector<int> f;
        int len = s.size(),ans=0;
        if (len < 2) return 0;
        f.resize(len);
        f[0] = 0;
        for (int i = 1;i<len;i++){
            f[i] = 0;
            if (s[i] == ')'){
                if (i > f[i-1] && s[i-f[i-1]-1] == '('){
                    f[i] = f[i-1] + 2;
                    if (i >= f[i]) f[i] += f[i-f[i]];
                    if (f[i] > ans) ans = f[i];
                }
            }
        }
        return ans;
    }
int main(){

    cout<<"032 Longest Valid Parentheses:Input a string,Output the length of the longest valid (well-formed) parentheses substring"<<endl;
    string s;
    cin>>s;
    while(s!= "-1"){
        cout<<longestValidParentheses(s)<<endl;
        cin>>s;
    }
    
    return 0;
}
