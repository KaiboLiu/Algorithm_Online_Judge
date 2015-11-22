class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> result;
        map<int, int> m;
        if (numbers.size() < 2)
            return result;
        for (int i = 0; i < numbers.size(); i++)
            m[numbers[i]] = i;

        map<int, int>::iterator it;
        for (int i = 0; i < numbers.size(); i++) {
            if ((it = m.find(target - numbers[i])) != m.end())
            {
                if (i == it->second) continue;
                result.push_back(i+1);
                result.push_back(it->second+1);
                return result;
            }
        }
        return result;
    }
};
