//038_Count_and_Say.h
//从1开始，1, 11, 21, 1211, 111221，读出上一个序列中“几个2，几个1”
//按顺序生成序列，无规律可找

    string countAndSay(int n) {
        string s="1",t;
        int count;
        for (int k=0;k<n-1;k++){
            t = "";
            for (int i=0;i<s.size();i++){
                count = 0;
                char c = s[i];
                char str[20] = {'\0'};
                while (i<s.size() && s[i] == c){count++;i++;}
                sprintf(str,"%d",count);
                t = t + str + c;
                i--;
            }
            s = t;
        }
        return s;
    }
    
    
int main(){
    cout<<"038_Count and Say:Input n, return the generate the nth Count and Say sequence."<<endl;
    int n;
    string res;
    cin>>n;
    while(n >0){
        res = countAndSay(n);
        cout<<res.size()<<' '<<res<<endl;
        cin>>n;
    }
    
    return 0;
}
    
