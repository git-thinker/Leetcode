/*
 * @lc app=leetcode.cn id=454 lang=cpp
 *
 * [454] 四数相加 II
 */

#include<vector>
#include<map>
using namespace std;
// @lc code=start
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        map<int, int> comb_ab;
        map<int, int> comb_cd;
        int tmp;
        int ret = 0;
        for(int a: nums1){
            for(int b: nums2){
                tmp = a + b;
                if(comb_ab.find(tmp) == comb_ab.end()){
                    comb_ab[tmp] = 1;
                }else{
                    comb_ab[tmp]++;
                }
            }
        }
        for(int c: nums3){
            for(int d: nums4){
                tmp = c + d;
                if(comb_cd.find(tmp) == comb_cd.end()){
                    comb_cd[tmp] = 1;
                }else{
                    comb_cd[tmp]++;
                }
            }
        }
        for(auto item: comb_ab){
            if(comb_cd.find(-item.first) != comb_cd.end()){
                ret += comb_ab[item.first] * comb_cd[-item.first];
            }
        }
        return ret;
    }
};
// @lc code=end

