//631. Design Excel Sum Formula.h
//9ms
//LeetCode Contest 38

/*
Total Accepted: 32
Total Submissions: 348
Instruction: LeetCode 631 - Design Excel Sum Formula - [H]
Developer: lrushx
Process Time: June 25, 2017
*/

/*
Your task is to design the basic function of Excel and implement the function of sum formula. Specifically, you need to implement the following functions:
Excel(int H, char W): This is the constructor. The inputs represents the height and width of the Excel form. H is a positive integer, range from 1 to 26. It represents the height. W is a character range from 'A' to 'Z'. It represents that the width is the number of characters from 'A' to W. The Excel form content is represented by a height * width 2D integer array C, it should be initialized to zero. You should assume that the first row of C starts from 1, and the first column of C starts from 'A'.
void Set(int row, char column, int val): Change the value at C(row, column) to be val.
int Get(int row, char column): Return the value at C(row, column).
int Sum(int row, char column, List of Strings : numbers): This function calculate and set the value at C(row, column), where the value should be the sum of cells represented by numbers. This function return the sum result at C(row, column). This sum formula should exist until this cell is overlapped by another value or another sum formula.
numbers is a list of strings that each string represent a cell or a range of cells. If the string represent a single cell, then it has the following format : ColRow. For example, "F7" represents the cell at (7, F).
If the string represent a range of cells, then it has the following format : ColRow1:ColRow2. The range will always be a rectangle, and ColRow1 represent the position of the top-left cell, and ColRow2 represents the position of the bottom-right cell.
*/

class Excel {
private:
    int SIZE = 676,h,w;
    int T[676];
    int comp[676][676]={0};
    
    void deepset(int ind,int delt){
        //cout << "deeper: "<<ind / w <<" "<<ind % w<<endl;
        int delta[676];
        T[ind] -= delt;
        for (int i=0;i<SIZE;i++) {
            delta[i] = comp[i][ind] * delt;
            T[i] += delta[i];
        }
        for (int i=0;i<SIZE;i++) 
            if (i != ind && comp[i][ind] > 0) deepset(i,delta[i]);
    }
    
public:
    Excel(int H, char W) {
        h = H;
        w = W-'A'+1;
        SIZE = h*w;
        memset(comp,0,SIZE*SIZE*sizeof(bool));
        memset(T,0,SIZE*sizeof(int));
        for (int i=0;i<SIZE;i++) comp[i][i] = 1;
    }
    
    void set(int r, char c, int v) {
        int ind = (r-1)*w+c-'A';
        v -= T[ind];
        int delta[676];
        //T[ind] = v;
        for (int i=0;i<SIZE;i++) {
            delta[i] = comp[i][ind] * v;
            T[i] += delta[i];
        }
        for (int i=0;i<SIZE;i++) 
            comp[ind][i] = 0;
        comp[ind][ind] = 1;
        for (int i=0;i<SIZE;i++) 
            if (i != ind && comp[i][ind] > 0) deepset(i,delta[i]);
        return;
    }
    
    int get(int r, char c) {
        int ind = (r-1)*w+c-'A';
        return T[ind];
    }
    
    int sum(int r, char c, vector<string> strs) {
        int nb = strs.size(),ind = (r-1)*w+c-'A',i,j,len,r1,ind1,val=0;
        char c1;
        for (i=0;i<nb;i++){
            string s = strs[i];
            len = s.size();
            j = 0;
            if (len < 4){ // single cell
                c1 = s[j++];
                r1 = 0;
                while (j < len) r1 = r1*10+s[j++]-'0';
                ind1 = (r1-1)*w+c1-'A';
                comp[ind][ind1] += 1;
                val += T[ind1];
                //cout<<c1<<" "<<r1<<endl;
            }else{
                char col[2];
                int row[2];
                int count = 0;
                s += ":";
                len++;
                while (j < len){
                    col[count] = s[j++];
                    row[count] = 0;
                    while (j < len && s[j] != ':') row[count] = row[count]*10+s[j++]-'0';
                    j++;
                    count++;
                }
                for (r1 = row[0];r1 <= row[1];r1++){
                    int r0 = (r1-1)*w;
                    for (c1 = col[0];c1 <= col[1];c1++){
                        ind1 = r0+c1-'A';
                        comp[ind][ind1] += 1;
                        val += T[ind1];
                    }
                }
                //cout<<col[0]<<" "<<row[0]<<" "<<col[1]<<" "<<row[1]<<endl;
            }
        }
        T[ind] = val;
        //cout<<endl;
        return val;
        
    }
};

/**
 * Your Excel object will be instantiated and called as such:
 * Excel obj = new Excel(H, W);
 * obj.set(r,c,v);
 * int param_2 = obj.get(r,c);
 * int param_3 = obj.sum(r,c,strs);
 */
