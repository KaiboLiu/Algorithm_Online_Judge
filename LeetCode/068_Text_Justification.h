//068_Text_Justification.h
//给一组单词和长度L，按照每行L分配单词，并且每行左右顶格，中间空格均分，若不能均分则左边多一些
//

    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int p=0,q=0,sum,space0,space1;
        int len = words.size();
        
        vector<string> ans;
        ans.clear();
        if (len == 0 || (len == 1 && words[0] == "")) {
            string s="";
            s.insert(s.end(),maxWidth,' ');
            ans.push_back(s);
            return ans;
        }
        
        while (p < len){
            sum = 0;
            while (q < len && (sum+words[q].size()+1 <= maxWidth+1)){
                sum = sum + words[q].size()+1;//本行占用位置数包括每个单词+1个空格
                q++;//下标往后走1个
            }
            string s="";

            q--;            
            space0 = maxWidth+1-sum;
            if (p == q || q == len-1) {//本行只有一个单词，或者是最后一行，则在右边补足空格
                for (int i=p;i<q;i++)
                    s += words[i]+ " ";
                s += words[q];
                s.insert(s.end(),space0,' ');
                ans.push_back(s);
            }else{
                space1 = space0 % (q-p);
                space0 = space0 / (q-p);
            
                for (int i=p;i<q;i++){//添加本行除了最后一个单子之外别的单词和空格
                    s += words[i];
                    s.insert(s.end(),space0+1,' ');
                    if (space1 > 0) {   s += " ";   space1--; }
                }
                s += words[q];
                ans.push_back(s);
            }
            q++;
            p = q;
        }
        return ans;
    }

int main(){
    cout<<"068_Text Justification:Input n, n words and length L,format the text."<<endl;
    int n,l;
    string s;
    vector<string> words,ans;

    cin>>n;
    while(n >0){
        words.clear();
        
        for(int i=0;i<n;i++) {
            cin>>s;
            words.push_back(s);
        }
        cin>>l;
        ans = fullJustify(words,l);
        
        for(int i=0;i<ans.size();i++) 
            cout<<ans[i]<<endl;
        
        cin>>n;
    }
    
    return 0;
}    
