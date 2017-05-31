//341_Flatten_Nested_List_Iterator.h
//16ms	99.85%

/*
Total Accepted: 35476
Total Submissions: 87406
Instruction: LeetCode 341 - Flatten Nested List Iterator - [M]
Developer: lrushx
Process Time: May 27, 2017
*/

/*
Given a nested list of integers, implement an iterator to flatten it.
Each element is either an integer, or a list -- whose elements may also be integers or other lists.
Example 1:
Given the list [[1,1],2,[1,1]],
By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,1,2,1,1].
Example 2:
Given the list [1,[4,[6]]],
By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,4,6].
*/


//给一个结构I，可以是一个数字，也可以是一个列表，每个元素是数字或者列表，给这个解构的一个数列vector<I>，扁平化为一个数组
//初始化：遍历这个数列，通过内建函数如果是单个数，就加到res数组中，否则就是个新的嵌套数列，递归其即可；
//next和判断是否有next：直接使用全局数组res即可
//题目给的提示是stack，有空可以做做


/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
 
 
class NestedIterator {
private:
    vector<int> v;
    int p = 0;
    
    void init(vector<NestedInteger> &nestedList){
        int len = nestedList.size();
        for (int i=0;i<len;i++)
            if (nestedList[i].isInteger()) 
                v.push_back(nestedList[i].getInteger());
            else init(nestedList[i].getList());        
    }
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        init(nestedList);
    }

    int next() {
        return v[p++];
    }

    bool hasNext() {
        return (p < v.size());
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */