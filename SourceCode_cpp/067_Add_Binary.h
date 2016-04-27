//067_Add_Binary.h
//求两个二进制数的和，用string表示
//字符串和数字相加的转换，注意最高位，可以用s.erase(位置,个数)删除,也可以用'1'+s加上最高位

    string addBinary(string a, string b) {
        int lena ,lenb,left=0,loc=0;
        if (a.size() < b.size()) a.swap(b);
        lena = a.size();lenb = b.size();    //a长，b短,r若a=b则答案长度必为a+1
        string ans;
        if (lenb == 0) return a;
        
        ans.assign(lena+1,'0');
        for(int i=1;i<=lenb;i++){
            left = ((a[lena-i]-'0') + (b[lenb-i]-'0') + loc) / 2;
            loc = ((a[lena-i]-'0') + (b[lenb-i]-'0') + loc) % 2;
            ans[lena+1-i] = char(loc+'0');
            loc = left;
        }
        for(int i=lenb+1;i<=lena;i++){
            left = ((a[lena-i]-'0') + loc) / 2;
            loc = ((a[lena-i]-'0') + loc) % 2;
            ans[lena+1-i] = char(loc+'0');
            loc = left;        
        }
        if (loc != 0) ans[0] = '1';
        else ans.erase(0,1);
        return ans;
    }
    
    
int main(){
    cout<<"067_Add Binary:Input a string s and t (two binary strings), return their sum (also a binary string)."<<endl;
    string s,t;
    cin>>s>>t;
    while(s != "-1" && t != "-1"){
        cout<<addBinary(s,t)<<endl;
        cin>>s>>t;
    }
    
    return 0;
}
