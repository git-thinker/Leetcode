#
# @lc app=leetcode.cn id=401 lang=python3
#
# [401] 二进制手表
#

# @lc code=start
class Solution:
    def readBinaryWatch(self, num: int) -> List[str]:
        def vertify(bool_list):
            if len(bool_list) >= 2:
                if bool_list[0] and bool_list[1]:
                    return False
            if len(bool_list) >= 8:
                if bool_list[4] and bool_list[5] and bool_list[6] and bool_list[7]:
                    return False
            return True

        def regulate(bool_list):
            hour = 0
            minute = 0
            for i, item in enumerate(bool_list):
                if i < 4:
                    hour += item * 2 ** (3 - i)
                else:
                    minute += item * 2 ** (5 - (i - 4))
            return str(hour) + ':{:>02}'.format(str(minute))

        bool_bit = []
        rst = []
        def recursive():
            if not vertify(bool_bit):
                return None
            if len(bool_bit) == 10:
                if sum(bool_bit) == num:
                    rst.append(regulate(bool_bit))
                return None
            else:
                bool_bit.append(0)
                recursive()
                bool_bit.pop()
                bool_bit.append(1)
                recursive()
                bool_bit.pop()
        recursive()
        return rst



        
# @lc code=end

