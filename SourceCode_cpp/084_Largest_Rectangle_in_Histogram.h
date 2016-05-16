//084_Largest_Rectangle_in_Histogram.h
//24ms 77.37%

/**
 * Instruction：LeetCode 084 - Largest Rectangle in Histogram - [H]
 * Developer：lrushx
 * Process Time：May 16, 2016
 */
 
//给一些并排直方图的高，求出最大的单独矩形面积
//用一个栈存递增高度的索引，0入栈，题目数组尾部加个0。维护这个栈，从1开始遍历i，当h[i]遇到比h[栈顶元素]小，出栈，计算当前面积，出栈，直到h[i]比栈顶大，i入栈。


    int largestRectangleArea(vector<int>& heights) {
        heighs.push_back(0);
        int l = heights.size(),t;
		int ans = 0;
		if (l == 1) return 0;
		stack<int> bar;
		while (!bar.empty()) bar.pop();
		bar.push(0);
		for (int i=1;i<l;i++){
			while (!bar.empty() && heights[i] < heights[bar.top()]){
				t = bar.top();
				bar.pop();
				int tmp = heights[t] * (bar.empty()? i : i - bar.top() - 1);
				if (tmp > ans) ans = tmp;
			}
			bar.push(i);
		}
		return ans;		
    }
	
	
int main(){
    cout<<"084_Largest_Rectangle_in_Histogram:Input n and {an} representing the histogram's bar height where the width of each bar is 1, return the area of largest rectangle in the histogram."<<endl;
    int n;
    vector<int> nums;
    cin>>n;
    while(n >0){        
        nums.resize(n);
        for(int i=0;i<n;i++) cin>>nums[i];
        cout<<largestRectangleArea(nums)<<endl;       
      
        cin>>n;
    }
    
    return 0;
}
    
