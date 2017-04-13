//126_Word_Ladder_II.h
//给一个字典，起始词和目标词，输出从起始词到目标词，每次改一位字母，到达目标所需的最小步数（中间词都要在字典中），
//输出如此变幻的最小步数的所有具体变幻序列

//BSF，应根据题意，字母为小写，可以每位改写字母a~z判断是否在字典中
//——因为题目给的字典是unordered_set，不排序但是可以查找，没必要遍历字典，BFS时每个元素的复杂度为O(26*len)
//在自己构造的结构WordNode中多加一个lastword的成员表示变幻序列中的父元素


    struct WordNode{
        string word;
        WordNode* lastword;
        int step;
        int pos;
        WordNode(string s,int x,int y):word(s),lastword(NULL),step(x),pos(y){}
        
    };
    
    void solution1(WordNode* top,vector<string> & seq){
        
        if (top == NULL) return;
        //cout<<top->word<<" "<<top->lastword->word<<top->step<<" ";
        solution1(top->lastword,seq);
        seq.push_back(top->word);
        return;
     }
     
     
    //vector<vector<string> > findLadders(string start, string end, unordered_set<string>& dict) {
    vector<vector<string> > findLadders(string start, string end, vector<string>& dict) {
        vector<vector<string> > ans;
        vector<string>  ans1;
        
        if (dict.empty()) return ans;
        int len = start.size(),ans_step = INT_MAX;

        queue<WordNode*> q;
        string s2;
        //unordered_set<string>::iterator it;
        vector<string>::iterator it;
        
        while (!q.empty()) q.pop();
        q.push(new WordNode(start,1,-1));
        //if (dict.find(end) == dict.end()) dict.insert(end);
        if (find(dict.begin(),dict.end(),s2) == dict.end()) dict.push_back(end);
        
        while (!q.empty()){
            WordNode* top = q.front();
            if (top->step > ans_step) break;
            if (top->word == end && top->step <= ans_step) {
                ans_step = top->step;
                ans1.clear();
                solution1(top,ans1);
                ans.push_back(ans1);
            }else{
            s2 = top->word; 
            for (int i=0;i<len;i++){
                if (i == top->pos) continue;
                for (char c='a';c<='z';c++){
                    if (top->word[i] != c) s2[i] = c; else continue;
                    //it = dict.find(s2);
                    it = find(dict.begin(),dict.end(),s2);
                    if (it != dict.end()){
                        WordNode* tmp = new WordNode(s2,top->step+1,i);
                        tmp->lastword = top;
                        cout<<s2<<" "<<tmp->lastword->word<<" "<<top->word<<" "<<tmp->step<<',';
                        q.push(tmp);
                        //if (s2 != end) dict.erase(it);//若为目标词，则不要删
                    }
                }
                s2[i] = top->word[i];
            }
            }
            q.pop();
        }
        return ans;
    }
    
int main(){
    cout<<"127_Word_Ladder:Input start, and {a,b}*n to form a collection of n intervals, merge all overlapping intervals."<<endl;
    int n;
    string start,end,str;
    vector<string> dict;

    cin>>n;
    while(n >0){
        dict.clear();
        cin>>start>>end;
        for(int i=0;i<n;i++) {
            cin>>str;
            //dict.insert(str);
            dict.push_back(str);
        }
        vector<vector<string> > ans = findLadders(start,end,dict);
        for(int i=0;i<ans.size();i++){
            for (int j=0;j<ans[i].size();j++)
                cout<<ans[i][j]<<" ";
            cout<<endl;
                
        }
        
        cin>>n;
    }
    
    return 0;
}    
