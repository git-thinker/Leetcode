/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] 两个数组的交集 II
 */

// @lc code=start
#include<vector>
#include<hash_map>
using namespace std;
using namespace __gnu_cxx;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        hash_map<int, int> counter1, counter2;
        vector<int> ansVec;
        for(int i: nums1){
            if(counter1.count(i)) counter1[i] += 1;
            else counter1[i] = 1;
        }

        for(int i: nums2){
            if(counter2.count(i)) counter2[i] += 1;
            else counter2[i] = 1;
        }

        for(pair<int, int> item: counter1){
            if(counter2.count(item.first)){
                ansVec.insert(ansVec.end(), min(item.second, counter2[item.first]), item.first);
            }
        }

        return ansVec;
    }
};
// @lc code=end

