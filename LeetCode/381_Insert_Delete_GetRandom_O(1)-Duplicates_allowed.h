//381_Insert_Delete_GetRandom_O(1)-Duplicates_allowed.h
//52ms	95.70%

/*
Total Accepted: 13509
Total Submissions: 47325
Instruction: LeetCode 381 - Insert Delete GetRandom O(1) - Duplicates allowed - [H]
Developer: lrushx
Process Time: May 19, 2017
*/


/*
Design a data structure that supports all following operations in average O(1) time.

Note: Duplicate elements are allowed.
insert(val): Inserts an item val to the collection.
remove(val): Removes an item val from the collection if present.
getRandom: Returns a random element from current collection of elements. The probability of each element being returned is linearly related to the number of same value the collection contains.
*/


//实现一个数据结构，可以在O(1)时间内插入、删除和随机取数，若插入已有数依旧有效，将多存入一个数，并且插入已有的数或者删除没有的数要返回false
//用vector<pair> num[i]储存第i个插入的元素val，以及其在map相应list的位置。用unordered_map<int,list> m作为hash table储存某元素在num中的各个下标，每次数据是否存在用m.find()是否等于m.end()判断，删除时用num最后一个替换被删除的元素再让num pop最后一个，但是最后这个元素在num中的新位置要在m中更新。
//num还是需要用pair，因为map的list并不是永远都删最后一个，毕竟在remove时会把num最后一个往前提，使的下标从同类最后一个变成前几个


class RandomizedCollection {
private:
    vector<pair<int,int>> num;
    unordered_map<int,vector<int>> m; //m.second[i] is the pos of m.fisrt in num
    
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool res = m.find(val) == m.end();
        m[val].push_back(num.size());
        num.push_back(make_pair(val,m[val].size()-1));
        return res;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if (m.find(val) == m.end()) return false;
        auto last = num.back(); 
        num[m[val].back()] = last;  //m[val].back() is the pos of last val in num
        m[last.first][last.second] = m[val].back();
        m[val].pop_back();
        if (m[val].empty()) m.erase(val);
        num.pop_back();
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return num[rand() % num.size()].first;
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */