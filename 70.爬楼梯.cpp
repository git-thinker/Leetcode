/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
#include<map>

using namespace std;
class Solution {
public:
    int climbStairs_(int n) {
        if(n == 1) return 1;
        if(n == 2) return 2;
        int a, b, m, swap;
        a = 1;
        b = 2;
        m = 2;
        while(n != m){
            swap = a + b;
            a = b;
            b = swap;
            m++;
        }
        return b;
    }

    map <int, int> myMap;
    int climbStairs(int n){
        myMap[1] = 1;
        myMap[2] = 2;
        return this->recursive(n);
    }

    int recursive(int n){
        auto cursor = this->myMap.find(n);
        if(cursor != myMap.end()){
            return cursor->second;
        }else{
            int ans = this->recursive(n - 1) + this->recursive(n - 2);
            myMap[n] = ans;
            return ans;
        }
    }
};
// @lc code=end

