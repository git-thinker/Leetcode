#
# @lc app=leetcode.cn id=71 lang=python3
#
# [71] 简化路径
#

# @lc code=start
class Solution:
    def simplifyPath(self, path: str) -> str:
        rst = []
        for item in path.split('/'):
            if item  not in ('', '.', '..'):
                rst.append(item)
            elif item == '..' and rst:
                    rst.pop()
                
        return '/' + '/'.join(rst)


# @lc code=end

