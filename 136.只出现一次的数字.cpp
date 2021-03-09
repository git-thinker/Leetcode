/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 */

// @lc code=start
#include<vector>
#include<hash_map>
using namespace std;
using namespace __gnu_cxx;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        hash_map<int, int> map;
        for(int i: nums){
            if(map.count(i)) map[i]++;
            else map[i] = 1;
        }

        for(int i:nums){
            if(map[i] == 1) return i;
        }
        return -1;
    }
};
// @lc code=end

