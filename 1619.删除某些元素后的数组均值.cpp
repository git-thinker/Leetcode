/*
 * @lc app=leetcode.cn id=1619 lang=cpp
 *
 * [1619] 删除某些元素后的数组均值
 */
#include<vector>
#include<queue>
using namespace std;
// @lc code=start
class Solution {
public:
    // double trimMean(vector<int>& arr) {
    //     // heap solution
    //     double ret = 0;
    //     int off = (arr.size() * 0.05);
    //     int on = arr.size() - 2 * off;
    //     priority_queue<int, vector<int>, greater<int>> min;
    //     priority_queue<int, vector<int>, less<int>> max;
    //     for(auto i: arr){
    //         if(min.size() == off){
    //             min.push(i);
    //             min.pop();
    //         }else{
    //             min.push(i);
    //         }

    //         if(max.size() == off){
    //             max.push(i);
    //             max.pop();
    //         }else{
    //             max.push(i);
    //         }

    //         ret += ((double)i) / on;
    //     }

    //     while(min.size() != 0){
    //         ret -= ((double)min.top()) / on;
    //         min.pop();
    //     }
    //     while(max.size() != 0){
    //         ret -= ((double)max.top()) / on;
    //         max.pop();
    //     }
    //     return ret;
    // }

    double trimMean(vector<int>& arr){
        // sort
        double ret = 0;
        int off = (arr.size() * 0.05);
        int on = arr.size() - 2 * off;
        int i, j, tmp;
        for(i = 0; i < off; i++){
            for(j = 0; j < arr.size()-i-1; j++){
                if(arr[j] < arr[j+1]){
                    tmp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = tmp;
                }
            }
        }
        for(i = 0; i < off; i++){
            for(j = arr.size()-1; j > i; j--){
                if(arr[j-1] < arr[j]){
                    tmp = arr[j];
                    arr[j] = arr[j-1];
                    arr[j-1] = tmp;
                }
            }
        }
        for(i = off; i < arr.size() - off; i++){
            ret += (double)arr[i] / on;
        }
        return ret;
    }
};
// @lc code=end

