//399_Evaluate_Division.h
//0ms	100.00%

/*
Total Accepted: 14588
Total Submissions: 36012
Instruction: LeetCode 399 - Evaluate Division - [M]
Developer: lrushx
Process Time: May 27, 2017
*/

/*
Equations are given in the format A / B = k, where A and B are variables represented as strings, and k is a real number (floating point number). Given some queries, return the answers. If the answer does not exist, return -1.0.
Example:
Given a / b = 2.0, b / c = 3.0. 
queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? . 
return [6.0, 0.5, -1.0, 1.0, -1.0 ].
The input is: vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries , where equations.size() == values.size(), and the values are positive. This represents the equations. Return vector<double>.
According to the example above:
equations = [ ["a", "b"], ["b", "c"] ],
values = [2.0, 3.0],
queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"] ]. 
The input is always valid. You may assume that evaluating the queries will result in no division by zero and there is no contradiction.
*/

//给若干个除法表达式和浮点结果，求给定的query除法表达式的值，若不存在关系则输出-1
//需要3个数据结构：map v映射字符串(分子分母名)到value、map g映射字符串到group，map m<int,vec<string>>储存某组下所有字符串。
//有除法关系的都归到一组，以其中一个为1，另外元素根据除法关系设定浮点值。
//遍历分子分母对，若两个元素都归类过但是不同组，则把分子归到分母组跟新value，并把原来和分子一个组的所有元素都归到分母组同时更新value；
//若其中一个元素未归类，则轨道已归类元素的组中，根据除法式赋值；
//若都未归类，则分配一个组号，各自赋值，把这2个元素驾到该组的列表中。
//题目提示是graph，我用的枚举+hash，用到3个map实在是有点复杂，还花了很多时间。

    static bool mysort(pair<string, string>& a, pair<string, string>& b){ return a.second < b.second;   }
    
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        int len1 = equations.size(), len2 = queries.size(),i,j,group=0,g1;
        double bias;
        vector<double> res(len2,-1.0);
        if (len2*len1 == 0) return res;
        unordered_map<string,double> v;
        unordered_map<string,int> g;
        unordered_map<int,vector<string> > m;
        vector<string> vs;
        bool f1,f2;
        
        for (i = 0;i < len1;i++){
            f1 = v.find(equations[i].first)==v.end()? false:true;
            f2 = v.find(equations[i].second)==v.end()? false:true;
            if (f1 && f2) {
                if (g[equations[i].first] == g[equations[i].second]) continue;
                g1 = g[equations[i].first];
                bias = v[equations[i].second] * values[i] / v[equations[i].first];
                for (j=0;j<m[g1].size();j++){
                    v[m[g1][j]] *= bias;
                    g[m[g1][j]] = g[equations[i].second];
                    m[g[equations[i].second]].push_back(m[g1][j]);
                } 
                //m.erase(g1);
            }else if (f1 || f2){
                if (f1) {
                    v[equations[i].second] = v[equations[i].first] / values[i];
                    g[equations[i].second] = g[equations[i].first];
                    m[g[equations[i].first]].push_back(equations[i].second);
                }
                else {
                    v[equations[i].first] = v[equations[i].second] * values[i];
                    g[equations[i].first] = g[equations[i].second];
                    m[g[equations[i].second]].push_back(equations[i].first);
                }
            }else{
                group++;
                v[equations[i].second] = 1;
                v[equations[i].first] = values[i];
                g[equations[i].second] = g[equations[i].first] = group;
                m[group] = vs;
                m[group].push_back(equations[i].first);
                m[group].push_back(equations[i].second);
            }
            unordered_map<string,int>::iterator it;
            //for (it=g.begin();it!=g.end();++it) cout<<it->first<<":"<<v[it->first]<<":"<<it->second<<","; cout<<endl;
        }
        //cout<<endl;
        for (i = 0;i < len2;i++)
            if (v.find(queries[i].first)!=v.end() && v.find(queries[i].second)!=v.end()){
                if (g[queries[i].first] == g[queries[i].second]) 
                    res[i] = v[queries[i].first] / v[queries[i].second];
        }
        return res;
    }
