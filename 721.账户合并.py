#
# @lc app=leetcode.cn id=721 lang=python3
#
# [721] 账户合并
#

# @lc code=start
class Solution:
    def accountsMerge(self, accounts: List[List[str]]) -> List[List[str]]:
        index = 0
        email2index = {}
        email2name = {}
        for line in accounts:
            for i, item in enumerate(line):
                if i:
                    email2name[item] = line[0]
                    if item not in email2index:
                        email2index[item] = index
                        index += 1
        parents = [i for i in range(len(email2index))]
        index2email = {j:i for i,j in email2index.items()}

        def union(i, j):
            parents[find(i)] = find(j)

        def find(i):
            while parents[i] != i:
                i = parents[i]
            return i

        for line in accounts:
            for i, item in enumerate(line):
                if i > 1:
                    union(email2index[line[1]], email2index[item])
        
        rst = []
        tmp_rst = collections.defaultdict(list)
        for i, j in enumerate(parents):
            tmp_rst[find(i)].append(i)
        for key, value in tmp_rst.items():
            tmp = []
            for item in value:
                tmp.append(index2email[item])
            tmp.sort()
            tmp.insert(0, email2name[index2email[key]])
            rst.append(tmp)
        return rst        
# @lc code=end

