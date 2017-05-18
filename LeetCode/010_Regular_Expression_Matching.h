//010_Regular_Expression_Matching.h
//9ms	91.34%





    bool isMatch(string s, string p) {
        // no such inputs: no */. in s; no "a**b","*b" in p
        int len1=s.size(),len2=p.size(),i,j=1;
        if (len2 == 0) return len1 == 0;
        if (len1 == 0) {
            len1++; len2++;
            s = "a"+s; p = "a"+p;
        }
        bool f[len1+1][len2+1] = {};
        f[0][0] = true;
        while (j < len2 && p[j] == '*') {
            f[0][j+1] = true;
            j += 2;
        }
        for (i=0;i<len1;i++)
            for (j=0;j<len2;j++)
                if (p[j] == '*') f[i+1][j+1] = f[i+1][j-1] || f[i+1][j] || (f[i][j] && s[i] == p[j-1])  || (p[j-1] == '.' && f[i][j+1]);
                // *=precceding*0 || *=precceding*1 || *=precceding*2 || * follows .
                else f[i+1][j+1] = f[i][j] && (s[i] == p[j] || p[j] == '.');
        //cout<<f[]
        return f[len1][len2];
    }
    }
    
    
int main(){
    string s = "aaabaaaababcbccbaab";
    string p = "c*c*.*c*a*..*c*";
    cout<< isMatch(s,p) <<endl;
    
}
