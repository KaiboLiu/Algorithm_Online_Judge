?????



#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

// 注意 ? ? O2 O2 的输入
// 注意 ? I1 I1 的输入

int main(){
    //freopen("1.in","r",stdin);
    int n;
    while (cin >> n){
        //std::unordered_map<int,int> m;
        //std::unordered_map<int,int>::iterator it;
        
        int f[500001] = {0};
        int m[100001] = {0};
        memset(m,0,sizeof(int)*100001);
        int a,unknow=0,res = -1;
        char c;
        for(int i = 0; i < n; i++){
            cin>>c;
            if (c == '?') {
                f[i] = 0;
                unknow++;      continue;
            }
            cin>>a;
            
            if (res > 0) continue;
            //it = m.find(a);
            if (c == 'I'){
                f[i] = a;
                //if (it != m.end()){// a在记录中
                if (m[a] > 0){// a在记录中
                    if (unknow){    // a曾在?中被output
                        for (int j = i-1;j>=0;j--)
                            if (f[j] == 0) {
                                f[j] = -a;
                                break;
                            }else if (f[j] == f[i]){
                                res = i+1;
                                break;
                            }
                        unknow--;	
                    }else{			// 没有?，a未被output，不应被再次记录
                        res = i+1;   continue;
                    }
                }else m[a] = 1;		// a不在记录中，加入记录
            }else if (c == 'O'){
                f[i] = -a;
                //if (it != m.end())// a在记录中
                if (m[a] > 0)
                    m[a] = 0;
                    //m.erase(it);
                else {				// a不在记录中
                    if (unknow){	// a曾在?中被input
                        for (int j = i-1;j>=0;j--)
                            if (f[j] == 0) {
                                f[j] = a;
                                break;
                            }else if (f[j] == f[i]){
                                res = i+1;
                                break;
                            }
                        unknow--;
                    }else{
                        res = i+1;   continue;
                    }
                }
            }
        }
        cout <<res <<endl;
    }
    return 0;
}
