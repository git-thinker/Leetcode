/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */
// @lc code=start
#include<vector>
#include<algorithm>
#include<hash_map>
using namespace std;
using namespace __gnu_cxx;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        __gnu_cxx::hash_map<int, int> myMap;
        int ret=0;
        for(int num: nums){
            myMap[num] = 0;
        }
        for(auto item: myMap){
            if(!item.second){
                recursive(myMap, item.first);    
            }
        }
        for(auto item: myMap){
            if(item.second > ret){
                ret = item.second;
            }
        }
        return ret;
    }

    int recursive(__gnu_cxx::hash_map<int, int>& myMap, int key){
        if(myMap.find(key) == myMap.end()){
            return 0;
        }else{
            if(myMap[key]){
                return myMap[key];
            }else{
                myMap[key] = recursive(myMap, key-1)+1;
                return myMap[key];
            } 
        }
    }

    // int longestConsecutive(vector<int>& nums) {
    //     if(!nums.size()) return 0;
    //     sort(nums.begin(), nums.end());
    //     int ret = 1;
    //     int tmp = 1;
    //     for(int i = 0; i < nums.size() - 1; i++){
    //         if(nums[i+1] - nums[i] == 1){
    //             tmp++;
    //         }else if(nums[i+1] == nums[i]){
    //             ;
    //         }else{
    //             if(tmp > ret){
    //                 ret = tmp;
    //             }
    //             tmp = 1;
    //         }
    //     }
    //     if(tmp > ret){
    //         ret = tmp;
    //         tmp = 1;
    //     }
    //     return ret;
    // }
};
// @lc code=end

