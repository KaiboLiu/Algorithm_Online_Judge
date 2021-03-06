//040_Combination_Sum_II.h
//给一个大序列和一个值t，求所有非降子序列，使得和为t，大序列的值只能用一次
    vector<int> a;
    vector<vector<int> > ans;
    
    void solve(vector<int>& candidates, int t,int k){
        //此次所剩的和为t，总序列第k个元素开始
        if (t == 0){
            ans.push_back(a);
            
            for(int i=0;i<a.size();i++) cout<<a[i]<<" ";//提交时要删掉，不删的话输出也没错，因为只判返回值不用输入输出流
            cout<<endl;//提交时要删掉，不删的话输出也没错，因为只判返回值不用输入输出流
            return;
        }
        
        for(int i=k;i<candidates.size();i++){
            if (candidates[i] > t) break;
            else{
                
                a.push_back(candidates[i]);
                solve(candidates,t-candidates[i],i+1);
                a.pop_back();
                while (i<candidates.size()-1 && candidates[i] == candidates[i+1]) i++;
            }
        }
        
    }
    
    
    vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
        a.clear();
//        a.resize(target/candidates[0]+1);
        sort(candidates.begin(),candidates.end());
        solve(candidates,target,0);
        return ans;
    }
    
    
int main(){
    cout<<"040_Combination Sum II:Input array n,{an} and Target,Output the Combinations that sums to Target"<<endl;
    vector<int> arr;
    int n,t;
    cin>>n;
    arr.resize(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    cin>>t;
    combinationSum2(arr,t);
    //cout<<endl;
        
}
