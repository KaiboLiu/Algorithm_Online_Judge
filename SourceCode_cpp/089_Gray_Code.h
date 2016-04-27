    //089_Gray_Code.h
//输出所有二进制长度为n，并且相邻数字只有1位差别的数列
    
    vector<int> grayCode(int n) {
        int value = 0,tmp,nn = 1 << n,v;
        vector<int> ans;
        if (n < 0) return ans;
        
        bool flag[1048576] = {false};
        flag[0] = true;
        ans.push_back(0);
        
        for(int i=1;i<nn;i++){//第i个数字
            for(int k=0;k<n;k++){//从右往左计算第k+1位为1的2^k用于换位
                tmp = 1 << k;
                v = value ^ tmp;
                if (!flag[v]){
                    flag[v] = true;
                    ans.push_back(v);
                    value = v;
                    break;
                }
            }
        }
        return ans;
    }
    
    int main(){
        cout<<"089_Gray Code：输入n作为二进制的位数，输出所有二进制长度为n，并且相邻数字只有1位差别的数列";
        int n;
        cin>>n;
        vector<int> a = grayCode(n);
        for (int i=0;i<a.size();i++)
            cout<<a[i]<<" ";
        cout<<endl;
        
        }
