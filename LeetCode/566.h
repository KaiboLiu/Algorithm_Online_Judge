    vector<vector<int> > matrixReshape(vector<vector<int> >& nums, int r, int c) {
        int h = nums.size();
        if (h < 1) return nums;
        int w = nums[0].size();
        if (w < 1) return nums;
        if (h*w != r*c) return nums;
        int tmp;
        vector<vector<int> > ans(r,vector<int>(c,0));
        for (int i=0;i<h;i++)
            for (int j=0;j<w;j++){
                tmp = i*w+j;
                ans[tmp/c][tmp%c] = nums[i][j];
            }
        return ans;
    }
    
    
int main(){
    vector<vector<int> > a(2,vector<int>(2,0));
    cout<<"OK"<<endl;
    a[0][0] = 1;
    a[0][1] = 2;
    a[1][0] = 3;
    a[1][1] = 4;
    vector<vector<int> > b = matrixReshape(a,1,4);
    for (int i=0;i<b.size();i++){
        for (int j=0;j<b[0].size();j++)
            cout<<b[i][j]<<" ";
        cout<<endl;
    }
    return 0;
    
}