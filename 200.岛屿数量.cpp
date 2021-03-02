/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
class UnionFind{
public:
    vector<int> parents;
    int m, n;
    UnionFind(vector<vector<char>>& grid){
        this->m = grid.size();
        this->n = grid[0].size();
        for(int i = 0; i < this->m; i++){
            for(int j = 0; j < this->n ; j++){
                if(grid[i][j] == '1'){
                    this->parents.push_back(i * this->n + j);
                }else{
                    this->parents.push_back(-1);
                }
            }
        }
    }

    void find(int x, int y, int& outX, int& outY){
        int coordinate = this->n * x + y;
        if(this->parents[coordinate] == -1){
            outX = -1;
            outY = -1;
            return;
        }
        while(this->parents[coordinate] != coordinate) coordinate = this->parents[coordinate];
        outX = coordinate / this->n;
        outY = coordinate % this->n;
        return;
    }

    void Union(int x, int y, int a, int b, vector<vector<char>> &grid){
        int x0, y0, a0, b0;
        this->find(x, y, x0, y0);
        this->find(a, b, a0, b0);
        this->parents[x0 * this->n + y0] = a0 * this->n + b0;
        return;
    }

    int count(){
        int count = 0;
        for(int i = 0; i < this->m * this->n; i++){
            if(i == this->parents[i]){
                count++;
            }
        }
        return count;
    }
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        UnionFind myUnionFind = UnionFind(grid);
        for(int i = 0; i < myUnionFind.m; ++i){
            for(int j = 0; j < myUnionFind.n; ++j){
                if(grid[i][j] == '1'){
                    grid[i][j] = '2';
                    if(0 <= i-1 && grid[i-1][j] == '1') myUnionFind.Union(i, j, i-1, j, grid);
                    if(i+1 < myUnionFind.m && grid[i+1][j] == '1') myUnionFind.Union(i, j, i+1, j, grid);
                    if(0 <= j-1 && grid[i][j-1] == '1') myUnionFind.Union(i, j, i, j-1, grid);
                    if(j+1 < myUnionFind.n && grid[i][j+1] == '1') myUnionFind.Union(i, j, i, j+1, grid);
                }
            }
        }
        return myUnionFind.count();
    }
};
// @lc code=end

