/*
 * @lc app=leetcode.cn id=447 lang=cpp
 *
 * [447] 回旋镖的数量
 */
#include<vector>
#include<map>
#include<cmath>
using namespace std;
// @lc code=start
class Solution {
public:
    int calc(vector<int>& pa, vector<int>& pb){
        return pow(pa[0] - pb[0], 2) + pow(pa[1] - pb[1], 2);
    }
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int ret = 0;
        map<int, int> Mymap;
        for(auto &itemA : points){
            Mymap.clear();
            for(auto &itemB : points){
                if(&itemA == &itemB) continue;
                Mymap[this->calc(itemA, itemB)]++;
            }
            for(auto &item : Mymap){
                ret += item.second * (item.second - 1);
            }
        }
        return ret;
    }
};
// @lc code=end

