//380_Insert_Delete_GetRandom_O(1).h
//49ms	96.49%

/*
Total Accepted: 28606
Total Submissions: 73571
Instruction: LeetCode 380 - Insert Delete GetRandom O(1) - [M]
Developer: lrushx
Process Time: May 19, 2017
*/


/*
Design a data structure that supports all following operations in average O(1) time.

insert(val): Inserts an item val to the set if not already present.
remove(val): Removes an item val from the set if present.
getRandom: Returns a random element from current set of elements. Each element must have the same probability of being returned.
*/


//实现一个数据结构，可以在O(1)时间内插入、删除和随机取数，若插入已有数或者删除没有的数则返回false
//用vector num[i]储存第i个插入的元素，用unordered_map m作为hash table储存某元素在num中的下标即可，每次数据是否存在用m.find()是否等于m.end()判断，删除时用num最后一个替换被删除的元素再让num pop最后一个即可
//map的删除元素直接用m.erase(key1)；vector取最后元素可以用v.back()；vector加元素可以用v.emplace_back(val)或者v.push_back(val)


class RandomizedSet {
private:
    vector<int> num;
    unordered_map<int,int> m;
    
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (m.find(val) != m.end()) return false;
        m[val] = num.size();
        num.push_back(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (m.find(val) == m.end()) return false;
        int last = num.back();
        num[m[val]] = last;
        m[last] = m[val];
        m.erase(val);
        num.pop_back();
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return num[rand() % num.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */