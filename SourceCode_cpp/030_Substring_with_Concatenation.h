//030_Substring_with_Concatenation.h
//给一个字符串s和n个索引串，在s中找到n个串随意全排列出来的子串的下标

    vector<int> findSubstring(string s, vector<string>& words) {
        map<string,int> m,m1;
        vector<int> ans;
        bool flag,flag2;
        int len = s.size(),n = words.size();
        if (len ==0 || n == 0) return ans;
        int len1 = words[0].size();
        int sublen = len1 *n,i,j,k;
        if (len < sublen || len1 == 0) return ans;//s比子串长度n * len1短 或者子串长为空；
        
        for(j=0;j<n;j++){
            m[words[j]]++;
        }
        for(i=0;i<=len - len1;i++){   //i到i+sublen-1，长度为sublen，共n个len1长
            flag = true;
            flag2 = false;//本轮有否出现过map更新
            for (k=0;k<n;k++){
                string tmp = s.substr(i+k*len1,len1);
                if (m[tmp] >0 && m1[tmp]<m[tmp]) {
                    flag2 = true;
                    m1[tmp]++;
                }
                else {flag = false; break;}
                
            }
            if (flag) {ans.push_back(i);cout<<i<<" "<<endl;}
            if (flag2) 
                for(j=0;j<n;j++)   m1[words[j]] = 0;
        }
        return ans;
    }
    
    
int main(){
    cout<<"030_Substring with Concatenation:Input a string, s, and a list of words with same length. Output all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters."<<endl;
    string s,tmp;
    cin>>s;
    vector<string> words;
    cin>>tmp;
    while(tmp != "-1"){
        words.push_back(tmp);
        cin>>tmp;
    }
    findSubstring(s,words);
    
    return 0;
}
