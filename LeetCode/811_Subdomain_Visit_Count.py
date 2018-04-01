## 811_Subdomain_Visit_Count.py
## 64ms   %

'''
Total Accepted: 1.6K
Total Submissions: 2.3K
Instruction: LeetCode 811 -  Subdomain Visit Count [E]
Developer: lrushx
Process Time: Mar 31, 2018
'''

'''
A website domain like "discuss.leetcode.com" consists of various subdomains. At the top level, we have "com", at the next level, we have "leetcode.com", and at the lowest level, "discuss.leetcode.com". When we visit a domain like "discuss.leetcode.com", we will also visit the parent domains "leetcode.com" and "com" implicitly.

Now, call a "count-paired domain" to be a count (representing the number of visits this domain received), followed by a space, followed by the address. An example of a count-paired domain might be "9001 discuss.leetcode.com".

We are given a list cpdomains of count-paired domains. We would like a list of count-paired domains, (in the same format as the input, and in any order), that explicitly counts the number of visits to each subdomain.
'''

from collections import defaultdict

class Solution:
    def subdomainVisits(self, cpdomains):
        """
        :type cpdomains: List[str]
        :rtype: List[str]
        """
        dic = defaultdict(int)
        for s in cpdomains:
            n, dom = s.split(' ')
            n, list_dom = int(n), dom.split('.')
            dic[dom] += n
            dic[list_dom[-1]] += n
            if len(list_dom) == 3:
                dic['.'.join(list_dom[1:])] += n
        res = []
        for dom in dic:
            res.append(str(dic[dom])+' '+dom)
        return res
            
