    //077_Combinations.h
    //给n，k，输出1~n中C(n,k)的所有组合

//    bool flag[30] = {false};
//private:
    vector<int> ans1;
    vector<vector<int> > ans;

    void onesolution(int n,int k,int j,int s){
        //参数中：n,k与程序输入的n,k相同,j为当前组合中第j个元素,s为遍历的起始数值（因为必须升序，所以不能找更小的数）
        if (j == k){
            ans.push_back(ans1);
            
            for(int i=0;i<k;i++) cout<<ans1[i]<<" ";
            cout<<endl;
            
            return;
        }
        for(int i=s;i<=n;i++){
            ans1[j] = i;
            onesolution(n,k,j+1,i+1);
        }
        return;
        
    }
    
    vector<vector<int> > combine(int n, int k) {
        ans1.resize(k);
        onesolution(n,k,0,1);//从组合数的第0元素开始
        return ans;
    }


    
    int main(){
        cout<<"077_Combinations:Input n and k,Output the Combinations of C(k,n)"<<endl;
        int n,k;
        cin>>n>>k;
        combine(n,k);
//        cout<<endl;
        
    }
