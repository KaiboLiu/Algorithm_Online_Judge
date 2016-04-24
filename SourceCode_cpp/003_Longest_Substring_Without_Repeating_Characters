//003_Longest_Substring_Without_Repeating_Characters.h
//给一个字母串，返回最长不重复连续子串的长度
//按i遍历，维护包含第i个在内的最长不重复子串，用hash表判重，若有重，则删除重复字符之前的部分，加上i，构成新的不重复子串，更新子串最的大长度
//ASCII码总数256个，可用bool c[256]，不必用map<char,bool>，前者AC用12ms(网站最优)后者64ms

    int lengthOfLongestSubstring(string s) {
        int len = s.size(),ans=0,count=0;
        if (len <= 1) return len;
        bool alpha[256] = {false};
        for (int i=0;i<len;i++){
            if(!alpha[s[i]]){
                alpha[s[i]] = true;
                count++;
            }else{
                if (count > ans) ans = count;
                int j = i-count;
                while (s[j] != s[i]){
                    alpha[s[j]] = false;
                    count--;
                    j++;
                }
            }            
        }
        if (count > ans) ans = count;
        return ans;
    }
    
int main(){
    cout<<"003_Longest Substring Without Repeating Characters:Input a string until -1, find the length of the longest substring without repeating characters. "<<endl;
    string s;
    cin>>s;
    while(s != "-1"){
        cout<<lengthOfLongestSubstring(s)<<endl;
        cin>>s;
    }
    
    return 0;
}	
