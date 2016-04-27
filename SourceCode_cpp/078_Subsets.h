//078_Subsets.h
//给一个元素不重复的数组，求所有升序子集
 
//private:
    vector<int> ans1;
    vector<vector<int> > ans;

//public:   
    void solve(vector<int>& nums,int pos){
        if (pos >= nums.size()){
            ans.push_back(ans1);
            
            for(int i=0;i<ans1.size();i++) cout<<ans1[i]<<" ";//提交时要删掉，不删的话输出也没错，因为只判返回值不用输入输出流
            cout<<endl;//提交时要删掉，不删的话输出也没错，因为只判返回值不用输入输出流

            return;
        } 
        
        solve(nums,pos+1);
        ans1.push_back(nums[pos]);
        solve(nums,pos+1);
        ans1.pop_back();
        return;
        
    }
    vector<vector<int> > subsets(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        solve(nums,0);
        return ans;
        
    }
    
    
    
int main(){
    cout<<"078_Subsets:Input array n and {an},Output all subsets"<<endl;
    vector<int> arr;
    int n;
    cin>>n;
    arr.resize(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    subsets(arr);
    return 0;
}
