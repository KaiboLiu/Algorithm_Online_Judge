//406_Queue_Reconstruction_by_Height.h
//32ms	99.56%

/*
Total Accepted: 21308
Total Submissions: 38923
Instruction: LeetCode 406 - Queue Reconstruction by Height - [M]
Developer: lrushx
Process Time: May 01, 2017
*/


/*
Suppose you have a random list of people standing in a queue. Each person is described by a pair of integers (h, k), where h is the height of the person and k is the number of people in front of this person who have a height greater than or equal to h. Write an algorithm to reconstruct the queue.
Note:
The number of people is less than 1,100.

Input:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
Output:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
*/

//给一组数据，元素为(h,k)，h表示该人身高，k表示左边排k个比其高的人，求出重排后的数据
//贪心，先根据元素键值(先first后second)排序，然后从后往前，
//如果某数(h,k)左边比其高的数量不够，却count个，则从右边就近取count个和其交换(以此往左排1位，然后原数放到这count个后)

//大概率没有invalid数据，但是自己改了个，导致每次run都会出错误，原来是造的数据使得count太大数组访问越界。。。真是坑了自己


    //template <typename T>
    struct cmp{
        bool operator()(const std::pair<int,int>& x, const std::pair<int,int>& y){
        //bool operator()(const T &x, const T &y){
            if (x.first == y.first)
                return x.second < y.second;
            return x.first < y.first;
        }
    };
    
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        int len = people.size(),i,count,j;
        if (len < 2) return people;
        cmp c;
        pair<int, int> tmp;
        sort(people.begin(),people.end(),c);
        for (i = len-1;i >= 0;i--)
            if (people[i].second > 0){
                j = i-1;
                while (j >= 0 && people[j].first == people[i].first) j--;
                if (i-j-1 == people[i].second) continue;
                count = people[i].second+1+j-i; //move count elements after i to before i(i+1..i+count to i..i+count-1)
                if (i + count >= len) count = len - 1 - i;
                tmp = people[i];
                for (j = 0;j < count;j++) people[i+j] = people[i+j+1];
                people[i+count] = tmp;
            }
        return people;
    }