//566_Reshape_the_Matrix.h
//35ms  100%

/*
Total Accepted: 89871
Total Submissions: 225631
Instruction: LeetCode 566 - Reshape the Matrix - [E]
Developer: lrushx
Process Time: Apr 29, 2017
*/


/*
In MATLAB, there is a very useful function called 'reshape', which can reshape a matrix into a new one with different size but keep its original data.

You're given a matrix represented by a two-dimensional array, and two positive integers r and c representing the row number and column number of the wanted reshaped matrix, respectively.

The reshaped matrix need to be filled with all the elements of the original matrix in the same row-traversing order as they were.

If the 'reshape' operation with given parameters is possible and legal, output the new reshaped matrix; Otherwise, output the original matrix.

Example 1:
Input: 
nums = 
[[1,2],
 [3,4]]
r = 1, c = 4
Output: 
[[1,2,3,4]]
*/

//给一个matrix(二维数组)和r，c，
//如果可以reshape成r*c，就给出答案，否则给原始matrix
//比较简单


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