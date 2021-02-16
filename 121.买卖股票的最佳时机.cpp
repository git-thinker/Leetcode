/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
    int maxProfit_(vector<int>& prices) {
        int min = 2147483647;
        int max = -2147483648;
        int profit = 0;
        for(auto i: prices){
            if(i < min){
                min = i;
                max = -2147483648;
                // renew when lower price is found
                // drop current high price since it is no longer valid
            }if(i > max){
                max = i;
                if(profit < max - min){
                    profit = max - min;
                }
                // renew profit and high price
            }
        }
        return profit;
    }

    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int minPrice = 2147483647;
        for(auto stockPrice:prices){
            minPrice = min(stockPrice, minPrice);
            profit = max(profit, stockPrice - minPrice);
        }
        return profit;
    }
};
// @lc code=end

