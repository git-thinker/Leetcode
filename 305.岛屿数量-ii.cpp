/*
 * @lc app=leetcode.cn id=305 lang=cpp
 *
 * [305] 岛屿数量 II
 */

// @lc code=start
#include<vector>
using namespace std;

class UnionFind{
public:
    vector<int> parents;
    int m, n, count;
    UnionFind(int m, int n){
        this->m = m;
        this->n = n;
        this->count = 0;
        this->parents = vector<int>(m * n, -1);
    }
    
    void Find(int index, int &returnIndex, int &rank){
        rank = 0;
        while(index != this->parents[index]){
            index = this->parents[index];
            ++rank;
        }
        returnIndex = index;
    }

    void Union(int index0, int index1){
        int parentIndex0, parentIndex1;
        int rank0, rank1;
        this->Find(index0, parentIndex0, rank0);
        this->Find(index1, parentIndex1, rank1);
        if(parentIndex0 == parentIndex1) return;
        if(rank0 < rank1){
            this->parents[parentIndex0] = parentIndex1;
        }else {
            this->parents[parentIndex1] = parentIndex0;
        }
        this->count--;
    }

    void Unite(int x0, int y0, int x1, int y1){
        this->Union(x0 * this->n + y0, x1 * this->n + y1);
    }

    int Count(){
        int count = 0;
        for(int i = 0; i <  this->m * this->n; i++){
            if(i ==  this->parents[i]) count++;
        }
        return count;
    }

    void Set(int x, int y){
        this->parents[x * this->n + y] = x * this->n + y;
        this->count++;
    }
};


class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        vector<int> ans;
        vector<vector<int>> map = vector<vector<int>>(m, vector<int>(n, 0));
        UnionFind myUnionFind = UnionFind(m, n);
        for(auto tuple: positions){
            if(map[tuple[0]][tuple[1]]){
                ans.push_back(myUnionFind.count);
                continue;
            }
            map[tuple[0]][tuple[1]] = 1;
            myUnionFind.Set(tuple[0], tuple[1]);
            if(tuple[0] != 0 && map[tuple[0]-1][tuple[1]]) myUnionFind.Unite(tuple[0], tuple[1], tuple[0]-1, tuple[1]);
            if(tuple[1] != 0 && map[tuple[0]][tuple[1]-1]) myUnionFind.Unite(tuple[0], tuple[1], tuple[0], tuple[1]-1);
            if(tuple[0]+1 != m && map[tuple[0]+1][tuple[1]]) myUnionFind.Unite(tuple[0], tuple[1], tuple[0]+1, tuple[1]);
            if(tuple[1]+1 != n && map[tuple[0]][tuple[1]+1]) myUnionFind.Unite(tuple[0], tuple[1], tuple[0], tuple[1]+1);
            ans.push_back(myUnionFind.count);
        }
        return ans;
    }
};
// @lc code=end

