/*
 * @lc app=leetcode.cn id=743 lang=cpp
 *
 * [743] 网络延迟时间
 */

// @lc code=start
#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // return dfs_init(times, n, k);
        return dijkstra(times, n, k);

    }

    int dijkstra(vector<vector<int>>& times, int n, int k){
        k -= 1;
        vector<vector<int>> edgeMatrix = vector<vector<int>>(n, vector<int>(n, -1));
        vector<int> ansVec = vector<int>(n, -1);
        queue<int> myQueue;
        ansVec[k] = 0;
        int ans = 0;
        int c;
        for(auto item: times){
            edgeMatrix[--item[0]][--item[1]] = item[2];
        }

        myQueue.push(k);
        while(!myQueue.empty()){
            c = myQueue.front();
            myQueue.pop();
            for(int i = 0; i < n; i++){
                if(edgeMatrix[c][i] != -1){
                    if(ansVec[i] == -1) {
                        ansVec[i] = ansVec[c] + edgeMatrix[c][i];
                        myQueue.push(i);
                    }else if(ansVec[i] != -1 && ansVec[i] > ansVec[c] + edgeMatrix[c][i]){
                        ansVec[i] = ansVec[c] + edgeMatrix[c][i];
                        myQueue.push(i);
                    }
                }
            }
        }
        
        for(int time:ansVec){
            if(time == -1) return -1;
            ans = max(ans, time);
        }
        return ans;
        
    }

    int dfs_init(vector<vector<int>>& times, int n, int k){
        k -= 1;
        vector<vector<int>> edgeMatrix = vector<vector<int>>(n, vector<int>(n, -1));
        vector<int> ansVec = vector<int>(n, -1);
        ansVec[k] = 0;
        int ans = 0;
        for(auto item: times){
            edgeMatrix[--item[0]][--item[1]] = item[2];
        }

        dfs(edgeMatrix, ansVec, k, 0, n);
        
        for(int time:ansVec){
            if(time == -1) return -1;
            ans = max(ans, time);
        }
        return ans;
    }

    void dfs(vector<vector<int>>& edgeMatrix, vector<int>& ansVec, int c, int length, int n){
        for(int i = 0; i < n; i++){
            if(edgeMatrix[c][i] != -1){
                if(ansVec[i] == -1 || ansVec[i] > length + edgeMatrix[c][i]) {
                    ansVec[i] = edgeMatrix[c][i] + length;
                    dfs(edgeMatrix, ansVec, i, length + edgeMatrix[c][i], n);
                }
            }
        }
    }
};
// @lc code=end

