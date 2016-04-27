//076_Minimum_Window_Substring.h
//给一个S和T，求S中最短的一段，包含T中所有字符（若T中有重复，这一段也要重复）
//用int c[128]表示所有字符出现次数的hash

    string minWindow(string s, string t) {
        //ASCII字符共128个
        //注意，t中若有重复，那么在答案中也要体现重复
        int l1 = s.size(),l2 = t.size(),n = 0;//n为每次搜索时满足条件的字符个数
        int anspos=0,anslen=l1;
        
        if (l2 > l1) return "";//t中字符数比s的长度大
        
        bool flag = false;
        int exist[128];
        int num[128];//num为某字符出现的次数，>0即满足要求，但是涉及到前一个pointer后移会使某个字符计数减少甚至为负，故用int
        memset(exist,0,sizeof(int)*128);
        
        for (int i=0;i<l2;i++){
            //exist[int(t[i])] = true;
            exist[int(t[i])]++;
        }

        int p=0,q,nextp;

        while (p < l1){
            memset(num,0,sizeof(int)*128);
            q = p;
            nextp = -1;
            n = 0;
            while (n < l2 && q < l1){//向后移动pointer直到pq之间包含所有t中字符
                if (exist[int(s[q])] > 0){
                    if (num[int(s[q])] < exist[int(s[q])]) n++;
                    num[int(s[q])]++;
                    if (q != p && nextp == -1) nextp = q;
                }
                q++;
            }
            if (n == l2){
                while (p < q){//从前面往后删重复的
                    if (exist[int(s[p])] > 0)
                        if (num[int(s[p])] > exist[int(s[p])]) num[int(s[p])]--;
                        else break;
                    p++;
                }
                flag = true;
                if (q-p < anslen){  anslen = q-p;   anspos = p;}
            }else break;
            if (nextp >= 0) p = nextp; else p++;
        }
        if (flag) return s.substr(anspos,anslen);
        return "";
        
    }
    
int main(){
    cout<<"076_Minimum Window Substring:Input s and t, find the minimum window in S which will contain all the characters in T."<<endl;
    string s,t;
    
    cin>>s>>t;
    while(s != "-1"){
        cout<<minWindow(s,t);
        cout<<"!"<<endl;
        cin>>s>>t;
    }    
    return 0;
}
