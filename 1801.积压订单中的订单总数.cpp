/*
 * @lc app=leetcode.cn id=1801 lang=cpp
 *
 * [1801] 积压订单中的订单总数
 */
#include<vector>
#include<queue>
using namespace std;
// @lc code=start
class CompDescend{
    public:
    bool operator()(vector<int>& a, vector<int>& b){
        return a[0] < b[0];
    }
};

class CompAscend{
    public:
    bool operator()(vector<int>& a, vector<int>& b){
        return a[0] > b[0];
    }
};

class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        const long N = 1e9+7;
        priority_queue<vector<int>, vector<vector<int>>, CompDescend> buy;
        priority_queue<vector<int>, vector<vector<int>>, CompAscend> sell;
        for(int i=0; i<orders.size(); i++){
            switch(orders[i][2]){
                case 0:
                    // buy
                    while(!sell.empty() && orders[i][1] > 0 && sell.top()[0] <= orders[i][0]){
                        if(sell.top()[1] <= orders[i][1]){
                            orders[i][1] -= sell.top()[1];
                            sell.pop();
                        }else{
                            vector<int> item = sell.top();
                            sell.pop();
                            item[1] -= orders[i][1];
                            orders[i][1] = 0;
                            sell.push(item);
                        }
                    }
                    if(orders[i][1] > 0){
                        buy.push(orders[i]);
                    }
                    break;
                case 1:
                    // sell
                    while(!buy.empty() && orders[i][1] > 0 && buy.top()[0] >= orders[i][0]){
                        if(buy.top()[1] <= orders[i][1]){
                            orders[i][1] -= buy.top()[1];
                            buy.pop();
                        }else{
                            vector<int> item = buy.top();
                            buy.pop();
                            item[1] -= orders[i][1];
                            orders[i][1] = 0;
                            buy.push(item);
                        }
                    }
                    if(orders[i][1] > 0){
                        sell.push(orders[i]);
                    }
                    break;
            }
        }
        long int ret = 0;
        while(!sell.empty()){
            ret += sell.top()[1];
            sell.pop();
        }
        while(!buy.empty()){
            ret += buy.top()[1];
            buy.pop();
        }
        ret %= N;
        return ret;
    }
};
// @lc code=end

