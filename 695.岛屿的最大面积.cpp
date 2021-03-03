/*
 * @lc app=leetcode.cn id=695 lang=cpp
 *
 * [695] 岛屿的最大面积
 */

// @lc code=start
#include<vector>
using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        int nowArea = 0;
        for(int i = 0; i < grid.size(); ++i){
            for(int j = 0; j < grid[0].size(); ++j){
                if(grid[i][j] == 1){
                    this->crack(grid, i, j, nowArea);
                    if(nowArea > maxArea) maxArea = nowArea;
                    nowArea = 0;
                }
            }
        }
        return maxArea;
    }    

    void crack(vector<vector<int>>& grid, int x, int y, int& area){
        if(x < 0 || y < 0) return;
        if(x >= grid.size() || y >= grid[0].size()) return;
        if(grid[x][y] != 1) return;
        grid[x][y] = 2;
        area++;
        this->crack(grid, x+1, y, area);
        this->crack(grid, x, y+1, area);
        this->crack(grid, x-1, y, area);
        this->crack(grid, x, y-1, area);
    }
};
// @lc code=end

