/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

#include<vector>
using namespace std;
// @lc code=start
#define INTMAX 2147483647
class Solution {
public:
    // int ret = INTMAX;

    int add(int a, int b){
        if(a == INTMAX || b == INTMAX){
            return INTMAX;
        }else{
            return a + b;
        }
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp = vector<vector<int>>(coins.size()+1, vector<int>(amount+1, INTMAX));
        dp[0][0] = 0;
        for(int i = 1; i < coins.size()+1; i++){
            for(int j = 0; j < amount+1; j++){
                if(coins[i-1] <= j){
                    dp[i][j] = min(dp[i-1][j], add(dp[i][j-coins[i-1]], 1));
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp.back().back() == INTMAX ? -1 : dp.back().back();
    }

    // here is dfs version (cannot pass case 39)

    // int coinChange(vector<int>& coins, int amount) {
    //     if(amount == 0) return 0;
    //     dfs(coins, amount, 0, 0, 0);
    //     if(ret == 2147483647) return -1;
    //     else return ret;
    // }

    // void dfs(vector<int>& coins, int amount, int cursor, int now_coins, int now_amout){
    //     if(now_amout == amount){
    //         if(now_coins < ret) ret = now_coins;
    //         return ;
    //     }
    //     if(now_amout > amount || now_coins > ret || coins.size() == cursor){
    //         return ;
    //     }
    //     int max_amount = (amount - now_amout) / coins[cursor];
    //     for(int i = max_amount; i >= 0; i--){
    //         dfs(coins, amount, cursor + 1, now_coins + i, now_amout + i * coins[cursor]);
    //     }
    // }
};
// @lc code=end

