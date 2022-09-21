/*
 * @lc app=leetcode.cn id=827 lang=cpp
 *
 * [827] 最大人工岛
 */
#include<vector>
#include<map>
using namespace std;
// @lc code=start

class UnionFind{
public:
    vector<int> parents;
    int m, n;
    bool full = true;
    UnionFind(vector<vector<int>>& grid){
        this->m = grid.size();
        this->n = grid[0].size();
        for(int i = 0; i < this->m; i++){
            for(int j = 0; j < this->n ; j++){
                if(grid[i][j] == 1){
                    this->parents.push_back(i * this->n + j);
                }else{
                    this->parents.push_back(-1);
                    this->full = false;
                }
            }
        }
        for(int i = 0; i < this->m; i++){
            for(int j = 0; j < this->n; j++){
                if(grid[i][j]){
                    if(this->is_valid(i-1, j) && grid[i-1][j] == 1) this->Union(i, j, i-1, j);
                    if(this->is_valid(i+1, j) && grid[i+1][j] == 1) this->Union(i, j, i+1, j);
                    if(this->is_valid(i, j-1) && grid[i][j-1] == 1) this->Union(i, j, i, j-1);
                    if(this->is_valid(i, j+1) && grid[i][j+1] == 1) this->Union(i, j, i, j+1);
                }
            }
        }
        this->align();
    }

    bool is_valid(int x, int y) const{
        if(x < 0 || y < 0) return false;
        if(x >= this->m || y >= this->n) return false;
        return true;
    }

    void find(int x, int y, int& outX, int& outY){
        int coordinate = this->n * x + y;
        if(!this->is_valid(x, y) || this->parents[coordinate] == -1){
            outX = -1;
            outY = -1;
            return;
        }
        while(this->parents[coordinate] != coordinate) coordinate = this->parents[coordinate];
        outX = coordinate / this->n;
        outY = coordinate % this->n;
        return;
    }

    int find_linear(int x, int y) const {
        int coordinate = this->n * x + y;
        if(!this->is_valid(x, y) || this->parents[coordinate] == -1){
            return -1;
        }
        while(this->parents[coordinate] != coordinate) coordinate = this->parents[coordinate];
        return coordinate;
    }

    void Union(int x, int y, int a, int b){
        if(!this->is_valid(x, y)) return;
        if(!this->is_valid(a, b)) return;
        int x0, y0, a0, b0;
        this->find(x, y, x0, y0);
        this->find(a, b, a0, b0);
        this->parents[x0 * this->n + y0] = a0 * this->n + b0;
        return;
    }

    void align(){
        for(int i = 0; i < this->m * this->n; i++){
            if(this->parents[i] == -1) continue;
            int coordinate = i;
            while(this->parents[coordinate] != coordinate) coordinate = this->parents[coordinate];
            this->parents[i] = coordinate;
        }
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
    int largestIsland(vector<vector<int>>& grid) {
        map<int, int> tag;
        int ret = 1;
        UnionFind unionfind = UnionFind(grid);
        if(unionfind.full){
            return unionfind.m * unionfind.n;
        }
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid.size(); j++){
                if(grid[i][j]){
                    if(tag.find(unionfind.find_linear(i, j)) == tag.end()){
                        tag[unionfind.find_linear(i, j)] = 1;
                    }else{
                        tag[unionfind.find_linear(i, j)]++;
                    }
                }
            }
        }
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid.size(); j++){
                if(!grid[i][j]){
                    map<int, int> tmp;
                    this->crack(i-1, j, unionfind, tag, tmp);
                    this->crack(i, j-1, unionfind, tag, tmp);
                    this->crack(i+1, j, unionfind, tag, tmp);
                    this->crack(i, j+1, unionfind, tag, tmp);
                    int tmp_ret = 0;
                    for(auto item: tmp){
                        tmp_ret += item.second;
                    }
                    if(tmp_ret + 1 > ret){
                        ret = tmp_ret + 1;
                    }
                }
            }
        }
        return ret;
    }

    void crack(int i, int j, const UnionFind &unionfind, const map<int, int> &tag, map<int, int> &tmp){
        int root = unionfind.find_linear(i, j);
        if(root != -1){
            tmp[root] = tag.find(root)->second;
        }
    }
};
// @lc code=end

