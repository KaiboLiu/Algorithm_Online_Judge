//380_Insert_Delete_GetRandom_O(1).py
//104ms	90.34%

/*
Total Accepted: 56.1K
Total Submissions: 140.8K
Instruction: LeetCode 380 - Insert Delete GetRandom O(1) - [M]
Developer: lrushx
Process Time: Mar 18, 2018
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


from collections import defaultdict
from random import randint
class RandomizedSet:
    
    def __init__(self):
        """
        Initialize your data structure here.
        """
        from collections import defaultdict
        self.a = []
        #self.idx = {}
        self.idx = defaultdict(lambda:-1)
        

    def insert(self, val):
        """
        Inserts a value to the set. Returns true if the set did not already contain the specified element.
        :type val: int
        :rtype: bool
        """
        #if val in self.idx and self.idx[val] >= 0: return False
        if self.idx[val] >= 0: return False
        self.idx[val] = len(self.a)
        self.a.append(val)
        return True
        
    def remove(self, val):
        """
        Removes a value from the set. Returns true if the set contained the specified element.
        :type val: int
        :rtype: bool
        """
        #if val not in self.idx or self.idx[val] < 0: return False
        if self.idx[val] < 0: return False
        pos = self.idx[val]
        self.a[pos] = self.a[-1]
        self.idx[self.a[pos]] = pos
        self.idx[val] = -1
        self.a.pop()
        return True

    def getRandom(self):
        """
        Get a random element from the set.
        :rtype: int
        """
        return self.a[randint(0,len(self.a)-1)]
        


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()
