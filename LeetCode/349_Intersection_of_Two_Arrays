//349_Intersection_of_Two_Arrays
//[E]
//12ms

//Given two arrays, write a function to compute their intersection.Each element in the result must be unique.

//用2 point方法，先把2个数组排序，i和j分别指向2个数组，while循环，哪个元素小就++，当元素相等时，ans数组push一个，i和j各自++，然后ij各自往后处理重复元素，复杂度O(m+n)



class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int l1 = nums1.size(),l2 = nums2.size();
        vector<int> ans;
        if ((l1 && l2) == 0) return ans;
        int i=0,j=0;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        while (i < l1 && j < l2){
            while (i < l1 && nums1[i] < nums2[j]) i++;
            while (j < l2 && nums1[i] > nums2[j]) j++;
            if (nums1[i] == nums2[j]){
                ans.push_back(nums1[i]);
                i++;
                j++;
                while (i < l1 && nums1[i-1] == nums1[i]) i++;
                while (j < l2 && nums2[j-1] == nums2[j]) j++;
            }
        }
        return ans;
        
    }
};
