//609_Find_Duplicate_File_in_System.h
//112ms
//LeetCode Contest 35

/*
Total Accepted: 877
Total Submissions: 1672
Instruction: LeetCode 609 - Find Duplicate File in System - [M]
Developer: lrushx
Process Time: June 03, 2017
*/

/*
Given a list of directory info including directory path, and all the files with contents in this directory, you need to find out all the groups of duplicate files in the file system in terms of their paths.
A group of duplicate files consists of at least two files that have exactly the same content.
A single directory info string in the input list has the following format:
"root/d1/d2/.../dm f1.txt(f1_content) f2.txt(f2_content) ... fn.txt(fn_content)"
It means there are n files (f1.txt, f2.txt ... fn.txt with content f1_content, f2_content ... fn_content, respectively) in directory root/d1/d2/.../dm. Note that n >= 1 and m >= 0. If m = 0, it means the directory is just the root directory.
The output is a list of group of duplicate file paths. For each group, it contains all the file paths of the files that have the same content. A file path is a string that has the following format:
"directory_path/file_name.txt"

Example 1:
Input:
["root/a 1.txt(abcd) 2.txt(efgh)", "root/c 3.txt(abcd)", "root/c/d 4.txt(efgh)", "root 4.txt(efgh)"]
Output:  
[["root/a/2.txt","root/c/d/4.txt","root/4.txt"],["root/a/1.txt","root/c/3.txt"]]
Note:
No order is required for the final output.
You may assume the directory name, file name and file content only has letters and digits, and the length of file content is in the range of [1,50].
The number of files given is in the range of [1,20000].
You may assume no files or directories share the same name in a same directory.
You may assume each given directory info represents a unique directory. Directory path and file infos are separated by a single blank space.
*/

//给一串字符串，每个字符串里面多个空格，第一部分为路径，之后多个文件名(文件内容串)，要找出各个所有文件内容串相等的文件，把路径连同文件名输出到同一个vector中，然后返回一个数组，包含所有这样的vector
//用map构造hash table，key为内容串，内容为一个vector，push进所有包含这个内容串的路径+文件名，最后遍历这个map，把所有size>1的vector都push到答案中

    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string,vector<string>> m;
        unordered_map<string,vector<string>>::iterator it;
        vector<string> voidv;
        int len = paths.size(),i;
        vector<vector<string>> res;
        string root,file,content;
        size_t found,found1,s;
        for (i = 0;i<len;i++){
            if (paths[i].size() == 0) continue;
            paths[i] += " ";
            found = paths[i].find(" ");
            root = paths[i].substr(0,found);
            s = found+1;
            found = paths[i].find(" ",s);
            while (found != std::string::npos){
                found1 = paths[i].find("(",s);
                file = paths[i].substr(s,found1-s);
                content = paths[i].substr(found1+1,found-found1-2);
                
                if (m.find(content) == m.end()) m[content] = voidv;
                m[content].push_back(root+"/"+file);
                s = found + 1;
                found = paths[i].find(" ",s);
            }
        }
        for (it = m.begin();it!=m.end();++it){
            if (it->second.size()>1) res.push_back(it->second);
        }
        return res;
    }
