//022_Generate_Parentheses.h
//生成n对括号的所有排列
//回溯，根据'('和')'的个数标号p、q来选择括号：p<n加'(',q<p加')',当p==q==n时输出一个答案


//private:

    
    vector<string> ans;
    
//public:
    void solve(string s,int n,int p,int q){
        
        if (p == n && q == n){
            ans.push_back(s);
            cout<<s<<endl;//提交时要删掉，不删的话输出也没错，因为只判返回值不用输入输出流
            return;
        }
        if (p < n) solve(s+"(",n,p+1,q);
        if (p > q) solve(s+")",n,p,q+1);
        return;
        
    }
        
    vector<string> generateParenthesis(int n) {
        solve("",n,0,0);
        return ans;
    }

int main(){
    cout<<"022_Generate Parentheses:Input n until negative,Output all combinations of n pairs of well-formed parenthesesthe"<<endl;
    int n;
    cin>>n;
    while(n >= 0){
        generateParenthesis(n);
        cin>>n;
    }
    
    return 0;
}
