//046_Permutations.h
//给一个数组，输出全排列
//先排序，再用回溯，注意重复数字处理，本位置选择后，可以跳过相同数，但下一轮要注意不被跳过


//private:
   vector<bool> used;
    vector<int> ans1;
    vector<vector<int> > ans;
    int cnt = 0;
//public:
    void onesolution(vector<int>& a,int k,int n){
        if (k == n){
            ans.push_back(ans1);
            //以下提交时要删掉，不删的话输出也没错，因为只判返回值不用输入输出流
            cnt++;
            cout<<"---"<<cnt<<':';
            for(int i=0;i<n;i++) cout<<ans1[i];
            cout<<"---"<<endl;
            ////以上提交时要删掉，不删的话输出也没错，因为只判返回值不用输入输出流
            return;
        }
        int i=0;
        while(i < n){

            if (!used[i]){
                ans1.push_back(a[i]);
                //cout<<k<<':'<<a[i]<<"  ";
                used[i] = true;
                onesolution(a,k+1,n);
                ans1.pop_back();
                used[i] = false;
                
                while (i < n-1){
                    if (a[i] == a[i+1]) i++;
                    else break;
                }
            }
            i++;
        }
        return;
        
    }

    vector<vector<int> > permute(vector<int>& nums) {
        vector<int> a = nums;
        int len = a.size();
        sort(a.begin(),a.end());
        for (int i=0;i<len;i++){  used.push_back(false);}
        onesolution(a,0,len);
        return ans;
    }
    

int main(){
    cout<<"031_Next Permutation:Input n and {an}, return the lexicographically next greater permutation."<<endl;
    int n;
    vector<int> nums;
    cin>>n;
    while(n >0){
        
        nums.resize(n);
        for(int i=0;i<n;i++) cin>>nums[i];
        cnt = 0;
        permute(nums);       
      
        cin>>n;
    }
    
    return 0;
}
    
