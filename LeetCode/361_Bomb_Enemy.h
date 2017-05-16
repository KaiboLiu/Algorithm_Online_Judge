//361_Bomb_Enemy.h




    int maxKilledEnemies(vector<vector<char> >& grid) {
        int h=grid.size(),w=h==0?0:grid[0].size();
        if (h*w == 0) return 0;
        vector<vector<int> > x(h,vector<int>(w,0));
        vector<vector<int> > y(h,vector<int>(w,0));
        int i,j,k,res=0;
        bool to_do_x,to_do_y;
        for (i=0;i<h;i++)
            for (j=0;j<w;j++)
                if (grid[i][j] == '0'){
                    to_do_x = true;
                    to_do_y = true;
                    if (i > 0 && grid[i-1][j] == '0'){
                        to_do_y = false;
                        y[i][j] = y[i-1][j];
                    }
                    if (j > 0 && grid[i][j-1] == '0'){
                        to_do_x = false;
                        x[i][j] = x[i][j-1];
                    }
                    if (to_do_x){
                        k = j-1;
                        while (k >= 0 && grid[i][k] != 'W'){
                            if (grid[i][k--] == 'E') x[i][j]++;
                        }
                        k = j+1;
                        while (k < w && grid[i][k] != 'W'){
                            if (grid[i][k++] == 'E') x[i][j]++;
                        }
                    }
                    if (to_do_y){
                        k = i-1;
                        while (k >= 0 && grid[k][j] != 'W'){
                            if (grid[k--][j] == 'E') y[i][j]++;
                        }
                        k = i+1;
                        while (k < h && grid[k][j] != 'W'){
                            if (grid[k++][j] == 'E') y[i][j]++;
                        }
                    }
                    if (x[i][j]+y[i][j] > res) res = x[i][j]+y[i][j];
                    
                }
        return res;
                
        
    }
    
    
int main(){
    vector<vector<char> > grid;
    grid.resize(2);
    grid[0].resize(10);
    grid[1].resize(10);
    for (int i=0;i<10;i++) grid[0][i] = '0';
    for (int i=0;i<10;i++) grid[1][i] = 'E';
    cout<<maxKilledEnemies(grid)<<endl;
    
}