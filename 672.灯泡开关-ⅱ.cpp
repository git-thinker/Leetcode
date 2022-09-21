/*
 * @lc app=leetcode.cn id=672 lang=cpp
 *
 * [672] 灯泡开关 Ⅱ
 */
#include<set>
#include<vector>
#include<cmath>
using namespace std;



// @lc code=start
class Solution {
public:
    const unsigned int operator_0 = 0b111111;
    const unsigned int operator_1 = 0b101010;
    const unsigned int operator_2 = 0b010101;
    const unsigned int operator_3 = 0b001001;
    int flipLights(int n, int presses) {
        if(presses == 0) return 1;
        const unsigned int N = 6;
        // for 2 * 3 = 6
        // operation 0: 0-5
        // operation 1: 1 3 5
        // operation 2: 0 2 4
        // operation 3: 0 3

        set<int> ret_set = {};
        if(presses > 4){
            if(presses % 2 == 0){
                presses = 4;
            }else{
                presses = 3;
            }
        }
        vector<unsigned int> status_vec = {0};
        vector<unsigned int> cache;
        for(int i = 0; i < presses; i++){
            if(i){
                status_vec = cache;
                cache.clear();
            }
            for(auto item: status_vec){
                vector<unsigned int> returned_vec = recursive(item);
                cache.insert(cache.end(), returned_vec.begin(), returned_vec.end());
            }
            if(i == presses - 1){
                ret_set.insert(cache.begin(), cache.end());
            }
        }
        if(n < N){
            set<unsigned int> cache;
            for(auto item: ret_set){
                cache.insert(item & (unsigned int)(pow(2.0, n) - 1));
            }
            return cache.size();
        }
        return ret_set.size();
    }
    vector<unsigned int> recursive(unsigned int status){
        vector<unsigned int> ret = {
            status ^ operator_0, 
            status ^ operator_1, 
            status ^ operator_2, 
            status ^ operator_3
        };
        return ret;
    }
};
// @lc code=end

